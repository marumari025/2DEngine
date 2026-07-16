// SceneManager.h
#pragma once

#include "stdafx.h"

#include "Manager/Manager.h"
#include "BaseObj.h"
#include "Scene/Scene.h"
#include "ObjectFinder/ObjectFinder.h"


class SceneManager
{
	SceneManager() = default;
	// Masterの管理下のみ
	friend class Master;

	// 動かすオブジェクトが入っている
	std::vector<std::unique_ptr<BaseObj>> objects;
	std::vector<std::unique_ptr<BaseObj>> newObjects;

	// シーン用変数
	std::vector<std::unique_ptr<Scene>> scene;

	// シーンを変更するか否か
	bool SceneChangeFlg = false;
	// 次のシーン
	int nextScene = 0;
	// 現在のシーン
	int nowScene = 0;

	// オブジェクトのIDどこまで設定されているか
	// IDは1から (0エラー) 
	unsigned int nowID = 1;

	float fixedUpdateTime = 0;
	// 
	float fpsUpdateTime = 0;

	void AddScene();
	void QuickSort3Way(std::vector<std::unique_ptr<BaseObj>>& base, int left, int right);

	//	オブジェクト削除
	void ClearObject();

	void SetObjects();

	// 名前からシ－ンがあるか探し、あるなら場所を返す 
	int GetSceneNum(std::string _name);

	// SetChangeSceneで変えことになったシーンに変更
	void SceneChange();

	// templateは「.h」にしかかけない
	template<typename T>
	void SceneSet()
	{
		// シーンがまだないなら追加
		for (int i = 0; i < scene.size(); i++) {
			// T は型そのものなので、直接 == 比較はできないので
			// typeidに入れstd::type_infoにする
			// 同じクラスのシーンがないか確認する
			if (typeid(*scene[i]) == typeid(T)) {
				return;
			}
		}

		scene.push_back(std::make_unique<T>());

		// 追加したシーンに名前をセット
		scene.back()->SetName<T>();
		// scene.back()->Init();
	}



public:

	// 呼ばれたときにObjectFinderを生成して返す
	template<typename T = BaseObj>
	ObjectFinder<T> Find() {
		return ObjectFinder<T>(objects);
	}

	// 名前でシーンからオブジェクトを探す
	BaseObj* FindObjectByName(const std::string& _name);

	// どのシーンに変更するか
	void SetChangeScene(std::string _name);

	// 同じシーンの再読み込み
	void ResetScens();

	// IDでオブジェクト取得
	BaseObj* GetComponent(unsigned int _id);

	// ゲーム中のオブジェクト追加
	template<typename T, class... Args> // class... Args どのクラスも全部入る
	BaseObj* SpawnObj(Args&&... args) {

		newObjects.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		newObjects.back()->InitID(nowID++);

		return newObjects.back().get();
	}

	void Init();

	// 
	void UpdateGame();
	// 
	void UpdateFixed();
	// 画面の描画
	void Render();

	// 
	void SetNewObj();
	// 
	void DeleteObj();

};