#pragma once

#include "BaseObj.h"
#include "Utils/Utils.h"
#include "Master.h"
#include "Types/LayerType.h"

class TextMove : public Text
{
public:
	TextMove(
		std::string _str,

		float _x, float _y,
		float _renderSizeX, float _renderSizeY,

		std::string _fontName,

		Utils::Anchor::Type _anc = Utils::Anchor::Type::S,
		Utils::Layer::Type _lay = Utils::Layer::Type::Default
	) :
		Text(
			_str,
			
			_x, _y, 
			_renderSizeX, _renderSizeY, 
			
			_fontName,

			_anc, 
			_lay
		) 
	{
	}

	void Update() override {
		InputKeyBoard& InputKB = Master::Input().KeyBoard();
		float speed = 100;

		Vector2<float> vec = { 0,0 };
		if (InputKB.IsHeld(KeyBoardCode::W) == true) {
			vec.y += speed;
		}
		if (InputKB.IsHeld(KeyBoardCode::A) == true) {
			vec.x -= speed;
		}
		if (InputKB.IsHeld(KeyBoardCode::S) == true) {
			vec.y -= speed;
		}
		if (InputKB.IsHeld(KeyBoardCode::D) == true) {
			vec.x += speed;
		}

		pos += vec * Master::Time().DeltaTime();
	}
};