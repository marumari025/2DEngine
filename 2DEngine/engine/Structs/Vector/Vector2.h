#pragma once

#include "stdafx.h"

template<typename T>
struct Vector2 {
	T x;
	T y;

	// 計算系統
	Vector2 operator+(const Vector2& v) const { return { x + v.x, y + v.y }; }
	Vector2 operator-(const Vector2& v) const { return { x - v.x, y - v.y }; }
	Vector2 operator*(T s)              const { return { x * s,   y * s }; }
	Vector2 operator/(T s)              const { return { x / s,   y / s }; }

	Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
	Vector2& operator*=(T s) { x *= s;   y *= s;   return *this; }
	Vector2& operator/=(T s) { x /= s;   y /= s;   return *this; }

	bool operator==(const Vector2& v) const { return x == v.x && y == v.y; }
	bool operator!=(const Vector2& v) const { return !(*this == v); }

	// Castで方変更可能
	template<typename U>
	Vector2<U> Cast() {
		// コンパイル時に分岐で実装時コストを抑える
		if constexpr (std::is_integral_v<U>) {

			// 整数型のみ四捨五入キャスト
			return {
				static_cast<U>(std::round(x)),
				static_cast<U>(std::round(y))
			};
		}
		else {
			return {
				static_cast<U>(x),
				static_cast<U>(y)
			};
		}
	}
};