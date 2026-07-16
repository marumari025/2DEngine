// WindowManager.h
#pragma once

#include "Manager/Manager.h"
#include "Structs/Color/Color.h"
#include "Structs/Vector/Vector2.h"

class WindowManager {
protected:
	WindowManager();
	// Masterの管理下のみ
	friend class Master;

	// ウィンドウサイズ（解像度）
	Vector2<int> windowSize;

	// 描画設定
	int colorBit;	// カラービット数（色の精度）
	Color color;	// 背景色（RGB）

	// ウィンドウ状態
	int windowMode; // ウィンドウモード(TRUE)かフルスクリーン(FALSE)

	// マウス設定
	int mouseDisp;	// マウス表示フラグ 表示(TRUE) 非表示(DALSE)

	// フレーム管理
	float fixedStep;	// 一定間隔で処理を実行するための時間の指標
	int fps;	// 1秒あたりのフレーム数（FPS）

public:

	Vector2<int>& WindowSize() { return windowSize; }
	Color& Color() { return color; }
	int& FPS() { return fps; }
	float& FixedStep() { return fixedStep; }

	void SetupBeforeInit();
	void SetupAfterInit();
};