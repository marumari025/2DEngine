// WindowManager.cpp
#include "WindowManager.h"
#include "stdafx.h"

void WindowManager::SetupBeforeInit() {
	//ウィンドウサイズとカラービット数の指定
	SetGraphMode(windowSize.x, windowSize.y, colorBit);
	//ウィンドウモード指定
	ChangeWindowMode(windowMode);
	// 黒の透過を無効にする
	SetUseTransColor(FALSE); 
}

void WindowManager::SetupAfterInit() {
	// RGBで背景色を設定
	SetBackgroundColor(color.GetR(), color.GetG(), color.GetB());
	// マウスを表示指定
	SetMouseDispFlag(mouseDisp);
	//裏画面へ描画（ダブルバッファ）
	SetDrawScreen(DX_SCREEN_BACK);
}