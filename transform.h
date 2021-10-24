#pragma once
#include "vector2.h"
#include "vector3.h"
#include "quaternion.h"

class Transform2D
{
public:
	D3DXVECTOR2 position = Vec2::Zero;
	D3DXVECTOR2 size = D3DXVECTOR2(100.0f, 100.0f);
	float rotation = 0;
};

class Transform
{
private:
	D3DXVECTOR3 m_Position = Vec3::Zero;
	D3DXVECTOR3 m_Scale = D3DXVECTOR3(1, 1, 1);
	Quaternion m_Quaternion = Quaternion(0, 0, 0, 1);

public:
	Transform2D ToTransform2D() const {
		D3DXVECTOR3 euler = QuaternionToEuler(m_Quaternion);
		return { D3DXVECTOR2(m_Position.x, m_Position.y), D3DXVECTOR2(m_Scale.x, m_Scale.y), euler.z };
	}
	D3DXVECTOR3 GetUp() const;			// ��̎擾
	D3DXVECTOR3 GetForward() const;		// �O�̎擾
	D3DXVECTOR3 GetRight() const;		// �E�̎擾
	void Rotation(const D3DXVECTOR3& axis, float deg);		// ��](�s��)
	void SetRotation(const D3DXVECTOR3& axis, float deg);	// ��](����)
	void Move(const D3DXVECTOR3& move);						// �ړ�(3D)
	void Move(const D3DXVECTOR2& move);						// �ړ�(2D)
	void Translate(const D3DXVECTOR3& move);				// �ݒu


	void SetPosition(D3DXVECTOR3 pos) { m_Position = pos; }
	void SetScale(D3DXVECTOR3 scale) { m_Scale = scale; }
	void SetQuaternion(Quaternion qua) { m_Quaternion = qua; }

	D3DXVECTOR3 GetPosition() { return m_Position; }
	D3DXVECTOR3 GetScale() { return m_Scale; }
	Quaternion GetQuaternion() { return m_Quaternion; }
};