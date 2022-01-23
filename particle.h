#pragma once

#include "gameObject.h"
#include "counter.h"
#include "movement.h"

class Scene;
class ParticleInfo;

class Particle : public GameObject{
public:
	Particle(Scene* scene, ParticleInfo* info);
	Particle(Scene* scene, float angle, float speed,float life, ResourceTag tag, int drawpriority);

	virtual void Init() override {}
	virtual void Uninit() override {}
	virtual void Update() override {}
	virtual void Draw() override {}

protected:
	ParticleInfo* m_Info;
	float m_Angle;
	float m_Speed;
	Counter m_LifeSpan;
	float m_Size;
	float m_RedRate;
	float m_GreenRate;
	float m_BlueRate;
	float m_AlphaRate;
	float m_RotationRate;
	BlendMode m_BlendMode;
	BezierCurveInfo m_CurveInfo;
	D3DXVECTOR3 m_CurvePosition;
};

class Particle2D : public Particle {
public:
	Particle2D(Scene* scene, ParticleInfo* info);

	void Uninit() override;
	void Update() override;

private:
	class Polygon2D* m_Sprite;
	D3DXVECTOR2 m_BasePosition;
	D3DXVECTOR2 m_Velocity;
	D3DXVECTOR2 m_Gravity;
};

class Particle3D : public Particle {
public:
	Particle3D(Scene* scene, ParticleInfo* info);

	void Uninit() override;
	void Update() override;

private:
	class Polygon3D* m_SpriteFront;
	class Polygon3D* m_SpriteBack;
	D3DXVECTOR3 m_BasePosition;
	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_Gravity;
};