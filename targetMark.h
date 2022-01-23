#pragma once

#include "gameObject.h"

class Player;
class Enemy;
class Camera;
class Polygon3D;


class TargetMark : public GameObject{
public:
	TargetMark(Scene* scene, Camera* camera, int drawPriority);

	void Init() override {}
	void Update() override;
	void Draw() override {}
	void Uninit() override;

	void SetTarget(Enemy* eneym);
	Polygon3D* GetMarkerUI() const { return m_MarkerUI; }
	Enemy* GetTargetObj() const { return m_Target; }

	bool isSetingTarget() { return m_Target != nullptr; }
	void ResetTarget();

private:
	Polygon3D* m_MarkerUI;
	Enemy* m_Target;
	Camera* m_Camera;
};