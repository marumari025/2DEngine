#include "LayerManager.h"

void LayerManager::InitLayerMatrix() {

	// layerMatrix‚ğ‚Ìbit‚ğ1‚Å‰Šú‰»
	for (int i = 0; i < 32; i++) {
		layerMatrix[i] = ~0;
	}

}

void LayerManager::RemoveCollide(Utils::Layer::Type a, Utils::Layer::Type b) {

	// enum‚Ì‚Ç‚±‚É‚¢‚é‚©
	int ia = static_cast<int>(a);
	int ib = static_cast<int>(b);

	// a‚Æb‚ª“–‚½‚ç‚È‚¢‚æ‚¤‚É•ÏX
	layerMatrix[ia] &= ~(1 << ib);
	layerMatrix[ib] &= ~(1 << ia);
}

bool LayerManager::CanCollide(Utils::Layer::Type a, Utils::Layer::Type b) {

	// enum‚Ì‚Ç‚±‚É‚¢‚é‚©
	int ia = static_cast<int>(a);
	int ib = static_cast<int>(b);

	return (layerMatrix[ia] >> ib) & 1;
}

bool LayerManager::CanCollide(Utils::Layer::Type type, LayerMask mask) {

	// enum‚Ì‚Ç‚±‚É‚¢‚é‚©
	int num = static_cast<int>(type);

	return (mask.mask >> num) & 1;
}