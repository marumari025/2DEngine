#pragma once

#include "stdafx.h"
#include "Structs/Structs.h"
#include "BaseObj.h"
#include "Types/LayerType.h"
#include "Manager/FontsManager/BitmapFont/BitmapFont.h"
#include "Master.h"


class Text : public BaseObj
{
protected:

	Vector2<float> pos;

	// 一文字分の描画サイズ
	Vector2<float> renderSize;

	// 表示文字
	std::string str;

	// フォントの名前
	std::string fontName;

	// フォント
	BitmapFont* font;

public:

	Text(
		std::string _str,

		float _x, float _y,
		float _renderSizeX, float _renderSizeY,

		std::string _fontName,

		Utils::Anchor::Type _anc = Utils::Anchor::Type::S,
		Utils::Layer::Type _lay = Utils::Layer::Type::Default

	) :
		pos{ _x,_y },
		renderSize{ _renderSizeX, _renderSizeY },
		str(_str),
		fontName(_fontName),
		font(nullptr)
	{
		anchor = _anc;
		layer = _lay;
	}

	Vector2<float>& Pos() { return pos; }
	Vector2<float>& RenderSize() { return renderSize; }
	std::string& Str() { return str; }
	BitmapFont* Font() { return font; }

	void Start() override;
	void Draw() override;

};