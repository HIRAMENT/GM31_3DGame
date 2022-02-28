#pragma once

//#include "scene.h"
#include "transform.h"

enum class ObjectType {
	eObNone,
	eObPlayer,
	eObEnemy,
	eObSmallEnemy,
	eObBossEnemy,
	eObBullet,
	eObCamera,
	eObPolygon2D,
	eObPolygon3D,
	eObField,
	eObExplosion,
	eObSkydome,
	eObSword,
	eObShadow,
	eObRock,
	eObSensor,
	eObBillboard,
	eObGauge,
	eObNumber,
	eObButton,
	eObTree,
	eObStatus,
	eObTargetMark,
	eObParticle,
	eObBox, 
	eObDebugCamera,
	eObObstancle,
};


class GameObject
{
private:
	int m_DrawPriority;
	class Scene* m_Scene;

protected:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;

	D3DXVECTOR3 m_Forward;

	D3DXMATRIX m_World;

	ObjectType m_Type;
	bool m_Destroy = false;

public:
	GameObject(Scene* scene, ObjectType type,int drawPriority) : m_Scene(scene), m_Type(type), m_DrawPriority(drawPriority){}
	virtual ~GameObject() {}

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetPosition(D3DXVECTOR3 pos) { m_Position = pos; }
	void SetRotation(D3DXVECTOR3 rot) { m_Rotation = rot; }
	void SetScale   (D3DXVECTOR3 scl) { m_Scale = scl; }
	void SetScale   (float mag)       { m_Scale = { mag,mag,mag }; }

	D3DXVECTOR3 GetPosition(void) { return m_Position; }
	D3DXVECTOR3 GetRotation(void) { return m_Rotation; }
	D3DXVECTOR3 GetScale(void)    { return m_Scale; }
	Scene* GetScene() const { return m_Scene; }
	ObjectType GetObjectType() const { return m_Type; }
	D3DXMATRIX GetWorldMatrix() { return m_World; }
	int GetDrawPriority() const { return m_DrawPriority; }

	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}

	D3DXVECTOR3 GetRight()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 right;
		right.x = rot._11;
		right.y = rot._12;
		right.z = rot._13;

		return right;
	}

	D3DXVECTOR3 GetUp()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 up;
		up.x = rot._21;
		up.y = rot._22;
		up.z = rot._23;

		return up;
	}

	void SetDestroy() { m_Destroy = true; }
	void SetDestroy(GameObject* object) { object->SetDestroy(); }
	bool GetDestroy() const { return m_Destroy; }
	void ResetDestroy() { m_Destroy = false; }
	bool Destroy()
	{
		if (m_Destroy)
		{
			Uninit();
			delete this;
			return true;
		}
		else
		{
			return false;
		}
	}
};