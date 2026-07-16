#pragma once

#include "stdafx.h"
#include "Structs/Structs.h"

struct BitmapFont {
	// 1文字の画像の二次元配列
	std::vector<std::vector<int>> bitmap;

	// 1文字のサイズ
	int textSize;

	// 文字のグリッド数
	Vector2<int> gridSize;

	// 画像のサイズ
	BitmapFont(int _textSize, std::string _bitmapName) :
		textSize(_textSize)
	{
		BitmapFontSet(_bitmapName);
	}

	void BitmapFontSet(std::string _bitmapName) {

		// 全体サイズ
		Vector2<int> bitmapSize = BitmapFontSize(_bitmapName);

		// 横の文字数
		gridSize.x = bitmapSize.x / textSize;
		// 縦の文字数
		gridSize.y = bitmapSize.y / textSize;

		// 文字が入る一次元配列
		std::vector<int> handles(gridSize.x * gridSize.y);

		LoadDivGraph(
			_bitmapName.c_str(),	// ファイルパス
			gridSize.x * gridSize.y,		// 総分割数
			gridSize.x,				// 横の分割数
			gridSize.y,				// 縦の分割数
			textSize,			// 1文字の横サイズ（ピクセル）
			textSize,			// 1文字の縦サイズ（ピクセル）
			handles.data()		// ハンドルの格納先
		);

		// ビットマップの初期化
		bitmap.resize(gridSize.y, std::vector<int>(gridSize.x, -1));

		// bitmapにハンドルを入れなおす
		for (int i = 0; i < gridSize.y; i++) {
			for (int j = 0; j < gridSize.x; j++) {
				bitmap[i][j] = handles[i * gridSize.x + j];
			}
		}

	}

	// Bitmap画像サイズを取得
	Vector2<int> BitmapFontSize(std::string _bitmapName) {

		Vector2<int> size;

		// ロードしたハンドルを変数に保存しないと解放できない
		int tmpHandle = LoadGraph(_bitmapName.c_str());

		// 全体画像サイズを取得
		GetGraphSize(tmpHandle, &size.x, &size.y);

		// 一時的なので、使い終わったら解放
		DeleteGraph(tmpHandle);

		return size;
	}

	int Handle(int c) {
		int u = (c % gridSize.x);
		int v = (c / gridSize.x);

		if (u < 0 || gridSize.x <= u || v < 0 || gridSize.y <= v) {
			// インデックス外
			return -1;
		}

		return bitmap[v][u];
	}
};
