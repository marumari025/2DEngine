#pragma once
#include "../Rect/Rect.h"

// ’·•ûŒ`
template<typename T>
struct Side {
	T top;
	T left;
	T bottom;
	T right;

	// Cast‚Å•û•ÏX‰Â”\
	template<typename U>
	Side<U> Cast() {
		return {
			static_cast<U>(top),
			static_cast<U>(left),
			static_cast<U>(bottom),
			static_cast<U>(right)
		};
	}
};