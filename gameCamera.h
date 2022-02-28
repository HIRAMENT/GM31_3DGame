#pragma once

#include "camera.h"

class GameCamera : public Camera {
public:
	GameCamera(class Scene* scene, D3DXVECTOR3 pos, int drawpriority);

	void Update() override;
	void Draw() override;

	void SetUse(bool use) { m_isUse = use; }

private:
	D3DXVECTOR2 m_Angle3D;
	class TargetMark* m_TargetMarker;
	class Player* m_Player;
	const float m_Distance = 15;
	bool m_isUse;
};