#pragma once

class ExperiencePoint
{
private:
	int m_EXP;

public:
	ExperiencePoint(const int exp) : m_EXP(exp){}

	int GetEXP() const { return m_EXP; }
	void SetEXP(const int exp) { m_EXP = exp; }
	void AddEXP(const int exp) { m_EXP += exp; }

};