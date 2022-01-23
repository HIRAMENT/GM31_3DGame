#pragma once

#include "gameObject.h"
#include "counter.h"
#include <list>

enum class ProductionType
{
	Point,
	Region,
};

class ParticleInfo
{
public:
	ParticleInfo() {}
	~ParticleInfo() {}

	D3DXVECTOR3 m_Position;
	ResourceTag m_TextureTag;
	int m_DrawPriority;

	// 2D���ǂ���
	bool m_is2Dimension;
	// �r���{�[�h���ǂ���
	bool m_isBillboard;
	// �p�x
	int m_AngleMax;
	int m_AngleMin;
	// ���x
	float m_SpeedMax;
	float m_SpeedMin;
	// ��������
	float m_LifeSpanMax;
	float m_LifeSpanMin;
	// �傫��
	float m_ScaleMax;
	float m_ScaleMin;
	// ������
	int m_ProductionMax;
	int m_ProductionMin;
	// ��]���x
	float m_RotationMax;
	float m_RotationMin;
	// �F
	float m_RedMax;
	float m_RedMin;
	float m_GreenMax;
	float m_GreenMin;
	float m_BlueMax;
	float m_BlueMin;
	float m_AlphaMax;
	float m_AlphaMin;
	// �d��
	bool m_GravityUse;
	D3DXVECTOR3 m_Gravity;
	// �����̎��
	BlendMode m_BlendMode;
	// �����Ԋu
	bool m_ProductionOnes;	// ��x���肩�ǂ���
	float m_ProductionInterval;
	// �J�[�u���邩�ǂ���
	bool m_isCurve;
	float m_CurveRateMax;
	float m_CurveRateMin;
	// �����̎��
	ProductionType m_ProductionType;
	D3DXVECTOR3 m_ProductionPosMax;
	D3DXVECTOR3 m_ProductionPosMin;
};

class ParticleManager : public GameObject{
public:
	ParticleManager(class Scene* scene, ParticleInfo* info);
	virtual ~ParticleManager() {}

	void Init() override {}
	void Uninit() override;
	void Update() override;
	void Draw() override {}

	void CreateParticle();

private:
	//std::list<class Particle*> m_Particles;
	ParticleInfo m_ParticleInfo;
	Counter m_ProductionInterval;
	bool m_ProductionOnes;	// ��x���肩�ǂ���
	bool m_isProduction;	// �����������ǂ���
};

