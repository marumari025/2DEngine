#include "Tag.h"

namespace Utils::Tag {

	int Tag(Utils::Tag::Type _tag) {
		return (1 << static_cast<int>(_tag));
	}

}