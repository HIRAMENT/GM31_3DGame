#include "counter.h"

Counter & Counter::operator+=(float num)
{
	m_Rest += num;

	if (m_Rest >= m_Max) {
		m_Rest = m_Max;
	}

	return *this;
}

Counter & Counter::operator-=(float num)
{
	m_Rest -= num;

	if (m_Rest <= 0.0f) {
		m_isFinish = true;
	}

	return *this;
}

void Counter::Reset()
{
	m_Rest = m_Max;
	m_isFinish = false;
}
