#pragma once
#include <d3dx9.h>

namespace Vec3
{
	static const D3DXVECTOR3 Zero(0, 0, 0);
	static const D3DXVECTOR3 Up(0, 1, 0);
	static const D3DXVECTOR3 Forward(0, 0, 1);
	static const D3DXVECTOR3 Right(1, 0, 0);

	float Length(const D3DXVECTOR3& v);		// ベクトルの長さの取得 (取得用)
	float LengthSq(const D3DXVECTOR3& v);	// ベクトルの長さの取得 (比較用)
	float Distance(const D3DXVECTOR3& origin, const D3DXVECTOR3& dest);		// 2つのオブジェクトの間隔の取得 (取得用)
	float DistanceSq(const D3DXVECTOR3& origin, const D3DXVECTOR3& dest);	// 2つのオブジェクトの間隔の取得 (比較用)

	D3DXVECTOR3 Cross(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);	// 外積
	float Dot(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);		// 内積
	D3DXVECTOR3 PlaneNormal(const D3DXVECTOR3 v[3]);				// 法線
}

D3DXVECTOR3 operator*(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);