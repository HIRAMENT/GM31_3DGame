#pragma once
#include "obstancle.h"

class Tree : public Obstancle
{
public:
	Tree(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 scale, int drawPriority);

	void Init() override {};
	void Update() override {};
	void Draw() override;
};