#include "vector3.h"

D3DXVECTOR3 operator*(const D3DXVECTOR3 & v1, const D3DXVECTOR3 & v2)
{
	return D3DXVECTOR3(v1.x *v2.x, v1.y *v2.y, v1.z *v2.z);
}

float Vec3::Length(const D3DXVECTOR3 & v)
{
	return D3DXVec3Length(&v);
}

float Vec3::LengthSq(const D3DXVECTOR3 & v)
{
	return D3DXVec3LengthSq(&v);	// 距離の比較だけならこっちの方が早い　(√を使わないから戻り値は正規ではない)
}

float Vec3::Distance(const D3DXVECTOR3 & origin, const D3DXVECTOR3 & dest)
{
	return Length(dest - origin);
}

float Vec3::DistanceSq(const D3DXVECTOR3 & origin, const D3DXVECTOR3 & dest)
{
	return LengthSq(dest - origin);
}

D3DXVECTOR3 Vec3::Cross(const D3DXVECTOR3 & v1, const D3DXVECTOR3 & v2)
{
	static D3DXVECTOR3 result;
	D3DXVec3Cross(&result, &v1, &v2);	// 外積の計算
	return result;
}

float Vec3::Dot(const D3DXVECTOR3 & v1, const D3DXVECTOR3 & v2)
{
	return D3DXVec3Dot(&v1, &v2);		// 内積の計算
}

D3DXVECTOR3 Vec3::PlaneNormal(const D3DXVECTOR3 v[3])
{
	D3DXVECTOR3 v1 = v[1] - v[0];
	D3DXVECTOR3 v2 = v[2] - v[0];
	return Cross(v1, v2);
}
