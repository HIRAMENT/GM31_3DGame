#pragma once
#include "singleton.h"

class Information : public Singleton<Information>{
public:
	friend class Singleton<Information>;

private:
	float m_Fps;
	float m_Memory;
	float m_Cpu;

private:
	float GetFPS() const;
	float GetMemory() const;
	float GetCPU() const;

public:
	void Display();

protected:
	Information() {}
	virtual ~Information() {}
};