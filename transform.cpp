#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "transform.h"

D3DXVECTOR3 Transform::GetUp() const
{
	return m_Quaternion * Vec3::Up;
}

D3DXVECTOR3 Transform::GetForward() const
{
	return m_Quaternion * Vec3::Forward;
}

D3DXVECTOR3 Transform::GetRight() const
{
	return m_Quaternion * Vec3::Right;
}

void Transform::Rotation(const D3DXVECTOR3 & axis, float deg)
{
	Quaternion qua;
	D3DXQuaternionRotationAxis(&qua, &axis, degToRad(deg));
	m_Quaternion = qua * m_Quaternion;
}

void Transform::SetRotation(const D3DXVECTOR3 & axis, float deg)
{
	D3DXQuaternionRotationAxis(&m_Quaternion, &axis, degToRad(deg));
}

void Transform::Move(const D3DXVECTOR3 & move)
{
	m_Position += move.x * GetRight() + move.y * GetUp() + move.z * GetForward();
}

void Transform::Move(const D3DXVECTOR2 & move)
{
	Move(D3DXVECTOR3(move.x, 0, move.y));
}

void Transform::Translate(const D3DXVECTOR3 & move)
{
	m_Position += move;
}