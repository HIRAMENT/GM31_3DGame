#pragma once
#include "gameObject.h"

class tree : public GameObject
{
private:
	class Billboard* m_TreeUI = nullptr;
	class Shadow* m_Shadow = nullptr;

public:
	tree(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 scale, int drawPriority);

	void Init() override {};
	void Uninit() override {};
	void Update() override {};
	void Draw() override {};
};