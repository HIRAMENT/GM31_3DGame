#pragma once
#include <d3dx9.h>

// êÆêîî≈
class Rect
{
public:
	Rect() : Rect(0, 0) {}
	Rect(int x, int y) : x(x), y(y) {}
	Rect(const D3DXVECTOR2& v) : x((int)v.x), y((int)v.y) {}
	D3DXVECTOR2 ToVector2() { return D3DXVECTOR2(x, y); }
	int x;
	int y;
};

namespace Vec2
{
	static const D3DXVECTOR2 Zero(0, 0);
}
D3DXVECTOR2 operator*(const D3DXVECTOR2 & v1, const D3DXVECTOR2 & v2);