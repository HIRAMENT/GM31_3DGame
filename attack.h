#pragma once

class Attack {

public:
	Attack(int pow) :m_Power(pow),m_CoolTime(0) {}

	void Update();

	bool CheckCoolTime();
	bool CheckHit(D3DXVECTOR3 vec, D3DXVECTOR3 forword, float ang, float len);

	int GetPower()const { return m_Power; }
	int GetCoolTime() const { return m_CoolTime; }
	void SetPower(const int pow) { m_Power = pow; }
	void GetCoolTime(const int time) { m_CoolTime = time; }

private:
	int m_Power;
	int m_CoolTime;
};