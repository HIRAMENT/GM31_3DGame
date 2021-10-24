#pragma once
#include <d3dx9.h>

namespace Vec3
{
	static const D3DXVECTOR3 Zero(0, 0, 0);
	static const D3DXVECTOR3 Up(0, 1, 0);
	static const D3DXVECTOR3 Forward(0, 0, 1);
	static const D3DXVECTOR3 Right(1, 0, 0);

	float Length(const D3DXVECTOR3& v);		// �x�N�g���̒����̎擾 (�擾�p)
	float LengthSq(const D3DXVECTOR3& v);	// �x�N�g���̒����̎擾 (��r�p)
	float Distance(const D3DXVECTOR3& origin, const D3DXVECTOR3& dest);		// 2�̃I�u�W�F�N�g�̊Ԋu�̎擾 (�擾�p)
	float DistanceSq(const D3DXVECTOR3& origin, const D3DXVECTOR3& dest);	// 2�̃I�u�W�F�N�g�̊Ԋu�̎擾 (��r�p)

	D3DXVECTOR3 Cross(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);	// �O��
	float Dot(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);		// ����
	D3DXVECTOR3 PlaneNormal(const D3DXVECTOR3 v[3]);				// �@��
}

D3DXVECTOR3 operator*(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2);