
#include "stdafx.h"
#include "Math.h"

namespace Utils::Math
{

	Side<float> RectToSide(Rect<float> rect, Utils::Anchor::Type anc) {
		rect = ToOrigin(rect, anc);

		Side<float> side;

		side.top = rect.pos.y + rect.size.y;
		side.left = rect.pos.x;
		side.bottom = rect.pos.y;
		side.right = rect.pos.x + rect.size.x;

		return side;
	}

	Rect<float> ToOrigin(Rect<float> rect, Utils::Anchor::Type anc) {

		using namespace Utils::Anchor;

		const Vector2<float>& bias = anchorMap.at(anc);

		rect.pos.x -= rect.size.x * bias.x;
		rect.pos.y -= rect.size.y * bias.y;

		return rect;
	}

	Rect<float> FromOrigin(Rect<float> rect, Utils::Anchor::Type anc) {

		using namespace Utils::Anchor;

		const Vector2<float>& bias = anchorMap.at(anc);

		rect.pos.x += rect.size.x * bias.x;
		rect.pos.y += rect.size.y * bias.y;

		return rect;
	}

	Side<float> GetPenetrations(Side<float> _moverSide, Side<float> _staticSide) {

		Side<float> result;

		result.left = abs(_moverSide.right - _staticSide.left);
		result.right = abs(_moverSide.left - _staticSide.right);
		result.bottom = abs(_moverSide.bottom - _staticSide.top);
		result.top = abs(_moverSide.top - _staticSide.bottom);

		return result;

	}

	float AngleToRadian(float _degree) {
		return _degree * (3.1415926535f / 180.0f);
	}

	float RadianToAngle(float _radian) {
		return _radian * (180.0f / 3.1415926535f);
	}

	Vector2<float>RadianToDirection(float _radian) {
		return { std::cos(_radian), std::sin(_radian) };
	}

	float DirectionToRadian(Vector2<float> _dir) {
		// atan2は(y, x)の順に引数を渡す点に注意
		return std::atan2(_dir.y, _dir.x);
	}

	float LookAtRadian(Vector2<float> _from, Vector2<float> _to) {
		// ターゲットへの方向ベクトルを作成
		Vector2<float> dir{ _to.x - _from.x, _to.y - _from.y };
		return DirectionToRadian(dir);
	}

	float DotVector2(Vector2<float> v1, Vector2<float> v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	float CrossVector2(Vector2<float> v1, Vector2<float> v2) {
		return v1.x * v2.y - v1.y * v2.x;
	}

	float Square(float value) {
		return value * value;
	}

	float Distance(Vector2<float> pos1, Vector2<float> pos2)
	{
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;

		return std::sqrt(dx * dx + dy * dy);
	}

}
