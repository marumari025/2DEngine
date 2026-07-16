#include "Text.h"
#include "Utils/Render/Render.h"
#include "Master.h"

void Text::Start() {

	font = Master::Font().SearchFont(fontName);
}

void Text::Draw() {
	if (font == nullptr) {

		std::cerr << "font = nullptr" << std::endl;
		return;

	}

	Utils::Render::RenderString(pos, str, renderSize, font, anchor, layer);

}