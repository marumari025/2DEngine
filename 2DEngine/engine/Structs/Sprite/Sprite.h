#pragma once

#include "stdafx.h"
#include "../Image/Image.h"
#include "../Vector/Vector2.h"

struct Sprite
{

	// 画像ハンドル配列
	std::vector<int> handles;

	// 一画像のサイズ(フロートのほうが計算しやすくなるため)
	Vector2<float> gridPixelSize = { 0,0 };

	// 画像のグリッド数
	Vector2<int> gridCount = { 0,0 };

	Image GetImage(int _num = 0) const;

	Image GetImage(int _x, int _y) const;
};