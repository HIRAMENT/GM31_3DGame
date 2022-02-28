#pragma once

#include "camera.h"

class DebugCamera : public Camera {
public:
	DebugCamera(class Scene* scene, D3DXVECTOR3 pos, int drawpriority);

	void Update() override;
	void Draw() override;

	void SetUse(bool use) { m_isUse = use; }
	void CreateParticle();

private:
	class Player* m_Player;
	const float m_Distance = 15;
	bool m_isUse;
	class ParticleManager* m_PManager;
};