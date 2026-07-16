#include "Collision.h"
#include "../Math/Math.h"

namespace Utils::Collision
{
	bool CircleCircle(Vector2<float> aPos, float aRadius, Vector2<float> bPos, float bRadius)
	{
		float distSq =
			Utils::Math::Square(aPos.x - bPos.x) +
			Utils::Math::Square(aPos.y - bPos.y);

		float radius = aRadius + bRadius;

		return distSq <= Utils::Math::Square(radius);
	}

	bool RectRect(Rect<float> aRect, Rect<float> bRect)
	{
		Side<float> aSide = Utils::Math::RectToSide(aRect);
		Side<float> bSide = Utils::Math::RectToSide(bRect);

		return (
			aSide.right > bSide.left &&
			aSide.left < bSide.right &&
			aSide.top > bSide.bottom &&
			aSide.bottom < bSide.top
			);
	}

	bool RectRectInclusive(Rect<float> aRect, Rect<float> bRect)
	{
		// 誤差対策
		const float EPS = 0.001f;

		Side<float> aSide = Utils::Math::RectToSide(aRect);
		Side<float> bSide = Utils::Math::RectToSide(bRect);

		return (
			aSide.right >= bSide.left - EPS &&
			aSide.left <= bSide.right + EPS &&
			aSide.top >= bSide.bottom - EPS &&
			aSide.bottom <= bSide.top + EPS
			);
	}

	void RectRectResolve(Rect<float>* _mover, Rect<float> _static) {

		// 重なって居ないならリターン
		if (!Utils::Collision::RectRect(*_mover, _static))return;

		// サイド取得
		Side<float> moverSide = Utils::Math::RectToSide(*_mover);
		Side<float> staticSide = Utils::Math::RectToSide(_static);

		// すべての方向からの重なり量をとる
		Side<float> penetrations = Utils::Math::GetPenetrations(moverSide, staticSide);

		int collisionSide = CalcPenetrationSide(penetrations);

		ApplyResolve(collisionSide, _mover, penetrations);
	}

	int	CalcPenetrationSide(Side<float> _penetration) {

		float min = _penetration.left;
		int result = HIT_LEFT;

		if (_penetration.right < min) {
			min = _penetration.right;
			result = HIT_RIGHT;
		}

		if (_penetration.top < min) {
			min = _penetration.top;
			result = HIT_TOP;
		}

		if (_penetration.bottom < min) {
			min = _penetration.bottom;
			result = HIT_BOTTOM;
		}

		return result;
	}

	void ApplyResolve(int _collisionSide, Rect<float>* _mover, Side<float> _penetrations) {
		if (_collisionSide & HIT_LEFT) {
			_mover->pos.x -= _penetrations.left;
		}
		else if (_collisionSide & HIT_RIGHT) {
			_mover->pos.x += _penetrations.right;
		}
		else if (_collisionSide & HIT_TOP) {
			_mover->pos.y -= _penetrations.top;
		}
		else if (_collisionSide & HIT_BOTTOM) {
			_mover->pos.y += _penetrations.bottom;
		}
	}
}