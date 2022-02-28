#pragma once
#include "obstancle.h"

class Rock : public Obstancle
{
public:
	Rock(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int drawPriority);

	void Init() override {};
	void Update() override;
	void Draw() override;
};