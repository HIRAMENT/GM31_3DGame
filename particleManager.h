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

	// 2Dかどうか
	bool m_is2Dimension;
	// ビルボードかどうか
	bool m_isBillboard;
	// 角度
	int m_AngleMax;
	int m_AngleMin;
	// 速度
	float m_SpeedMax;
	float m_SpeedMin;
	// 生存時間
	float m_LifeSpanMax;
	float m_LifeSpanMin;
	// 大きさ
	float m_ScaleMax;
	float m_ScaleMin;
	// 生成量
	int m_ProductionMax;
	int m_ProductionMin;
	// 回転速度
	float m_RotationMax;
	float m_RotationMin;
	// 色
	float m_RedMax;
	float m_RedMin;
	float m_GreenMax;
	float m_GreenMin;
	float m_BlueMax;
	float m_BlueMin;
	float m_AlphaMax;
	float m_AlphaMin;
	// 重力
	bool m_GravityUse;
	D3DXVECTOR3 m_Gravity;
	// 合成の種類
	BlendMode m_BlendMode;
	// 生成間隔
	bool m_ProductionOnes;	// 一度きりかどうか
	float m_ProductionInterval;
	// カーブするかどうか
	bool m_isCurve;
	float m_CurveRateMax;
	float m_CurveRateMin;
	// 生成の種類
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
	bool m_ProductionOnes;	// 一度きりかどうか
	bool m_isProduction;	// 生成したかどうか
};

