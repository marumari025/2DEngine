#pragma once

#include "stdafx.h"
#include "Structs/Sprite/Sprite.h"

class SpriteEntry
{
protected:

	// 画像集合体の名前
	std::string name;

	// スプライト
	Sprite sprite;

	// 全体画像のサイズ
	Vector2<int> GetFullSize(std::string _spriteName);

	// グリッド数の計算
	Vector2<int> CalcGridCount(Vector2<int> _fullSize, Vector2<int> _gridPixelSize);

	// ハンドルを読み込む
	bool LoadHandles(std::string _spriteName, Vector2<int> _gridPixelSize, Vector2<int> gridCount);

public:

	SpriteEntry(std::string _name) :
		name(_name),
		sprite()
	{}

	std::string GetName() { return name; }

	const Sprite& GetSprite() { return sprite; }

	// スプライトの設定
	bool SpriteSet(Image* errorImage, std::string _spriteName, Vector2<int> _gridPixelSize);
};