#pragma once

#include "stdafx.h"
#include "Types/LayerType.h"

struct LayerMask {

	int mask;

	LayerMask(std::vector<Utils::Layer::Type> types) :
		mask(~0)
	{
		for (auto& t : types)
			Remove(t);
	}

	void Remove(Utils::Layer::Type a) {
		mask &= ~(1 << static_cast<int>(a));
	}
	void Add(Utils::Layer::Type a) {
		mask |= (1 << static_cast<int>(a));
	}
};