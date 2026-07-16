#pragma once

#include "stdafx.h"

#include "../Input.h"
#include "../Code.h"
#include "Structs/Structs.h"

class InputMouse
{
private:
	InputMouse() = default;
	// InputManagerの管理下のみ
	friend class InputManager;
	// コンパイル時定数と呼ばれるものらしい
	// これで定数が必要なものにも使える
	static constexpr int MOUSE_BUTTON_NUM = 11;

	// pushButton状態保存用
	int mouseState[MOUSE_BUTTON_NUM] = { 0 };

	Vector2<int> mousePos;

	const int MouseButtonMap[MOUSE_BUTTON_NUM] = {
		MOUSE_INPUT_LEFT,
		MOUSE_INPUT_RIGHT,
		MOUSE_INPUT_MIDDLE,

		MOUSE_INPUT_1,
		MOUSE_INPUT_2,
		MOUSE_INPUT_3,
		MOUSE_INPUT_4,
		MOUSE_INPUT_5,
		MOUSE_INPUT_6,
		MOUSE_INPUT_7,
		MOUSE_INPUT_8
	};

	int CodeNum(const MouseCode _code) {
		return MouseButtonMap[static_cast<int>(_code)];
	}

	// マウス位置の設定
	void SetMousePos();
	// 押したボタンの設定
	void PushButton();

public:
	void Update();

	bool IsDown(const MouseCode _button);
	bool IsHeld(const MouseCode _button);
	bool IsUp(const MouseCode _button);
};