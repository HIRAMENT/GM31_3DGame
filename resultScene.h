#pragma once
#include "scene.h"

class ResultScene : public Scene
{
private:
	class Polygon2D* m_BG = nullptr;
	Polygon2D* m_PressSpace = nullptr;
	Polygon2D* m_TitleName = nullptr;
	class Button* m_ReturnButton = nullptr;
	Button* m_ExitButton = nullptr;

	int m_Select;
	const int m_SelectMax = 2;
	static bool m_Clear;
	unsigned int m_BGMID;

public:
	void Init() override;
	void Update() override;
	void Uninit() override;

	static void SetClear(bool clear) { m_Clear = clear; }
};