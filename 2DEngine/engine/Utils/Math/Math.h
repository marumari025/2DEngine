#pragma once

#include "Structs/Structs.h"
#include "Utils/Utils.h"


namespace Utils::Math
{

	// RectをSideに変換( どのアンカーでもよし )
	Side<float> RectToSide(Rect<float> rect, Utils::Anchor::Type anc = Utils::Anchor::Type::Z);

	// 地点の原点にレクトを合わせる関数
	Rect<float> ToOrigin(Rect<float> rect, Utils::Anchor::Type anc);

	// 地点の原点にレクトを合わせる関数
	Rect<float> FromOrigin(Rect<float> rect, Utils::Anchor::Type anc);

	// _moverSideの重なり量を返す
	Side<float> GetPenetrations(Side<float> _moverSide, Side<float> _staticSide);


	// 角度からラジアン
	float AngleToRadian(float _degree);

	// ラジアンから角度
	float RadianToAngle(float _radian);

	// ラジアンからディレクション
	Vector2<float>RadianToDirection(float _radian);

	// ディレクションからラジアン
	float DirectionToRadian(Vector2<float> _dir);

	// 二つの地点からラジアン
	float LookAtRadian(Vector2<float> _from, Vector2<float> _to);

	// 内積計算
	float DotVector2(Vector2<float> v1, Vector2<float> v2);
	// 外積計算
	float CrossVector2(Vector2<float> v1, Vector2<float> v2);

	// 二乗の計算
	float Square(float value);

	// 二つの地点から距離をとる
	float Distance(Vector2<float> pos1, Vector2<float> pos2);

	// 以下はいろんな方で使うことが多そうなためtemplate

	// min~max内に数値を収める
	template<typename T>
	void Clamp(T* _num, T _min, T _max)
	{
		if (_min > *_num) { *_num = _min; }
		if (*_num > _max) { *_num = _max; }
	}

	// 数の入れ替え これだけいろんな方で使いそうなためtemplate
	template<typename T>
	void Swap(T* _num1, T* _num2)
	{
		T memo = *_num1;
		*_num1 = *_num2;
		*_num2 = memo;
	}

}