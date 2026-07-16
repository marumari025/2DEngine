#include "Sprite.h"
#include "Master.h"

Image Sprite::GetImage(int _num) const {

	// 画像の有無チェック
	if (handles.empty()) { return Master::Image().GetErrorImage(); }

	// 範囲外チェック
	if (0 > _num || _num >= handles.size()) { return Master::Image().GetErrorImage(); }

	return { handles[_num] , gridPixelSize };
}

Image Sprite::GetImage(int _x, int _y) const {

	// 画像の有無チェック
	if (handles.empty()) { return Master::Image().GetErrorImage(); }

	int num = (_y * gridCount.x) + _x;

	// 範囲外チェック
	if (0 > num || num >= handles.size()) { return Master::Image().GetErrorImage(); }

	return { handles[num] , gridPixelSize };
}