#pragma once
#include "singleton.h"

class Calculation : public Singleton<Calculation>
{
public:
	friend class Singleton<Calculation>;
	int ExtractDigit(int num, int digit);
	float RoundTrip(float now, float value, D3DXVECTOR2 limit);
	float RandomRange(float min, float max);
	int GetSign(int num) { return 1 - (num <= 0) - (num < 0); };
	int RandomSign();

protected:
	Calculation() {}
	virtual ~Calculation() {}
};