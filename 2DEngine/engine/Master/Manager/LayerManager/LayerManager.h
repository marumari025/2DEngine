#pragma once

#include "Types/LayerType.h"
#include "Structs/LayerMask/LayerMask.h"

// レイヤーの情報と、レイヤーの計算をする
class LayerManager
{
protected:

	// LayerOptionフォルダで作成
	LayerManager();
	// Masterの管理下のみ
	friend class Master;

	// LayerMatrixの初期か
	void InitLayerMatrix();

	// どのレイヤーとレイヤーが当たるか
	int layerMatrix[32];

public:

	// ヒットしなくなるように変更
	void RemoveCollide(Utils::Layer::Type a, Utils::Layer::Type b);

	// 当たるか確認
	bool CanCollide(Utils::Layer::Type a, Utils::Layer::Type b);
	
	// マスクと比較
	bool CanCollide(Utils::Layer::Type a, LayerMask mask);

};
