#include "Manager/ImageManager/ImageManager.h"

void ImageManager::Load() {

	// AddSpriteEntry(std::string _name, std::string spriteName)
	// AddSpriteEntry(std::string _name, std::string spriteName, Vector2<int> _gridPixelSize)

	AddSpriteEntry("monochrome_transparent", "kenney/monochrome-transparent_packed.png", Vector2<int>{16, 16});

}