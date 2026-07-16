#include "stdafx.h" // TRUE FALSE‚Ì‚½‚ß
#include "Manager/LayerManager/LayerManager.h"

LayerManager::LayerManager() {

	InitLayerMatrix();

	// Type‚ğˆµ‚¢‚â‚·‚­
	using Type = Utils::Layer::Type;

	// === ˆÈ‰º‚Å“–‚½‚ç‚È‚¢ƒŒƒCƒ„[‚Ìİ’è ===

	// —á::“G“¯m“–‚½‚ç‚È‚¢‚æ‚¤‚É
	// RemoveCollide(Type::Enemy, Type::Enemy);

}