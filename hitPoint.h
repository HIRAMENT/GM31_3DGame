#pragma once

class Gauge;
class Number;

class HitPoint
{
public:
	HitPoint(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int hp, int dim);

	int GetHitPoint() const { return m_HitPoint; }
	int GetHitPointMax() const { return m_HitPointMax; }
	Gauge* GetGauge() const { return m_HitPointGauge; }
	bool CheckCollTime();
	void SetHitPoint(const int hp) { m_HitPoint = hp; }
	void SetHitPointMax(const int hp) { m_HitPointMax = hp; }
	void SetCollTimeMax(const int time) { m_CoolTimeMax = time; }

	void SetNumberDisplay(const bool dis);

	void Damage(int dam);
	void Recover(int rec);

	void Update();
	void Unitit();

private:
	int m_HitPoint;
	int m_HitPointMax;
	int m_CoolTime;
	int m_CoolTimeMax;
	Gauge* m_HitPointGauge;
	Number* m_HitPointNumber[4];
	Number* m_HitPointNumberMax[4];
	Number* m_HitPointSlash;
};