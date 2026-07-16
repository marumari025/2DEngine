#include "stdafx.h"
#include "Master.h"
#include "Utils/Utils.h"
#include "Render.h"

namespace Utils::Render
{

	Rect<float> ClipRect(Rect<float> objRect, Rect<float> camRect) {

		Side<float> objSide = Utils::Math::RectToSide(objRect);
		Side<float> camSide = Utils::Math::RectToSide(camRect);

		float left = (objSide.left >= camSide.left)
			? objSide.left : camSide.left;

		float right = (objSide.right < camSide.right)
			? objSide.right : camSide.right;

		float top = (objSide.top < camSide.top)
			? objSide.top : camSide.top;

		float bottom = (objSide.bottom >= camSide.bottom)
			? objSide.bottom : camSide.bottom;

		// SideToRect
		return Rect<float>{ {left, bottom}, { right - left, top - bottom } };
	}

	void ImageFlip(Vector2<int> _flip, Side<int>* _drawSide, Rect<float>* _src, Vector2<float> _size) {

		if (_flip.x == TRUE) {
			Utils::Math::Swap(&_drawSide->left, &_drawSide->right);
			_src->pos.x = _size.x - _src->pos.x - _src->size.x;
		}

		if (_flip.y == FALSE) {
			Utils::Math::Swap(&_drawSide->top, &_drawSide->bottom);
			_src->pos.y = _size.y - _src->pos.y - _src->size.y;
		}
	}


	void RenderRect(Rect<float> _rect, Color _color, Utils::Anchor::Type _anc, Utils::Layer::Type _lay) {

		// カメラの数だけ繰り返す
		for (Camera* cam : Master::Scene().Find<Camera>().AllOfType()) {

			// カメラに映るか確認
			if (!(Master::Layer().CanCollide(_lay, cam->LayerMask()))) { continue; }

			// 座標を左上座標に変換
			Rect<float> camRect = Utils::Math::ToOrigin(cam->GetRect(), cam->Anchor());
			Rect<float> objRect = Utils::Math::ToOrigin(_rect * cam->Zoom(), _anc);

			// カメラ範囲内に居るか確認
			if (!Utils::Collision::RectRectInclusive(objRect, camRect)) { continue; }

			// カメラからはみ出た分を削除
			Rect<float> clipped = ClipRect(objRect, camRect);

			// カメラ相対座標に変換
			clipped.pos = (clipped.pos - cam->WorldPos()) + cam->ScreenPos();

			// Y軸反転（screenPosを中心に反転）
			clipped.pos.y = 2.0f * cam->ScreenPos().y - (clipped.pos.y + clipped.size.y);

			// DXライブラリのDrawBoxはintなのでCast
			Rect<int> drawRect = clipped.Cast<int>();

			DrawBox(
				drawRect.pos.x,
				drawRect.pos.y,
				drawRect.pos.x + drawRect.size.x,
				drawRect.pos.y + drawRect.size.y,
				_color.GetRGB(),
				TRUE);
		}
	}

	void RenderLine(Vector2<float> _vec1, Vector2<float> _vec2, Color _color, Utils::Layer::Type _lay) {

		// カメラの数だけ繰り返す
		for (Camera* cam : Master::Scene().Find<Camera>().AllOfType()) {

			// カメラに映るか確認
			if (!(Master::Layer().CanCollide(_lay, cam->LayerMask()))) { continue; }

			// カメラ相対座標に変換
			Vector2<float> p1 = (_vec1 - cam->WorldPos()) + cam->ScreenPos();
			Vector2<float> p2 = (_vec2 - cam->WorldPos()) + cam->ScreenPos();

			// Y軸反転
			p1.y = 2.0f * cam->ScreenPos().y - p1.y;
			p2.y = 2.0f * cam->ScreenPos().y - p2.y;

			// int化
			Vector2<int> p1i = p1.Cast<int>();
			Vector2<int> p2i = p2.Cast<int>();

			DrawLine(
				p1i.x, p1i.y,
				p2i.x, p2i.y,
				_color.GetRGB()
			);
		}
	}



	void RenderImage(Rect<float> _rect, Image _image, Utils::Anchor::Type _anc, Utils::Layer::Type _lay, Vector2<int> _flip) {

		// カメラの数だけ繰り返す
		for (Camera* cam : Master::Scene().Find<Camera>().AllOfType()) {

			// カメラに映るか確認
			if (!(Master::Layer().CanCollide(_lay, cam->LayerMask()))) { continue; }

			// カメラ左上座標
			Rect<float> camRect = Utils::Math::ToOrigin(cam->GetRect(), cam->Anchor());
			// オブジェクト左上座標
			Rect<float> objRect = Utils::Math::ToOrigin(_rect * cam->Zoom(), _anc);

			// カメラ範囲内に居るか確認
			if (!Utils::Collision::RectRectInclusive(objRect, camRect)) { continue; }

			// objRectのカメラ内にクリップ
			Rect<float> clipped = ClipRect(objRect, camRect);

			// オブジェのサイズ1にどのぐらい入るか
			Vector2<float> ratio{
				ratio.x = _image.size.x / objRect.size.x,
				ratio.y = _image.size.y / objRect.size.y
			};

			// 画像の切り取る形
			Rect<float> src{
				src.pos.x = (clipped.pos.x - objRect.pos.x) * ratio.x,
				src.pos.y = (clipped.pos.y - objRect.pos.y) * ratio.y,
				src.size.x = clipped.size.x * ratio.x,
				src.size.y = clipped.size.y * ratio.y
			};

			// カメラ相対座標に変換
			clipped.pos = (clipped.pos - cam->WorldPos()) + cam->ScreenPos();

			// Y軸反転（screenPosを中心に反転）
			clipped.pos.y = 2.0f * cam->ScreenPos().y - (clipped.pos.y + clipped.size.y);

			// 描画先の端
			Side<int> drawSide;
			// DXライブラリのDrawRectExtendGraphはintなのでCast
			drawSide = Utils::Math::RectToSide(clipped).Cast<int>();

			ImageFlip(_flip, &drawSide, &src, _image.size);

			// 画像の切り取る形(int)
			Rect<int> srcInt = src.Cast<int>();

			DrawRectExtendGraph(
				drawSide.left,		// 描画先の左（スクリーン座標）
				drawSide.top,		// 描画先の上（スクリーン座標）
				drawSide.right,		// 描画先の右（スクリーン座標）
				drawSide.bottom,	// 描画先の下（スクリーン座標）
				srcInt.pos.x,		// 画像の切り取り開始X（ピクセル）
				srcInt.pos.y,		// 画像の切り取り開始Y（ピクセル）
				srcInt.size.x,		// 画像の切り取り幅（ピクセル）
				srcInt.size.y,		// 画像の切り取り高さ（ピクセル）
				_image.handle,  // 画像ハンドル
				TRUE     // 透過フラグ
			);
		}
	}

	// テキストのレクト計算
	Rect<float> TextRect(Vector2<float> _pos, std::string _str, Vector2<float> _size) {

		// 文字サイズ変数
		Vector2<float> textSize;

		// 文章の横サイズ
		textSize.x = _size.x * static_cast<float>(_str.size());
		// 今回は一列のみの文章
		textSize.y = _size.y;

		return { _pos , textSize };

	}

	void RenderString(Vector2<float> _pos, std::string _str, Vector2<float> _renderSize, BitmapFont* const font, Utils::Anchor::Type _anc, Utils::Layer::Type _lay) {

		// カメラの数だけ繰り返す
		for (Camera* cam : Master::Scene().Find<Camera>().AllOfType()) {

			// カメラに映るか確認
			if (!(Master::Layer().CanCollide(_lay, cam->LayerMask()))) { continue; }

			// カメラ左上座標
			Rect<float> camRect = Utils::Math::ToOrigin(cam->GetRect(), cam->Anchor());
			// text左上座標
			Rect<float> stringRect = Utils::Math::ToOrigin(TextRect(_pos, _str, _renderSize) * cam->Zoom(), _anc);

			// カメラ範囲内に文字列のどこかが入っているか確認
			if (!Utils::Collision::RectRectInclusive(stringRect, camRect)) { continue; }

			// 一文字分のRect
			Rect<float> textRect = {
				stringRect.pos.x,
				stringRect.pos.y,
				_renderSize.x,
				_renderSize.y
			};

			Vector2<float> offset = font->CharOffset();

			Vector2<float> gridPixelSize = font->GridPixelSize();

			// オブジェのサイズ1にどのぐらい入るか
			Vector2<float> ratio{
				ratio.x = gridPixelSize.x / _renderSize.x,
				ratio.y = gridPixelSize.y / _renderSize.y
			};

			// 文字列の数だけ繰り返す
			for (int i = 0; i < _str.size(); i++) {

				// カメラ内部を求める
				Rect<float> clipped = ClipRect(textRect, camRect);

				// clippedとtextRectの比率でsrcもクリップする
				float clipRatioX = clipped.size.x / textRect.size.x;
				float clipRatioY = clipped.size.y / textRect.size.y;

				// 画像の切り取る形
				Rect<float> src{
					((clipped.pos.x - textRect.pos.x) + offset.x) ,
					((clipped.pos.y - textRect.pos.y) * ratio.y + offset.y) ,
					font->CharSize().x * clipRatioX,
					font->CharSize().y * clipRatioY,
				};

				// カメラ相対座標に変換
				clipped.pos = (clipped.pos - cam->WorldPos()) + cam->ScreenPos();

				// Y軸反転（screenPosを中心に反転）
				clipped.pos.y = 2.0f * cam->ScreenPos().y - (clipped.pos.y + clipped.size.y);

				// DXライブラリのDrawRectExtendGraphはintなのでCast
				Side<int> drawSide = Utils::Math::RectToSide(clipped).Cast<int>();

				Utils::Math::Swap(&drawSide.top, &drawSide.bottom);

				//Y軸反転
				src.pos.y = gridPixelSize.y - src.pos.y - src.size.y;

				Rect<int> srcRect = src.Cast<int>();

				int textHandle = font->Handle(_str[i]);

				// 使える文字か確認
				if (textHandle == -1) {
					// 使えない文字なら?に変更
					textHandle = font->Handle('?');
				}

				DrawRectExtendGraph(
					drawSide.left,		// 描画先の左（スクリーン座標）
					drawSide.top,		// 描画先の上（スクリーン座標）
					drawSide.right,		// 描画先の右（スクリーン座標）
					drawSide.bottom,	// 描画先の下（スクリーン座標）
					srcRect.pos.x,		// 画像の切り取り開始X（ピクセル）
					srcRect.pos.y,		// 画像の切り取り開始Y（ピクセル）
					srcRect.size.x,		// 画像の切り取り幅（ピクセル）
					srcRect.size.y,		// 画像の切り取り高さ（ピクセル）
					textHandle,			// 文字ハンドル
					TRUE				// 透過フラグ
				);

				// 一文字分ずらす
				textRect.pos.x += _renderSize.x;
			}
		}
	}

	void RenderCamerasBack() {

		// カメラの数だけ繰り返す
		for (Camera* cam : Master::Scene().Find<Camera>().AllOfType()) {

			Rect<float>camRect = { cam->ScreenPos(),cam->Size() };

			Side<int> camSide = Utils::Math::RectToSide(camRect, cam->Anchor()).Cast<int>();

			DrawBox(
				camSide.left,
				camSide.top,
				camSide.right,
				camSide.bottom,
				cam->BackColor().GetRGB(),
				TRUE);
		}
	}


}
