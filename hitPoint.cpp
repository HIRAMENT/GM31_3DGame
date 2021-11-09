#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "scene.h"
#include "gauge.h"
#include "hitPoint.h"
#include "number.h"
#include "calculation.h"

HitPoint::HitPoint(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp, int dim)
{
	m_HitPoint = hp;
	m_HitPointMax = hp;
	m_CoolTime = 0;
	m_CoolTimeMax = 100;

	if (dim == 2){
		m_HitPointGauge = new Gauge(scene, { pos.x, pos.y }, { size.x, size.y }, m_HitPointMax, 100);
	}
	else if(dim == 3){
		m_HitPointGauge = new Gauge(scene, pos, size, m_HitPointMax, 50);
	}

	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]    = new Number(scene, { (float)SCREEN_WIDTH / 2 - (16 * (i + 1)),            (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1), 110);
		m_HitPointNumber[i]->SetDisplay(false);
		m_HitPointNumberMax[i] = new Number(scene, { (float)SCREEN_WIDTH / 2 + (16 * 5) - (16 * (i + 1)), (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HitPointMax, i + 1), 110);
		m_HitPointNumberMax[i]->SetDisplay(false);
	}
	m_HitPointSlash = new Number(scene, { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 64 ,0 }, { 24, 24, 0 }, 12, 110);
	m_HitPointSlash->SetDisplay(false);
}

void HitPoint::SetNumberDisplay(const bool dis)
{
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->SetDisplay(dis);
		m_HitPointNumberMax[i]->SetDisplay(dis);
	}
	m_HitPointSlash->SetDisplay(dis);
}

void HitPoint::Damage(int dam)
{
	m_HitPoint -= dam;
	m_HitPointGauge->DegCapacity(dam);
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->ChangeNumber(Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1));
	}
}

void HitPoint::Recover(int rec)
{
	m_HitPoint += rec;
	m_HitPointGauge->AddCapacity(rec);
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->ChangeNumber(Calculation::GetInstance()->ExtractDigit(m_HitPoint, i + 1));
	}
}

void HitPoint::Update()
{
	if (m_CoolTime <= m_CoolTimeMax)
		m_CoolTime++;
}

void HitPoint::Unitit()
{
	m_HitPointGauge->SetDestroy();
	for (int i = 0; i < 4; i++)
	{
		m_HitPointNumber[i]->SetDestroy();
		m_HitPointNumberMax[i]->SetDestroy();
	}
	m_HitPointSlash->SetDestroy();
}

bool HitPoint::CheckCollTime()
{
	if (m_CoolTime >= m_CoolTimeMax)
		return true;

	return false;
}
