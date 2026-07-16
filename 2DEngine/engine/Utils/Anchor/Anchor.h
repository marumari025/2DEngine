#pragma once

#include "stdafx.h"
#include "Structs/Structs.h"

namespace Utils::Anchor {
	enum class Type {
		Q /*左上*/, W /* 上 */, E /*右上*/,
		A /* 左 */, S /*中央*/, D /* 右 */,
		Z /*左下*/, X /* 下 */, C /*右下*/
	};

	inline const std::map<Type, Vector2<float>> anchorMap = {
		{ Type::Q, {  0.0f,  1.0f } },{ Type::W, {  0.5f,  1.0f } },{ Type::E, {  1.0f,  1.0f } },
		{ Type::A, {  0.0f,  0.5f } },{ Type::S, {  0.5f,  0.5f } },{ Type::D, {  1.0f,  0.5f } },
		{ Type::Z, {  0.0f,  0.0f } },{ Type::X, {  0.5f,  0.0f } },{ Type::C, {  1.0f,  0.0f } },
	};
}

// 使用例
// using namespace Utils::Anchor;
// Vector2<float> anc = anchorMap.at(Type::S);