#pragma once

#include "gameObject.h"

class TargetMark : public GameObject{
public:
	TargetMark(Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, int drawPriority);

	void Init() override {}
	void Update() override {}
	void Draw() override {}
	void Uninit() override;

	Billboard* GetMarker() const { return m_Marker; }

private:
	class Billboard* m_Marker;
};