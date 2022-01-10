#pragma once

#include "camera.h"

class TitleCamera : public Camera {
public:
	TitleCamera(class Scene* scene, D3DXVECTOR3 pos, int drawpriority);

	void Init() override {}
	void Uninit() override {}
	void Update() override {}
};