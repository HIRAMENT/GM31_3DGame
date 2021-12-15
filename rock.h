#pragma once
#include "gameObject.h"

class Rock : public GameObject
{
private:
	class OBB* m_Obb = nullptr;
	class Shadow* m_Shadow = nullptr;

	bool m_Visble;

public:
	Rock(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	OBB* GetObb() const { return m_Obb; }
};