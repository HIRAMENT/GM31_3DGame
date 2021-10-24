#pragma once

#include "gameObject.h"

class Gauge : public GameObject
{
private:
	class Billboard* m_BGaugeUI;
	Billboard* m_BGaugeFrameUI;
	Billboard* m_BGaugeDecUI;
	class Polygon2D* m_PGaugeUI;
	Polygon2D* m_PGaugeFrameUI;
	Polygon2D* m_PGaugeDecUI;
	int m_MaxCapacity;
	int m_DiffCapacity;
	int m_Capacity;

	const D3DXVECTOR3 m_Aspect;
	D3DXVECTOR3 m_Size;
	D3DXVECTOR3 m_Adjust;

public:
	Gauge(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 adjust, int capa, int drawPriority);
	Gauge(Scene * scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, int capa, int drawPriority);

	void Init() override {}
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetGaugePos(D3DXVECTOR3 pos);
	void SetCapacity(int capa);
	void DegCapacity(int deg);
	void AddCapacity(int add);
	void ChangeColor(float r, float g, float b);
	void SetDisplay(bool display);
};