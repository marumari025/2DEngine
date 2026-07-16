#pragma once

#include "stdafx.h"

#include "Manager/Manager.h"
#include "InputKeyBoard/InputKeyBoard.h"
#include "InputMouse/InputMouse.h"

class InputManager {
protected:
	InputManager() = default;
	// Master‚ÌŠÇ—‰º‚Ì‚İ
	friend class Master;

	InputKeyBoard keyBoard;
	InputMouse mouse;

public:
	InputKeyBoard& KeyBoard() { return keyBoard; }
	InputMouse& Mouse() { return mouse; }

	void UpdateInput() {
		keyBoard.Update();
		mouse.Update();
	}

};