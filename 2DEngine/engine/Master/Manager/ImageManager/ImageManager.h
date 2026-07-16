#pragma once

#include "stdafx.h"
#include "SpriteEntry/SpriteEntry.h"

class ImageManager
{
protected:

	std::vector<SpriteEntry> spriteEntrys;

	Image errorImage;

public:

	Image GetErrorImage() { return errorImage; }

	void Init();

	// エラー画像の初期化
	void InitErrorImage();

	// 画像のロード
	void Load();

	// SpriteEntry追加関数
	void AddSpriteEntry(std::string _name, std::string spriteName, Vector2<int> _gridPixelSize = { 0,0 });

	// Sprite検索
	const Sprite* SearchSprite(const std::string& _name);
};