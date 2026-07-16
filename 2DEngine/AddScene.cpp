#include "stdafx.h"

#include "AddScene.h"
#include "EngineObject/EngineObject.h"
#include "Objects/Objects.h"
#include "Structs/Structs.h"
#include "Types/LayerType.h"
#include "Master.h"

void SceneManager::AddScene() {
	SceneSet<SampleScene>();
}

void SampleScene::ObjSet() {

	Vector2<float> winSize = Master::Window().WindowSize().Cast<float>();

	Camera* cam = dynamic_cast<Camera*>(CreateObj<Camera>(0, 0, (winSize.x / 4) * 1, winSize.y / 2, (winSize.x / 2) - 50, winSize.y - 50, 0xff8080));
	// Camera* cam = dynamic_cast<Camera*>(CreateObj<Camera>(0, 0, winSize.x / 2, winSize.y / 2, winSize, winSize, 0xC0C0FF));

	Side<float> camSide = cam->WorldCameraSide();
	Vector2<float> camCenter = cam->WorldPos();

	CreateObj<Text>(
		"SAMPLE SCENE",
		camSide.left, camSide.top,
		32, 64,           // renderSizeX, renderSizeY
		"GoldFont64",
		Utils::Anchor::Type::Q
	);

	const Sprite* searchSprite = Master::Image().SearchSprite("monochrome_transparent");

	// 見つからなかった場合,空のスプライト入れる
	Sprite pikachuSprite = (searchSprite != nullptr) ? *searchSprite : Sprite();

	CreateObj<ImageObj>(
		camCenter.x, camCenter.y, 128, 128,
		pikachuSprite.GetImage(1, 19)
	);
}