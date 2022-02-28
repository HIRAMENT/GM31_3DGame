#pragma once

#include "gameObject.h"

enum class ResourceTag;

class Box : public GameObject
{
public:
	Box(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, int drawPriority);
	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetDisplay(bool disp);
	void SetInfo(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot);
	void SetTexture(ResourceTag tag);

private:
	class Polygon3D* m_Face[6];
};