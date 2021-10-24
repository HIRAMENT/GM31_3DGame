#pragma once
#include "gameObject.h"

class Number : public GameObject
{
private:
	class Polygon2D* m_NumberUI = nullptr;

public:
	Number(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int number, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeNumber(int num);
};