#pragma once
#include "../Vector/Vector2.h"

// 長方形
template<typename T>
struct Rect {
	Vector2<T> pos;
	Vector2<T> size;

	// 計算系統
	Rect operator*(T s) const { return { pos * s,   size * s }; }
	Rect operator/(T s) const { return { pos / s,   size / s }; }

	Rect& operator*=(T s) { pos *= s;   size *= s;   return *this; }
	Rect& operator/=(T s) { pos /= s;   size /= s;   return *this; }

	bool operator==(const Rect& v) const { return pos == v.pos && size == v.size; }
	bool operator!=(const Rect& v) const { return !(*this == v); }

	// Castで方変更可能
	template<typename U>
	Rect<U> Cast() {
		return {
			pos.Cast<U>(),
			size.Cast<U>()
		};
	}

};