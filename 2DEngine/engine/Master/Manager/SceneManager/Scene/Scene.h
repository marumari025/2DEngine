// Scene.h
#pragma once

#include "stdafx.h"
#include "BaseObj.h"

class Scene
{
protected:
	Scene() = default;
	// SceneManagerの管理下のみ
	friend class SceneManager;

	// シーン名
	std::string name;

	// 追加オブジェクト
	std::vector<std::unique_ptr<BaseObj>>* objects = nullptr;

	// IDポインタ
	unsigned int* nowID = nullptr;

	// ソート
	void QuickSort3Way(std::vector<std::unique_ptr<BaseObj>>& base, int left, int right);


public:

	// シーン開始時のセットアップよう
	// オブジェクトにidを入れつつ追加
	template<typename T, class... Args> // class... Args どのクラスも全部入る
	BaseObj* CreateObj(Args&&... args) {
		objects->push_back(std::make_unique<T>(std::forward<Args>(args)...));
		objects->back()->InitID((*nowID)++);

		return objects->back().get();
	}

	void SetObjectsAddress(std::vector<std::unique_ptr<BaseObj>>* _objects) {
		objects = _objects;
	}

	void SetNowIDAddress(unsigned int* _nowID) {
		nowID = _nowID;
	}

	// baseにオブジェクト追加したりする
	virtual void ObjSet() {};

	std::string GetName() { return name; }

	// class nameから
	template<typename T>
	void SetName() {
		// "class "が前についたクラス名取得
		std::string _name = typeid(T).name();
		// 削除する文字列
		std::string delTxt = "class ";

		// delTxt分の文字を消す
		for (int i = 0; i < _name.size() - delTxt.size(); i++) {
			name += _name[delTxt.size() + i];
		}
	}
};