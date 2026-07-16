#pragma once

template<typename T>
struct Vector3{
	T x;
	T y;
	T z;

	// Cast‚Å•û•ÏX‰Â”\
	template<typename U>
	Vector3<U> Cast() {
		return {
			static_cast<U>(x),
			static_cast<U>(y),
			static_cast<U>(z)
		};
	}
};