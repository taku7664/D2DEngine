#pragma once

class ColorF
{
public:
	ColorF(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
		: r(rgba[0]), g(rgba[1]), b(rgba[2]), a(rgba[3]) // 참조 초기화
	{
		rgba[0] = r; rgba[1] = g; rgba[2] = b; rgba[3] = a;
	}
	const float& r;
	const float& g;
	const float& b;
	const float& a;

	UINT32 GetRGB()
	{
		UINT8 r = static_cast<UINT8>(rgba[0] * 255.0f);
		UINT8 g = static_cast<UINT8>(rgba[1] * 255.0f);
		UINT8 b = static_cast<UINT8>(rgba[2] * 255.0f);
		return (r << 16) | (g << 8) | (b);
	}

	operator const float*() const { return rgba; }
	operator const Vector4() const { return Vector4(r, g, b, a); }
	ColorF& operator=(const ColorF& _val)
	{
		rgba[0] = _val.rgba[0];
		rgba[1] = _val.rgba[1];
		rgba[2] = _val.rgba[2];
		rgba[3] = _val.rgba[3];
		return *this;
	}
#ifdef _D2D1_H_
	operator D3DCOLORVALUE()
	{
		return D3DCOLORVALUE(r, g, b, a);
	}
#endif
private:
	float rgba[4];
};