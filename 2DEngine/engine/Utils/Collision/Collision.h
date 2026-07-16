#pragma once
#include "Structs/Structs.h"

namespace Utils::Collision
{
	// 円と円の当たり判定
	bool CircleCircle(
		Vector2<float> aPos,
		float aRadius,
		Vector2<float> bPos,
		float bRadius
	);

	// 長方形と長方形の当たり判定
	bool RectRect(
		Rect<float> aRect,
		Rect<float> bRect
	);

	// 長方形と長方形の当たり判定 (辺の接触もあたりに含む)
	bool RectRectInclusive(
		Rect<float> aRect,
		Rect<float> bRect
	);

	// Rectめり込み解決
	void RectRectResolve(
		Rect<float>* _mover,
		Rect<float> _static
	);

	// 一番めり込みが小さい方向
	int CalcPenetrationSide(
		Side<float> _penetration
	);

	// 重なり量が一番小さいところに合わせて位置替え
	void ApplyResolve(
		int _collisionSide,
		Rect<float>* _mover,
		Side<float> _penetrations
	);
}