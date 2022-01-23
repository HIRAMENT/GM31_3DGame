#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "scene.h"
#include "gauge.h"
#include "hitPoint.h"
#include "number.h"
#include "calculation.h"

#define COOLTIME (36.0f);

HitPoint::HitPoint(class Scene* scene, int hp)
	: m_HitPoint(hp)
	, m_HitPointMax(hp)
{
	m_CoolTimeCounter = COOLTIME;
	m_CoolTimeCounter -= COOLTIME;
}

void HitPoint::Damage(int dam)
{
	m_HitPoint -= dam;
	m_HitPointGauge->DegCapacity(dam);
	m_CoolTimeCounter.Reset();
}

void HitPoint::Recover(int rec)
{
	m_HitPoint += rec;
	m_HitPointGauge->AddCapacity(rec);
}

void HitPoint::Update()
{
	m_CoolTimeCounter -= 1.0f;
}

void HitPoint::Uninit()
{
	m_HitPointGauge->SetDestroy();
}

bool HitPoint::CheckCollTime()
{
	return m_CoolTimeCounter.GetIsFinish();
}



HitPoint2D::HitPoint2D(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp)
	: HitPoint(scene, hp)
{
	m_HitPointGauge = new Gauge(scene, { pos.x, pos.y }, { size.x, size.y }, m_HitPointMax, 100);
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i] = new Number(scene, { (float)SCREEN_WIDTH / 2 - (16 * (i + 1)),            (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1), 110);
		m_HitPointNumber[i]->SetDisplay(true);
		m_HitPointNumberMax[i] = new Number(scene, { (float)SCREEN_WIDTH / 2 + (16 * 5) - (16 * (i + 1)), (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HitPointMax, i + 1), 110);
		m_HitPointNumberMax[i]->SetDisplay(true);
	}
	m_HitPointSlash = new Number(scene, { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 64 ,0 }, { 24, 24, 0 }, 12, 110);
	m_HitPointSlash->SetDisplay(true);
}

void HitPoint2D::SetNumberDisplay(const bool dis)
{
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->SetDisplay(dis);
		m_HitPointNumberMax[i]->SetDisplay(dis);
	}
	m_HitPointSlash->SetDisplay(dis);
}

void HitPoint2D::Damage(int dam)
{
	HitPoint::Damage(dam);
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->ChangeNumber(Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1));
	}
}

void HitPoint2D::Recover(int rec)
{
	HitPoint::Recover(rec);
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->ChangeNumber(Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1));
	}
}

void HitPoint2D::Uninit()
{
	HitPoint::Uninit();
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->SetDestroy();
		m_HitPointNumberMax[i]->SetDestroy();
	}
	m_HitPointSlash->SetDestroy();
}



HitPoint3D::HitPoint3D(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp)
	: HitPoint(scene, hp)
{
	m_HitPointGauge = new Gauge(scene, pos, size, m_HitPointMax, 5);
}