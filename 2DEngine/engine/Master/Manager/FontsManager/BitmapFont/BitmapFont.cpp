#include "BitmapFont.h"

// Bitmap画像サイズを取得
Vector2<int> BitmapFont::BitmapFontSize(std::string _bitmapName) {

	Vector2<int> size;

	// ロードしたハンドルを変数に保存しないと解放できない
	int tmpHandle = LoadGraph(_bitmapName.c_str());

	// 全体画像サイズを取得
	GetGraphSize(tmpHandle, &size.x, &size.y);

	// 一時的なので、使い終わったら解放
	DeleteGraph(tmpHandle);

	return size;
}

void BitmapFont::BitmapFontSet(std::string _bitmapName) {

	// 全体サイズ
	Vector2<int> bitmapSize = BitmapFontSize(_bitmapName);

	Vector2<int> gridPixelSizeInt = gridPixelSize.Cast<int>();

	// 横文字数
	gridCount.x = bitmapSize.x / gridPixelSizeInt.x;
	// 縦の文字数
	gridCount.y = bitmapSize.y / gridPixelSizeInt.y;

	// 文字が入る一次元配列
	std::vector<int> handles(gridCount.x * gridCount.y);

	LoadDivGraph(
		_bitmapName.c_str(),	// ファイルパス
		gridCount.x * gridCount.y,		// 総分割数
		gridCount.x,				// 横の分割数
		gridCount.y,				// 縦の分割数
		gridPixelSizeInt.x,			// 1文字の横サイズ（ピクセル）
		gridPixelSizeInt.y,			// 1文字の縦サイズ（ピクセル）
		handles.data()		// ハンドルの格納先
	);

	// ビットマップの初期化
	bitmap.resize(gridCount.y, std::vector<int>(gridCount.x, -1));

	// bitmapにハンドルを入れなおす
	for (int i = 0; i < gridCount.y; i++) {
		for (int j = 0; j < gridCount.x; j++) {
			bitmap[i][j] = handles[i * gridCount.x + j];
		}
	}
}

// グリッド内での文字のオフセット（中央寄せ）
Vector2<float> BitmapFont::CharOffset() const {

	return {
		(gridPixelSize.x - charSize.x) / 2.0f,
		(gridPixelSize.y - charSize.y) / 2.0f
	};
}

int BitmapFont::Handle(int c) {
	int u = (c % gridCount.x);
	int v = (c / gridCount.x);

	if (u < 0 || gridCount.x <= u || v < 0 || gridCount.y <= v) {
		// インデックス外
		return -1;
	}

	return bitmap[v][u];
}