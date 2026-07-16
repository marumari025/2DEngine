#pragma once

#include "stdafx.h"
#include "Structs/Structs.h"

class BitmapFont {
protected:
	// フォントを使うときの名前
	std::string name;

	// 1文字の画像の二次元配列
	std::vector<std::vector<int>> bitmap;
	// 切り分けグリッドサイズ（1マスのピクセルサイズ）
	Vector2<float> gridPixelSize;
	// 実際の文字サイズ
	Vector2<float> charSize;
	// 文字のグリッド数
	Vector2<int> gridCount;


	// Bitmap画像サイズを取得
	Vector2<int> BitmapFontSize(std::string _bitmapName);

	void BitmapFontSet(std::string _bitmapName);

public:

	BitmapFont(
		std::string _name,
		float _gridPixelX, float _gridPixelY,
		float _charX, float _charY,
		std::string _bitmapName
	) :
		name(_name),
		gridPixelSize{ _gridPixelX, _gridPixelY },
		charSize{ _charX, _charY },
		gridCount{ 0,0 }
	{
		BitmapFontSet(_bitmapName);
	}

	std::string& Name() { return name; }
	std::vector<std::vector<int>>& Bitmap() { return bitmap; }
	Vector2<float>& GridPixelSize() { return gridPixelSize; }
	Vector2<float>& CharSize() { return charSize; }
	Vector2<int>& GridCount() { return gridCount; }

	// グリッド内での文字のオフセット（中央寄せ）
	Vector2<float> CharOffset() const;

	int Handle(int c);
};
