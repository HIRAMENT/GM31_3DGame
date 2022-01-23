#pragma once
#include "scene.h"
#include "movement.h"

class TitleScene : public Scene
{
private:

	class Polygon3D* m_BG = nullptr;
	Polygon3D* m_TitleName = nullptr;
	class Polygon2D* m_PressSpace = nullptr;
	class Button* m_StartButton = nullptr;
	Button* m_ExitButton = nullptr;

	int m_Select;
	const int m_SelectMax = 2;

	bool m_CursorEnter;

	unsigned int m_BGMID;

	// タイトルのカーブ関連
	BezierCurveInfo m_CurveInfo;
	int m_Reverse;
	float m_CurveRate;
	D3DXVECTOR3 m_Parameter;

public:
	void Init() override;
	void Update() override;
	void Uninit() override;

private:
	void CreateParticle();
	void TitleCurve();
};