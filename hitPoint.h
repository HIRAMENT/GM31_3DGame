#pragma once

#include "counter.h"

class Gauge;
class Number;

class HitPoint
{
public:
	HitPoint(class Scene* scene, int hp);

	void SetHitPoint(const int hp) { m_HitPoint = hp; }
	void SetHitPointMax(const int hp) { m_HitPointMax = hp; }
	int GetHitPoint() const { return m_HitPoint; }
	int GetHitPointMax() const { return m_HitPointMax; }
	Gauge* GetGauge() const { return m_HitPointGauge; }
	Counter GetCoolTimeCounter() const { return m_CoolTimeCounter; }

	virtual void Damage(int dam);
	virtual void Recover(int rec);
	bool CheckCollTime();

	void Update();
	virtual void Uninit();

protected:
	int m_HitPoint;
	int m_HitPointMax;
	Counter m_CoolTimeCounter;
	Gauge* m_HitPointGauge;
};

class HitPoint2D : public HitPoint {
public:
	HitPoint2D(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp);
	void SetNumberDisplay(const bool dis);

	void Damage(int dam) override;
	void Recover(int rec) override;

	void Uninit() override;

private:
	Number* m_HitPointNumber[4];
	Number* m_HitPointNumberMax[4];
	Number* m_HitPointSlash;

};

class HitPoint3D : public HitPoint {
public:
	HitPoint3D(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp);
};