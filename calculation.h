#pragma once
#include "singleton.h"

class Calculation : public Singleton<Calculation>
{
public:
	friend class Singleton<Calculation>;
	int ExtractDigit(int num, int digit);
	float RoundTrip(float now, float value, D3DXVECTOR2 limit);

protected:
	Calculation() {}
	virtual ~Calculation() {}
};