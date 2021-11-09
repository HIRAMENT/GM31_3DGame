#pragma once
#include "singleton.h"

class MyImGui : public Singleton<MyImGui>
{
	friend class Singleton<MyImGui>;

public:
	void Init();
	void UpdateStart();
	void UpdateEnd();
	void Draw();
	void Uninit();

protected:
	virtual ~MyImGui() {}
};