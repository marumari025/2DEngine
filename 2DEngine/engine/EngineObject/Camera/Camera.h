#pragma once

#include "BaseObj.h"
#include"Structs/Structs.h"
#include "Utils/Anchor/Anchor.h"
#include "Master.h"

class Camera : public BaseObj
{
protected:

	// 表示するレイヤー
	LayerMask layerMask;

	// カメラが写しているワールド座標（中心）
	Vector2<float> worldPos;
	// ウィンドウ上のどこに描画するか（中心）
	Vector2<float> screenPos;
	// 映す範囲のサイズ
	Vector2<float> size;

	// カメラ背景色
	Color backColor;

	// ズーム倍率
	float zoom;

public:
	Camera(
		float _worldX, float _worldY,
		float _screenX, float _screenY,
		float _w, float _h,
		int _color = Master::Window().Color().GetRGB(),
		std::vector<Utils::Layer::Type> _removeLayers = {},
		float _zoom = 1.0f
	) :
		worldPos{ _worldX,_worldY },
		screenPos{ _screenX,_screenY },
		size{ _w,_h },
		backColor(_color),
		layerMask(_removeLayers),
		zoom(_zoom)

	{

	}

	LayerMask& LayerMask() { return layerMask; }

	Vector2<float>& WorldPos() { return worldPos; }

	Vector2<float>& ScreenPos() { return screenPos; }

	Vector2<float>& Size() { return size; }

	Color& BackColor() { return backColor; }

	float& Zoom() { return zoom; }

	// BaseObjが持っている変数を渡す
	Utils::Anchor::Type& Anchor() { return anchor; }

	// カメラの端
	Side<float> WorldCameraSide();

	// カメラ座標をRectとして使う場合に使用
	Rect<float> GetRect() const;

};