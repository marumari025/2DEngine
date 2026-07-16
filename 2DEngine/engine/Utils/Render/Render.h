#pragma once

#include "Structs/Structs.h"
#include "EngineObject/Camera/Camera.h"
#include "Master/Manager/FontsManager/BitmapFont/BitmapFont.h"



// 描画計算
namespace Utils::Render
{
	// Rectをカメラ範囲にクリッピング
	Rect<float> ClipRect(Rect<float> objRect, Rect<float> camRect);

	// _flipに合わせて描画位置等を変更
	void ImageFlip(
		Vector2<int> _flip,
		Side<int>* _drawSide,
		Rect<float>* _src,
		Vector2<float> _size
	);

	// Rectを内部でカメラ分の計算をして実際に描画
	void RenderRect(
		Rect<float> _rect,
		Color _color,
		Utils::Anchor::Type _anc,
		Utils::Layer::Type _lay
	);

	// Rectを内部でカメラ分の計算をして実際に描画
	void RenderLine(
		Vector2<float> vec1,
		Vector2<float> vec2,
		Color _color,
		Utils::Layer::Type _lay
	);

	// 内部でカメラ分の計算をして実際に描画
	void RenderImage(
		Rect<float> _rect,
		Image image,
		Utils::Anchor::Type _anc,
		Utils::Layer::Type _lay,
		Vector2<int> _flip = { FALSE,FALSE }
	);

	// 内部でカメラ分の計算をして実際に描画
	void RenderString(
		Vector2<float> _pos,
		std::string _str,
		Vector2<float> _renderSize,
		BitmapFont* const font,
		Utils::Anchor::Type _anc,
		Utils::Layer::Type _lay
	);

	// すべてのカメラの背景を指定職に変更
	void RenderCamerasBack();
}