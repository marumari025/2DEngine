#include "SpriteEntry.h"

bool SpriteEntry::SpriteSet(Image* _errorImage, std::string _spriteName, Vector2<int> _gridPixelSize) {

	Vector2<int> fullSize = GetFullSize(_spriteName);

	// 0以下の画像サイズは正常に取れていない
	if (fullSize.x <= 0 || fullSize.y <= 0) { return false; } // ロード失敗

	// 0除算などになりそうなものは一枚だけとして扱う
	if (_gridPixelSize.x <= 0 || _gridPixelSize.y <= 0) {

		_gridPixelSize = fullSize;
	}

	Vector2<int> gridCount = CalcGridCount(fullSize, _gridPixelSize);

	if (!LoadHandles(_spriteName, _gridPixelSize, gridCount)) { return false; }

	sprite.gridPixelSize = _gridPixelSize.Cast<float>();

	sprite.gridCount = gridCount;

	return true;
}

Vector2<int> SpriteEntry::GetFullSize(std::string _spriteName) {

	// 全体画像サイズ({ 0,0 }ままの場合はエラーということ)
	Vector2<int> fullSize = { 0,0 };

	// 全体画像
	int tmpHandle = LoadGraph(_spriteName.c_str());

	if (tmpHandle != -1) {

		// 画像サイズを取得
		GetGraphSize(tmpHandle, &fullSize.x, &fullSize.y);
	}

	// 全体画像ハンドルの開放
	DeleteGraph(tmpHandle);

	return fullSize;
}

Vector2<int> SpriteEntry::CalcGridCount(Vector2<int> _fullSize, Vector2<int> _gridPixelSize) {

	return { _fullSize.x / _gridPixelSize.x , _fullSize.y / _gridPixelSize.y };
}

bool SpriteEntry::LoadHandles(std::string _spriteName, Vector2<int> _gridPixelSize, Vector2<int> gridCount) {

	// 一時的に画像が入る一次元配列
	std::vector<int> tmpHandles(gridCount.x * gridCount.y);

	if (LoadDivGraph(
		_spriteName.c_str(),	// ファイルパス
		gridCount.x * gridCount.y,		// 総分割数
		gridCount.x,				// 横の分割数
		gridCount.y,				// 縦の分割数
		_gridPixelSize.x,			// 1文字の横サイズ（ピクセル）
		_gridPixelSize.y,			// 1文字の縦サイズ（ピクセル）
		tmpHandles.data()		// ハンドルの格納先
	) == -1) {

		// -1だったらfalse返して作成しない
		return false;
	}

	sprite.handles = tmpHandles;
	return true;
}