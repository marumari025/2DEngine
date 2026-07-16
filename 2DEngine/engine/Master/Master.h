#pragma once
#include "Manager/SceneManager/SceneManager.h"
#include "Manager/TimeManager/TimeManager.h"
#include "Manager/WindowManager/WindowManager.h"
#include "Manager/InputManager/InputManager.h"
#include "Manager/LayerManager/LayerManager.h"
#include "Manager/FontsManager/FontsManager.h"
#include "Manager/ImageManager/ImageManager.h"

#include "Manager/EnableConsole/EnableConsole.h"

class Master {
private:
	// Masterが管理してるクラス
	InputManager input;
	SceneManager scene;
	TimeManager time;
	WindowManager window;
	LayerManager layer;
	FontManager font;
	ImageManager image;

	// Debug時限定
#if _DEBUG
	// 先輩からもらったコンソール
	EnableConsole enableConsole;
#endif

public:
	// シングルトンクラス
	static Master& Instance() {
		static Master instance;
		return instance;
	}

	static InputManager& Input() { return Instance().input; }
	static SceneManager& Scene() { return Instance().scene; }
	static TimeManager& Time() { return Instance().time; }
	static WindowManager& Window() { return Instance().window; }
	static LayerManager& Layer() { return Instance().layer; }
	static FontManager& Font() { return Instance().font; }
	static ImageManager& Image() { return Instance().image; }

	bool InitSystem() {
		window.SetupBeforeInit();

		//DXライブラリの初期化、エラーで終了
		if (DxLib_Init() == -1) return false;

		window.SetupAfterInit();

		return true;
	}

	void InitContents() {

		font.Load();  // DxLib_Init後にロード
		image.InitErrorImage();  // DxLib_Init後にロード
		image.Load();  // DxLib_Init後にロード
		scene.Init();
		layer.InitLayerMatrix();

	}

	void GameLoop();

	// マネージャーたちのアップデート
	void ManagerUpdate();

	bool IsGameEnd();
};
