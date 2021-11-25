#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "obb.h"

OBB::OBB(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	SetObb(pos, size, rot);
}

D3DXVECTOR3 OBB::GetDirection(int elem) const
{
	return m_Direction[elem];
}

float OBB::GetLength(int elem) const
{
	return m_Length[elem];
}

D3DXVECTOR3 OBB::GetPosition() const
{
	return m_Position;
}

void OBB::SetObb(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	D3DXMATRIX matRot;

	m_Position = pos;

	// 最大値・最小値の設定
	D3DXVECTOR3 min = { pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2 };
	D3DXVECTOR3 max = { pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2 };

	// 方向ベクトルの取得
	D3DXMatrixRotationYawPitchRoll(&matRot, rot.y, rot.x, rot.z);
	m_Direction[0] = D3DXVECTOR3(matRot._11, matRot._12, matRot._13);
	m_Direction[1] = D3DXVECTOR3(matRot._21, matRot._22, matRot._23);
	m_Direction[2] = D3DXVECTOR3(matRot._31, matRot._32, matRot._33);

	// 長さの取得
	m_Length[0] = fabsf(max.x - min.x) * 0.5f;
	m_Length[1] = fabsf(max.y - min.y) * 0.5f;
	m_Length[2] = fabsf(max.z - min.z) * 0.5f;
}

void OBB::BorderDisplay(bool dis)
{

}
