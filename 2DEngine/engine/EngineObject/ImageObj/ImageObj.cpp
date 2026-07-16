#include "ImageObj.h"
#include "Utils/Render/Render.h"

void ImageObj::Draw() {
	Utils::Render::RenderImage(
		rect,
		image,
		anchor,
		layer
	);
}