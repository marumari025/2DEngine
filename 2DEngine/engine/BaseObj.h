// ========================================
// ベースのオブジェクトを作る
// オブジェクトを簡単に
// 更新やアップデートできるように
// ========================================

// #include "BaseObj.h"
#pragma once

#include "stdafx.h"
#include "Utils/Anchor/Anchor.h"
#include "Types/LayerType.h"
#include "Utils/Tag/Tag.h"


class BaseObj
{
protected:

	std::string name;

	int tag;

	// 自分のレイヤー
	Utils::Layer::Type layer;

	// 現在アンカー
	Utils::Anchor::Type anchor;

	// 表示場所
	int drawOrder;
	// 有効 / 無効 
	bool active;
	// 生 / 死
	bool isDead;
	// 単一のID
	unsigned int objID;

	// スタート前フラグ
	bool started;

	BaseObj(
		std::string _name = "Defaults",
		Utils::Tag::Type _tag = Utils::Tag::Type::Default,
		Utils::Layer::Type _layer = Utils::Layer::Type::Default,
		Utils::Anchor::Type _anchor = Utils::Anchor::Type::S,
		int _drawOrder = 0,
		bool _active = true
	) :
		name(_name),
		tag(Utils::Tag::Tag(_tag)),
		layer(_layer),
		anchor(_anchor),
		drawOrder(_drawOrder),
		active(_active),

		isDead(false),
		objID(0),
		started(false)
	{
	}

public:
	// === 初期化処理系統 ===

	bool& Started() { return started; }

	virtual void Awake() {/* 何もしない */ };
	// 開始時に動く関数
	virtual void Start() {/* 何もしない */ };


	// === 継続処理系統 ===

	virtual void Update() {/* 何もしない */ };
	virtual void Fixed() {/* 何もしない */ };
	virtual void Draw() {/* 何もしない */ };

	int GetDrawOrder() { return drawOrder; }
	unsigned int GetObjID() { return objID; }

	// 名前を返す
	std::string& Name() { return name; }

	// 有効 / 無効 を返す
	bool& Active() { return active; }

	// 個別ID類
	void InitID(unsigned int _objID) { objID = _objID; };

	// オブジェクト削除類
	void Kill() { isDead = true; };
	bool IsDead() const { return isDead; }

};
