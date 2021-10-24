#pragma once
#include "scene.h"

class TutorialScene : public Scene
{
private:
	class Polygon2D* m_BG = nullptr;

public:
	static unsigned int m_tBGMID;

public:
	void Init() override;
	void Update() override;
	void Uninit() override;

	static void SetBGMID(unsigned int id) { m_tBGMID = id; }
};