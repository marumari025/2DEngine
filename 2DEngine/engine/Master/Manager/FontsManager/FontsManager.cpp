#include "FontsManager.h"

void FontManager::AddFont(
	std::string fontName,
	float _gridPixelX, float _gridPixelY,
	float _charX, float _charY,
	std::string _bitmapName
) {

	if (nullptr != SearchFont(fontName)) {

		std::cerr << "Font : " << fontName << " はすでにあります" << std::endl;
		return;
	}

	std::cerr << "Font : " << fontName << " を追加" << std::endl;

	// もし、同じ名前のフォントがないなら追加
	fonts.push_back(
		std::make_unique<BitmapFont>(
			fontName,
			_gridPixelX, _gridPixelY,
			_charX, _charY,
			_bitmapName
		)
	);

}

BitmapFont* FontManager::SearchFont(const std::string& _name) {

	for (auto& font : fonts)
	{

		// 名前が一致するか
		if (font->Name() == _name) { return font.get(); }

	}

	return nullptr; // 見つからなかった場合
}