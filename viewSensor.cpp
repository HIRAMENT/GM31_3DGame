#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "shader.h"
#include "scene.h"
#include "resource.h"
#include "texture.h"
#include "sensor.h"
#include "polygon3D.h"
#include "movement.h"
#include "viewSensor.h"

ViewSensor::ViewSensor(Scene * scene, D3DXVECTOR3 pos, float length, float radius, int drawPriority)
	: Sensor(scene, pos, drawPriority)
{
	m_OutLookUI = new Polygon3D(scene, pos, { 1.0f,0.0f,1.0f }, ResourceTag::tDebugSensor, true, false, 5);
	SetRange(radius);
	SetLength(length);

	scene->Add(this);
}

void ViewSensor::Uninit()
{
	m_OutLookUI->SetDestroy();
}

void ViewSensor::SetRange(float range)
{
	if (m_Range == range)
		return;

	m_Range = range;
	SetVertex();
}

void ViewSensor::SetLength(float length)
{
	if (m_Length == length)
		return;

	m_Length = length;
	SetVertex();
}

void ViewSensor::SetRotationForward(D3DXVECTOR3 forward, bool rev)
{
	float opangle = Movement::GetInstance()->GetTwoVecAngle({ Vec3::Forward.x, Vec3::Forward.z}, {forward.x, forward.z});
	if (rev && -forward.x < 0.0f) 
	{
		opangle *= -1;
	}
	else if(forward.x < 0.0f)
	{
		 opangle *= -1;
	}

	m_Rotation = { 0.0f,opangle,0.0f };
	m_OutLookUI->SetRotation({ 0.0f,opangle,0.0f });
}

void ViewSensor::SetVertex()
{
	float rad = (m_Range * 3.14159f / 180.0f);
	m_OutLookUI->SetVertex(
		{ -std::sinf(rad) * m_Length, 1.0f, std::cosf(rad) * (m_Length + 2) },
		{  std::sinf(rad) * m_Length, 1.0f, std::cosf(rad) * (m_Length + 2) },
		{ -std::sinf(rad) * m_Length, 1.0f, 0.0f },
		{  std::sinf(rad) * m_Length, 1.0f, 0.0f });
}

void ViewSensor::SetSensorPosition(D3DXVECTOR3 pos)
{
	m_Position = pos;
	m_OutLookUI->SetPosition(m_Position);
}

void ViewSensor::SetInfo(D3DXVECTOR3 pos, D3DXVECTOR3 forw, float ran, float len, bool dis, bool rev)
{
	SetSensorPosition(pos);
	SetRotationForward(forw, rev);
	SetRange(ran);
	SetLength(len);
	SetDisplay(dis);
}

void ViewSensor::SetDisplay(bool dis)
{
	m_OutLookUI->SetDisplay(dis);
}

bool ViewSensor::WithinRange(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 forward, D3DXVECTOR3 size)
{
	float angle[5] = {};
	float length[5] = {};
	D3DXVECTOR2 vec[5] = {};
	vec[0] = { pos2.x - pos1.x , pos2.z - pos1.z };
	vec[1] = { (pos2.x + size.x / 2) - pos1.x , pos2.z - pos1.z };
	vec[2] = { (pos2.x - size.x / 2) - pos1.x , pos2.z - pos1.z };
	vec[3] = { pos2.x - pos1.x , (pos2.z + size.z / 2) - pos1.z };
	vec[4] = { pos2.x - pos1.x , (pos2.z - size.z / 2) - pos1.z };

	D3DXVECTOR3 v1, v2, n;
	float dot;
	v1 = forward * 5 - m_Position;
	v2 = D3DXVECTOR3(forward.x, 10, forward.z) * 5 - D3DXVECTOR3(m_Position.x, 10, m_Position.z);
	D3DXVec3Cross(&n, &v1, &v2);

	for (int i = 0; i < 5; i++) 
	{
		angle[i] = Movement::GetInstance()->GetTwoVecAngle({ forward.x, forward.z }, { vec[i].x, vec[i].y });
		angle[i] = D3DXToDegree(angle[i]);
		if (D3DXVec3Dot(&n, &D3DXVECTOR3(vec[i].x, 0.0f, vec[i].y)) < 0.0f)
			angle[i] *= -1;
		length[i] = D3DXVec2Length(&vec[i]);
		if (fabs(angle[i]) < m_Range && length[i] < m_Length) {
			return true;
		}
	}

	if (angle[1] > m_Range && angle[2] < -m_Range)
	{
		return true;
	}
	else if (angle[3] > m_Range && angle[4] < -m_Range) 
	{
		return true;
	}

	return false;
}
