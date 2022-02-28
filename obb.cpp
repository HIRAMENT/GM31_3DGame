#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "box.h"
#include "scene.h"
#include "obb.h"

OBB::OBB(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot)
{
	m_DebugBox = new Box(Manager::GetInstance()->GetScene(), pos, size, adj, 5);
	m_DebugBox->SetDisplay(false);
	SetObb(pos, size, adj, rot);
}

OBB::~OBB()
{
	m_DebugBox->SetDestroy();
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

void OBB::SetObb(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot)
{
	D3DXMATRIX matRot;

	m_Position = pos + adj;
	m_DebugBox->SetInfo(pos, size, adj, rot);

	// 最大値・最小値の設定
	D3DXVECTOR3 min = { m_Position.x - size.x / 2, m_Position.y - size.y / 2, m_Position.z - size.z / 2 };
	D3DXVECTOR3 max = { m_Position.x + size.x / 2, m_Position.y + size.y / 2, m_Position.z + size.z / 2 };

	// 方向ベクトルの取得
	D3DXMatrixRotationYawPitchRoll(&matRot, rot.y, rot.x, rot.z);
	m_Direction[Direction::eRight]   = D3DXVECTOR3(matRot._11, matRot._12, matRot._13);
	m_Direction[Direction::eUp]      = D3DXVECTOR3(matRot._21, matRot._22, matRot._23);
	m_Direction[Direction::eForward] = D3DXVECTOR3(matRot._31, matRot._32, matRot._33);

	// 長さの取得
	m_Length[0] = fabsf(max.x - min.x) * 0.5f;
	m_Length[1] = fabsf(max.y - min.y) * 0.5f;
	m_Length[2] = fabsf(max.z - min.z) * 0.5f;

	D3DXVECTOR3 adjust = m_Direction[Direction::eRight] * adj.x + m_Direction[Direction::eUp] * adj.y + m_Direction[Direction::eForward] * adj.z;
	m_Position = pos + adjust;
}