#include "main.h"
#include "renderer.h"
#include "resource.h"
#include "polygon3D.h"
#include "obb.h"
#include "scene.h"
#include "box.h"

Box::Box(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, int drawPriority)
	: GameObject(scene, ObjectType::eObBox, drawPriority)
{
	D3DXVECTOR3 halfLen(size.x / 2, size.y / 2, size.z / 2);
	// �E��
	m_Face[0] = new Polygon3D(scene, { pos.x + halfLen.x, pos.y, pos.z }, { 0.0f, size.y, size.z }, ResourceTag::tDebugLine, true, false, drawPriority);
	// ����
	m_Face[1] = new Polygon3D(scene, { pos.x - halfLen.x, pos.y, pos.z }, { 0.0f, -size.y, -size.z }, ResourceTag::tDebugLine, true, false, drawPriority);
	// ���
	m_Face[2] = new Polygon3D(scene, { pos.x, pos.y + halfLen.y, pos.z }, { size.x, 0.0f, size.z }, ResourceTag::tDebugLine, true, false, drawPriority);
	// ����
	m_Face[3] = new Polygon3D(scene, { pos.x, pos.y - halfLen.y, pos.z }, { -size.x, 0.0f, -size.z }, ResourceTag::tDebugLine, true, false, drawPriority);
	// ��� 
	m_Face[4] = new Polygon3D(scene, { pos.x, pos.y, pos.z + halfLen.z }, { -size.x, -size.y, 0.0f }, ResourceTag::tDebugLine, true, false, drawPriority);
	// �O��
	m_Face[5] = new Polygon3D(scene, { pos.x, pos.y, pos.z - halfLen.z }, {  size.x, size.y, 0.0f }, ResourceTag::tDebugLine, true, false, drawPriority);

	scene->Add(this);
}

void Box::Init()
{
}

void Box::Uninit()
{
	for (int i = 0; i < 6; i++)
	{
		m_Face[i]->SetDestroy();
	}
}

void Box::Update()
{
}

void Box::Draw()
{
}

void Box::SetDisplay(bool disp)
{
	for (int i = 0; i < 6; i++)
	{
		m_Face[i]->SetDisplay(disp);
	}
}

void Box::SetInfo(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot)
{
	D3DXMATRIX matRot;
	D3DXVECTOR3 direction[3];
	D3DXMatrixRotationYawPitchRoll(&matRot, rot.y, rot.x, rot.z);
	direction[Direction::eRight]   = D3DXVECTOR3(matRot._11, matRot._12, matRot._13);
	direction[Direction::eUp]      = D3DXVECTOR3(matRot._21, matRot._22, matRot._23);
	direction[Direction::eForward] = D3DXVECTOR3(matRot._31, matRot._32, matRot._33);

	D3DXVECTOR3 adjust = direction[Direction::eRight] * adj.x + direction[Direction::eUp] * adj.y + direction[Direction::eForward] * adj.z;
	D3DXVECTOR3 halfLen(size.x / 2, size.y / 2, size.z / 2);

	// xyz��rightUpForward��R�t���Ĉړ�
	// ���s�ړ��s��𑫂��Ƃ��ł��s���邩��
	m_Face[0]->SetPosition(pos + direction[Direction::eRight]   * halfLen.x + adjust);
	m_Face[1]->SetPosition(pos - direction[Direction::eRight]   * halfLen.x + adjust);
	m_Face[2]->SetPosition(pos + direction[Direction::eUp]      * halfLen.y + adjust);
	m_Face[3]->SetPosition(pos - direction[Direction::eUp]      * halfLen.y + adjust);
	m_Face[4]->SetPosition(pos + direction[Direction::eForward] * halfLen.z + adjust);
	m_Face[5]->SetPosition(pos - direction[Direction::eForward] * halfLen.z + adjust);

	for (int i = 0; i < 6; i++)
	{
		m_Face[i]->SetRotation(rot);
	}
}

void Box::SetTexture(ResourceTag tag)
{
	for (int i = 0; i < 6; i++)
	{
		m_Face[i]->SetTextureTag(tag);
	}
}
