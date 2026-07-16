#include "stdafx.h" // TRUE FALSE‚Ì‚½‚ß
#include "Manager/FontsManager/FontsManager.h"

void FontManager::Load()
{
	// ƒtƒHƒ“ƒg‚Ì’Ç‰Á
	AddFont("GoldFont64", 64, 64, 32, 64, "Images/Font/fontBitmap_64.png");
	AddFont("WhiteFont16", 64, 64, 32, 64, "Images/Font/fontBitmap_a_w.png");
}