#pragma once

#include "counter.h"

class Attack {

public:
	Attack(int pow,float time);

	void Update();

	bool CheckCoolTime();
	bool CheckHit(D3DXVECTOR3 vec, D3DXVECTOR3 forword, float ang, float len);

	int GetPower()const { return m_Power; }
	Counter GetCoolTime() const { return m_CoolTime; }
	void SetPower(const int pow) { m_Power = pow; }
	void SetCoolTime(float time) { m_CoolTime = time; }

private:
	int m_Power;
	Counter m_CoolTime;
};