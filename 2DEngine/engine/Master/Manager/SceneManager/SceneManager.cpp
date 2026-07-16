// SceneManager.cpp
#include "SceneManager.h"
#include "Master.h"
#include "Utils/Render/Render.h"

void SceneManager::Init() {
	AddScene();
	SetObjects();

	// 開始時のシーンをコンソールに描画
	std::cerr << "FirstScene : " << scene[nextScene]->GetName() << std::endl;
}

// すべてのオブジェクト削除
void SceneManager::ClearObject() {
	objects.clear();
	newObjects.clear();
};

BaseObj* SceneManager::FindObjectByName(const std::string& _name) {
	for (auto& obj : objects)
	{
		if (obj->Name() == _name) {
			return obj.get();
		}
	}
	return nullptr; // 見つからなかった場合
}

void SceneManager::SetChangeScene(std::string _name) {
	int num = GetSceneNum(_name);

	// 一応始めに通ったシーンに変える
	if (SceneChangeFlg || num == -1)return;
	
	SceneChangeFlg = true;
	nextScene = num;
}

void SceneManager::ResetScens() {
	// 一応始めに通ったシーンに変える
	if (SceneChangeFlg || nowScene == -1)return;
	
	SceneChangeFlg = true;
}

int SceneManager::GetSceneNum(std::string _name) {
	for (int i = 0; i < scene.size(); i++) {
		// _nameとscene[i]のクラス名が同じか確認
		std::string name = scene[i]->GetName();
		if (name == _name) {
			return i;
		}
	}
	return -1;
}

void SceneManager::SceneChange() {
	// シーンチェンジするか
	if (!SceneChangeFlg) return;

	// インデックス外ではないか確認
	assert(0 <= nextScene && nextScene < scene.size());	// assertを使うように.

	// 画面のクリア 
	ClearDrawScreen();
	// オブジェクトのクリア 
	ClearObject();
	// オブジェクトのセット
	SetObjects();

	std::cerr << "SceneChange : " << scene[nextScene]->GetName() << std::endl;

	SceneChangeFlg = false;
	nowScene = nextScene;
}

void SceneManager::SetObjects() {

	// objectsのアドレス教えて、
	scene[nextScene]->SetObjectsAddress(&newObjects);
	scene[nextScene]->SetNowIDAddress(&nowID);

	// 教えたアドレスにオブジェクトをセット
	scene[nextScene]->ObjSet();

	SetNewObj();
}

// 3-way QuickSort（ダッチナショナルフラッグ法）
void SceneManager::QuickSort3Way(std::vector<std::unique_ptr<BaseObj>>& base, int left, int right)
{
	if (left >= right) return;

	int i = left;
	int j = right;
	int pivot = base[(left + right) / 2]->GetDrawOrder();

	int lt = left;     // pivot より小さい領域の終端
	int gt = right;    // pivot より大きい領域の始端

	while (i <= gt) {
		if (base[i]->GetDrawOrder() < pivot) {
			std::swap(base[i], base[lt]);
			i++;
			lt++;
		}
		else if (base[i]->GetDrawOrder() > pivot) {
			std::swap(base[i], base[gt]);
			gt--;
		}
		else {
			i++;
		}
	}

	QuickSort3Way(base, left, lt - 1);
	QuickSort3Way(base, gt + 1, right);
}

void SceneManager::UpdateGame()
{
	// スタート処理をするか毎回確認
	for (auto& obj : objects) {
		if (!obj->Started())
		{
			obj->Start();
			obj->Started() = true;
		}
	}

	for (auto& obj : objects) {
		obj->Update();
	}
}

void SceneManager::UpdateFixed()
{
	float fixed = Master::Window().FixedStep();

	fixedUpdateTime += Master::Time().DeltaTimeUnscaled();

	if (fixed <= fixedUpdateTime) {

		fixedUpdateTime = std::fmodf(fixedUpdateTime, fixed);
		Master::Time().UpdateFixedTime();

		for (auto& obj : objects) {
			obj->Fixed();
		}
	}
}

void SceneManager::Render() {

	int FPS = Master::Window().FPS();

	fpsUpdateTime += Master::Time().DeltaTimeUnscaled();
	
	// 1フレーム時間以上たっているか
	if ((1.0f / FPS) <= fpsUpdateTime) {
		
		// 時間を燃えた時間に戻す
		fpsUpdateTime = std::fmodf(fpsUpdateTime, 1.0f / FPS);

		ClearDrawScreen();	//画面をクリアする

		// カメラの背景を変更する
		Utils::Render::RenderCamerasBack();

		for (auto& obj : objects) {
			obj->Draw();
		}

		ScreenFlip();			//裏画面の内容を表画面に反映
	}
}

// 初期処理系動かしてからbaseに入れる
void SceneManager::SetNewObj() {

	// newObjectsにオブジェクトが入っているか
	if (!newObjects.empty()) {

		// 追加するオブジェクトのAwake
		for (auto& obj : newObjects) {
			obj->Awake();
		}

		// 実際に追加
		for (auto& obj : newObjects) {
			objects.push_back(std::move(obj));
		}

		// ソート
		QuickSort3Way(objects, 0, static_cast<int>(objects.size() - 1));

		// newObjectsの中身削除
		newObjects.clear();
	}
}

// 死亡フラグがたっているなら消す
void SceneManager::DeleteObj()
{
	objects.erase(
		std::remove_if(objects.begin(), objects.end(), [&](const std::unique_ptr<BaseObj>& b) {
			return b->IsDead();
			}),
		objects.end()
	);
}

BaseObj* SceneManager::GetComponent(unsigned int _id) {
	for (auto& obj : objects) {
		if (_id == obj->GetObjID()) {
			return obj.get();
		}
	}
	return nullptr;
}