#pragma once

#include "gameObject.h"

class Obstancle : public GameObject
{
public:
	Obstancle(class Scene* scene, int drawPriority);

	virtual void Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	class OBB* GetObb() const { return m_Obb; }

protected:
	OBB* m_Obb = nullptr;
	class Shadow* m_Shadow = nullptr;

	D3DXVECTOR3 m_Size;
	D3DXVECTOR3 m_Adjust;
	bool m_Visble;
};