#pragma once
#include "scene.h"

class GameScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Uninit() override;

	void SetGameOver() { m_GameOver = true; }

private:
	bool m_GameOver;
	unsigned int m_BGMID;
	int m_PhaseCount;
};