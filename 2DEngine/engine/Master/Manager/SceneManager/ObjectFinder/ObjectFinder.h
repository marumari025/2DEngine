#pragma once

#include "BaseObj.h"

template<typename T>
class ObjectFinder
{
protected:
	// SceneManagerの管理下のみ
	friend class SceneManager;

	// オブジェクト配列のアドレス
	std::vector<std::unique_ptr<BaseObj>>& objects;

	ObjectFinder(std::vector<std::unique_ptr<BaseObj>>& _objects) : objects(_objects) {}

public:

	// 完全一致・単一
	T* First(bool _includeInactive = false) {

		for (auto& obj : objects) {

			// クラスが一致しているか文字列で比べる
			if (typeid(*obj.get()) != typeid(T)) { continue; }

			// アクティブかどうか
			if (!_includeInactive && !obj->Active()) { continue; }

			return static_cast<T*>(obj.get());

		}

		return nullptr;

	}

	// 完全一致・複数
	std::vector<T*> All(bool _includeInactive = false) {

		std::vector<T*> result;

		for (auto& obj : objects) {

			// クラスが一致しているか文字列で比べる
			if (typeid(*obj.get()) != typeid(T)) { continue; }

			// アクティブかどうか
			if (!_includeInactive && !obj->Active()) { continue; }

			result.push_back(static_cast<T*>(obj.get()));
		}

		return result;

	}

	// 継承含む・単一
	T* FirstOfType(bool _includeInactive = false) {

		for (auto& obj : objects) {

			// アクティブかどうか
			if (!_includeInactive && !obj->Active()) { continue; }

			// もしdynamic_castでT*型に変換ができれば返す
			if (T* t = dynamic_cast<T*>(obj.get())) { return t; }

		}

		return nullptr;

	}

	// 継承含む・複数
	std::vector<T*> AllOfType(bool _includeInactive = false) {

		std::vector<T*> result;

		for (auto& obj : objects) {

			if (!_includeInactive && !obj->Active()) { continue; }

			// もしdynamic_castでtにT*型に変換できればresultに入れる
			if (T* t = dynamic_cast<T*>(obj.get())) { result.push_back(t); }

		}

		return result;

	}

	// 名前検索・単一 
	T* FirstOfNamed(const std::string& _name, bool _includeInactive = false) {

		for (auto& obj : objects)
		{
			// アクティブかどうか
			if (!_includeInactive && !obj->Active()) { continue; }

			// もしdynamic_castでtにT*型に変換できれば次に進む
			if (T* t = dynamic_cast<T*>(obj.get())) {

				// 名前が一致するか
				if (obj->Name() == _name) {

					return obj.get();

				}
			}
		}

		return nullptr; // 見つからなかった場合

	}

};