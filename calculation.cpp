#include "main.h"
#include "calculation.h"

int Calculation::ExtractDigit(int num, int digit)
{
	int division = powf(10, (digit - 1));
	if (division == 0) division = 1;
	int number = num / division % 10;
	return number;
}

float Calculation::RoundTrip(float now, float value, D3DXVECTOR2 limit)
{
	float num = now;

	if (now <= limit.x)
	{
		num += value;
	}
	else if(now >= limit.y)
	{
		num -= value;
	}
	
	return num;
}

float Calculation::RandomRange(float min, float max)
{
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}
