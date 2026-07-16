#include "ImageManager.h"


void ImageManager::Init() {
	InitErrorImage();
	Load();
}

void ImageManager::InitErrorImage() {

	if ((errorImage.handle = LoadGraph("engine/Master/Manager/ImageManager/error.png")) == -1) {

		std::cerr << "errorImageの初期化に失敗しました" << std::endl;
		return;
	}

	Vector2<int> size;
	GetGraphSize(errorImage.handle, &size.x, &size.y);

	errorImage.size = size.Cast<float>();
}

// 複数画像用
void ImageManager::AddSpriteEntry(std::string _name, std::string spriteName, Vector2<int> _gridPixelSize) {

	// 同名のエントリーがあるならスキップ
	if (nullptr != SearchSprite(_name)) {

		std::cerr << "SpriteEntry : " << _name << " はすでにあります" << std::endl;
		return;
	}

	SpriteEntry entry(_name);

	// すべての画像はimagesに入っている前提
	spriteName = "Images/" + spriteName;

	if (entry.SpriteSet(&errorImage, spriteName, _gridPixelSize)) {

		// 正常に作成できた場合push_back
		spriteEntrys.push_back(SpriteEntry(entry));
	}
	else {
		std::cerr << "SpriteEntry : " << _name << " は、正常に生成することができませんでした" << std::endl;
	}

}

const Sprite* ImageManager::SearchSprite(const std::string& _name) {

	for (auto& spriteEntry : spriteEntrys) {

		// 名前が一致するか
		if (spriteEntry.GetName() == _name) { return &spriteEntry.GetSprite(); }
	}

	return nullptr; // 見つからなかった場合
}