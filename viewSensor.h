#pragma once

#include "sensor.h"

class ViewSensor : public Sensor{
public:
	ViewSensor(class Scene* scene, D3DXVECTOR3 pos, float length, float radius, int drawPriority);

	void Init() override {}
	void Uninit() override;
	void Update() override {};
	void Draw() override {};

	void SetRange(float range);
	void SetLength(float length);
	void SetRotationForward(D3DXVECTOR3 forward, bool rev);
	void SetSensorPosition(D3DXVECTOR3 pos);
	void SetInfo(D3DXVECTOR3 pos, D3DXVECTOR3 forw, float ran, float len, bool dis, bool rev = false);
	void SetDisplay(bool dis);

	bool WithinRange(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 forward, D3DXVECTOR3 size);

private:
	void SetVertex();

private:
	class Polygon3D* m_OutLookUI = nullptr;
	float m_Range;
	float m_Length;
};