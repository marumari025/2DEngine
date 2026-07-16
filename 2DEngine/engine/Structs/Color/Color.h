// StrColor.h
#pragma once

// 色の型
class Color
{
private:
	unsigned int color;

public:
	// コンストラクタ
	explicit Color(int _color, int _alpha = 255)
	{
		SetRGBA(_color, _alpha);
	}

	explicit Color(int _r, int _g, int _b, int _alpha = 255)
	{
		SetRGBA(_r, _g, _b, _alpha);
	}

	// 単色設定
	int GetA()const { return color >> 24 & 0xFF; }
	int GetR()const { return color >> 16 & 0xFF; }
	int GetG()const { return color >> 8 & 0xFF; }
	int GetB()const { return color & 0xFF; }

	// 単色取得
	void SetA(int _a) { color = (color & 0x00FFFFFF) | ((_a & 0xFF) << 24); }
	void SetR(int _r) { color = (color & 0xFF00FFFF) | ((_r & 0xFF) << 16); }
	void SetG(int _g) { color = (color & 0xFFFF00FF) | ((_g & 0xFF) << 8); }
	void SetB(int _b) { color = (color & 0xFFFFFF00) | (_b & 0xFF); }

	// 全色設定(透明度抜き)
	void SetRGB(int _r, int _g, int _b) { color = ((color & 0xFF000000)) | ((_r & 0xFF) << 16) | ((_g & 0xFF) << 8) | (_b & 0xFF); }
	void SetRGB(int _rgb) { color = ((color & 0xFF000000)) | (_rgb & 0xFFFFFF)/*有効範囲内に*/; }

	// 全色設定(透明度付き)
	void SetRGBA(int _r, int _g, int _b, int _a) { color = ((_r & 0xFF) << 16) | ((_g & 0xFF) << 8) | (_b & 0xFF) | ((_a & 0xFF) << 24); }
	void SetRGBA(int _rgb, int _a) { color = (_rgb & 0xFFFFFF) | ((_a & 0xFF) << 24); }

	// 全色取得(透明度抜き)
	unsigned int GetRGB() const { return color & 0xFFFFFF; }
};