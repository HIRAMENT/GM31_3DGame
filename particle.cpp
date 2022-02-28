#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "texture.h"
#include "scene.h"
#include "polygon2D.h"
#include "polygon3D.h"
#include "calculation.h"
#include "collision.h"
#include "particleManager.h"
#include "particle.h"
#include "camera.h"
#include <algorithm>

Particle::Particle(Scene * scene, ParticleInfo* info)
	: GameObject(scene, ObjectType::eObParticle, info->m_DrawPriority)
	, m_Info(info)
	, m_LifeSpan(Calculation::GetInstance()->RandomRange(info->m_LifeSpanMin, info->m_LifeSpanMax))
	, m_Speed(Calculation::GetInstance()->RandomRange(info->m_SpeedMin, info->m_SpeedMax))
	, m_Size(Calculation::GetInstance()->RandomRange(info->m_ScaleMin, info->m_ScaleMax))
	, m_Angle(D3DXToRadian(Calculation::GetInstance()->RandomRange(info->m_AngleMin, info->m_AngleMax)))
	, m_RedRate(Calculation::GetInstance()->RandomRange(info->m_RedMin, info->m_RedMax))
	, m_GreenRate(Calculation::GetInstance()->RandomRange(info->m_GreenMin, info->m_GreenMax))
	, m_BlueRate(Calculation::GetInstance()->RandomRange(info->m_BlueMin, info->m_BlueMax))
	, m_AlphaRate(Calculation::GetInstance()->RandomRange(info->m_AlphaMin, info->m_AlphaMax))
	, m_RotationRate(Calculation::GetInstance()->RandomRange(info->m_RotationMin, info->m_RotationMax))
	, m_BlendMode(info->m_BlendMode)
{
}

Particle::Particle(Scene * scene, float angle, float speed, float life, ResourceTag tag, int drawpriority)
	: GameObject(scene, ObjectType::eObParticle, drawpriority)
	, m_Angle(angle)
	, m_Speed(speed)
	, m_LifeSpan(life)
{
}

//----------------------------------------------------------------------------

Particle2D::Particle2D(Scene * scene, ParticleInfo * info)
	: Particle(scene, info)
	, m_BasePosition({info->m_Position.x, info->m_Position.y})
	, m_Velocity({ cosf(m_Angle) * m_Speed, sinf(m_Angle) * m_Speed })
	, m_Gravity(D3DXVECTOR2(0.0f,0.0f))
{
	m_Sprite = new Polygon2D(scene, m_BasePosition, {m_Size, m_Size}, info->m_TextureTag, info->m_DrawPriority);
	m_Sprite->SetColor(m_RedRate, m_GreenRate, m_BlueRate);

	scene->Add(this);
}

void Particle2D::Uninit()
{
	m_Sprite->SetDestroy();
}

void Particle2D::Update()
{
	D3DXVECTOR2 pos = { m_Sprite->GetPosition().x, m_Sprite->GetPosition().y };
	if (m_Info->m_GravityUse) 
	{
		m_Gravity += D3DXVECTOR2(m_Info->m_Gravity.x, m_Info->m_Gravity.y) * 0.01f;
	}
	m_Sprite->SetVertex(pos + m_Velocity + m_Gravity);

	static float rot = 0.0f;
	m_Sprite->SetRotation(D3DXVECTOR3(rot, rot, rot));
	SetRotation(D3DXVECTOR3(rot, rot, rot));
	rot += 0.1f;

	m_LifeSpan -= 0.01f;

	if (!Collision::GetInstance()->BoundingBox2D(pos, m_Sprite->GetSize(), { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f }, {SCREEN_WIDTH, SCREEN_HEIGHT})
		|| m_LifeSpan.GetIsFinish()) 
	{
		SetDestroy();
	}
}

//-------------------------------------------------------------------------------------------

Particle3D::Particle3D(Scene * scene, ParticleInfo * info)
	: Particle(scene, info)
	, m_BasePosition(info->m_Position)
	, m_Gravity(D3DXVECTOR3(0.0f, 0.0f, 0.0f))

{
	int indec = 1;
	int ran = rand() % 2;
	if (ran == 0)indec *= -1;
	m_Velocity = D3DXVECTOR3(cosf(m_Angle) * m_Speed, sinf(m_Angle) * m_Speed, cosf(m_Angle) * indec * m_Speed);

	if (info->m_ProductionType == ProductionType::Region)
	{
		D3DXVECTOR3 amount;
		amount.x = Calculation::GetInstance()->RandomRange(info->m_ProductionPosMin.x, info->m_ProductionPosMax.x);
		amount.y = Calculation::GetInstance()->RandomRange(info->m_ProductionPosMin.y, info->m_ProductionPosMax.y);
		amount.z = Calculation::GetInstance()->RandomRange(info->m_ProductionPosMin.z, info->m_ProductionPosMax.z);
		m_BasePosition = m_BasePosition + amount;
	}

	m_SpriteFront = new Polygon3D(scene, m_BasePosition, D3DXVECTOR3(m_Size, m_Size, 0.0f), info->m_TextureTag, true, info->m_isBillboard, info->m_DrawPriority);
	m_SpriteFront->SetColor(m_RedRate, m_GreenRate, m_BlueRate);
	m_SpriteFront->SetAlpha(m_AlphaRate);
	m_SpriteFront->SetBlendMode(m_BlendMode);
	m_SpriteFront->SetShaderType(ShaderType::UNLIT);

	if (info->m_isCurve)
	{
		float curverate = Calculation::GetInstance()->RandomRange(info->m_CurveRateMin, info->m_CurveRateMax);
		m_CurveInfo.ControlPoint[0] = m_BasePosition;
		m_CurveInfo.ControlPoint[3] = m_BasePosition + m_Velocity * (m_LifeSpan.GetMax() * 100);
		D3DXVECTOR3 right, left, half, top;
		half = (m_CurveInfo.ControlPoint[0] + m_CurveInfo.ControlPoint[3]) * 0.5f;
		top = m_CurveInfo.ControlPoint[3] - half;
		right = { top.y * curverate, -top.x * curverate, 0.0f };
		left =  {-top.y * curverate,  top.x * curverate, 0.0f };
		m_CurveInfo.ControlPoint[1] = half + left;
		m_CurveInfo.ControlPoint[2] = half + right;
	}

	scene->Add(this);
}

void Particle3D::Uninit()
{
	m_SpriteFront->SetDestroy();
}

void Particle3D::Update()
{
	// 重力処理
	if (m_Info->m_GravityUse)
	{
		m_Gravity += m_Info->m_Gravity;
	}

	// カーブ処理
	if (m_Info->m_isCurve)
	{
		m_CurveInfo.Time += (1.0f / m_LifeSpan.GetMax()) * 0.01f;
		m_CurvePosition =  Movement::GetInstance()->BezierCurve(m_CurveInfo);
		m_SpriteFront->SetPosition(m_CurvePosition);
	}
	else
	{
		m_SpriteFront->SetPosition(m_SpriteFront->GetPosition() + m_Velocity - m_Gravity);
	}

	// 回転
	D3DXVECTOR3 rot = { m_SpriteFront->GetRotation().x + m_RotationRate, m_SpriteFront->GetRotation().y + m_RotationRate, m_SpriteFront->GetRotation().z + m_RotationRate};
	m_SpriteFront->SetRotation(D3DXVECTOR3(rot));

	// 寿命を削る
	m_LifeSpan -= 0.01f;

	// 徐々に薄くなる
	if ((m_LifeSpan.GetMax() * 0.2f) * m_AlphaRate >= m_LifeSpan.GetRest())
	{
		m_SpriteFront->SetAlpha(m_LifeSpan.GetRest() / (m_LifeSpan.GetMax() * 0.2f));
	}

	if (m_LifeSpan.GetIsFinish()) 
	{
		SetDestroy();
	}
}
