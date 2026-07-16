#pragma once

#include "stdafx.h"
#include "../Vector/Vector2.h"

struct Image
{
	// 画像ハンドル
	int handle = -1;

	// 画像サイズ
	Vector2<float> size = { 0,0 };
};