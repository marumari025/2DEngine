#pragma once

#include "stdafx.h"
#include "BaseObj.h"
#include "Structs/Structs.h"


class ImageObj : public BaseObj
{
protected:

	Rect<float> rect;
	Image image;

public:

	ImageObj(
		float _x, float _y, float _w, float _h,
		Image _image,
		Utils::Anchor::Type _anc = Utils::Anchor::Type::S,
		Utils::Layer::Type _lay = Utils::Layer::Type::Default
	) :
		rect{ _x,_y,_w,_h },
		image(_image)
	{
		anchor = _anc;
		layer = _lay;
	}

	void Draw() override;

};