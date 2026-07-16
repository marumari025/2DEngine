#pragma once
#include "stdafx.h"
#include "BitmapFont/BitmapFont.h"

class FontManager
{
protected:

	std::vector<std::unique_ptr<BitmapFont>> fonts;

	// フォントを追加
	void AddFont(
		std::string fontName,
		float _gridPixelX, float _gridPixelY,
		float _charX, float _charY,
		std::string _bitmapName
	);

public:
	void Load();

	// フォントを名前で探す
	BitmapFont* SearchFont(const std::string& _name);

};
