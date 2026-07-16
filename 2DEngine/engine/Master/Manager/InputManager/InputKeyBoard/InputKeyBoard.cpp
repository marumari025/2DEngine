#include "InputKeyBoard.h"


void InputKeyBoard::Update()
{
	char tmpKey[256];					//現在のキー入力状態を格納するchar型配列
	GetHitKeyStateAll(tmpKey);			//全てのキーの入力状態を取得

	for (int i = 0; i < 256; i++) {
		//i番のキーコードに対応するキーが押されていたら1 
		if (tmpKey[i] != 0) {
			// 押された直後
			if (keyState[i] <= 0) {
				keyState[i] = 1;
			}
			// 長押し
			else {
				keyState[i] = 2;
			}
		}
		// 離した瞬間は-1
		else if (keyState[i] > 0) {
			keyState[i] = -1;			//一度 -1 にリセット
		}
		// 離した瞬間でない0
		else {
			keyState[i] = 0;			//0にリセット
		}
	}
}

// 押された瞬間
bool InputKeyBoard::IsDown(const KeyBoardCode _button)
{
	int num = CodeNum(_button);
	if (keyState[num] == 1) {
		return true;
	}
	return false;
}

// 押し続けているか
bool InputKeyBoard::IsHeld(const KeyBoardCode _button)
{
	int num = CodeNum(_button);
	if (keyState[num] > 0) {
		return true;
	}
	return false;
}

// 離された直後
bool InputKeyBoard::IsUp(const KeyBoardCode _button)
{
	int num = CodeNum(_button);

	if (keyState[num] == -1) {
		return true;
	}
	return false;
}