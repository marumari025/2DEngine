#include "InputMouse.h"

void InputMouse::Update() {
	SetMousePos();
	PushButton();

}

void InputMouse::SetMousePos() {
	GetMousePoint(&mousePos.x, &mousePos.y);
}

void InputMouse::PushButton() {
	int input = GetMouseInput();
	for (int i = 0; i < MOUSE_BUTTON_NUM; ++i) {

		//i番のキーコードに対応するキーが押されていたら1 
		if (input & MouseButtonMap[i]) {
			// 押された直後
			if (mouseState[i] <= 0) {
				mouseState[i] = 1;
			}
			// 長押し
			else {
				mouseState[i] = 2;
			}
		}
		// 離した瞬間は-1
		else if (mouseState[i] > 0) {
			mouseState[i] = -1;			//一度 -1 にリセット
		}
		// 離した瞬間でない0
		else {
			mouseState[i] = 0;			//0にリセット
		}
	}

}

bool InputMouse::IsDown(const MouseCode _button)
{
	if (mouseState[CodeNum(_button)] == 1) {
		return true;
	}
	return false;
}

bool InputMouse::IsHeld(const MouseCode _button)
{
	if (mouseState[CodeNum(_button)] > 0) {
		return true;
	}
	return false;
}

bool InputMouse::IsUp(const MouseCode _button)
{
	if (mouseState[CodeNum(_button)] < 0) {
		return true;
	}
	return false;
}