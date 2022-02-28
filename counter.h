#pragma once

class Counter {
public:
	Counter() : m_Max(0), m_Rest(0), m_isFinish(false) {}
	Counter(float count) : m_Max(count), m_Rest(count), m_isFinish(false) {}
	virtual ~Counter() {}

	Counter& operator +=(float num);
	Counter& operator -=(float num);

	void Reset();
	void Half() { m_Rest = m_Max / 2; }

	float GetMax() const { return m_Max; }
	float GetRest() const { return m_Rest; }
	bool GetIsFinish() const { return m_isFinish; }
	float GetRatio() const { return (1.0f - (m_Rest / m_Max)); }

private:
	float m_Max;
	float m_Rest;
	bool m_isFinish;
};