#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "polygon3D.h"
#include "scene.h"
#include "player.h"
#include "enemy.h"
#include "camera.h"
#include "targetMark.h"

TargetMark::TargetMark(Scene * scene, Camera* camera, int drawPriority)
	: GameObject(scene, ObjectType::eObTargetMark, drawPriority)
{
	m_MarkerUI = new Polygon3D(scene, {0.0f,0.0f,0.0f}, { 1.0f, 1.0f, 0.0f }, ResourceTag::tTargetMarker, true, true, drawPriority);
	m_Camera = camera;
	m_Target = nullptr;

	scene->Add(this);
}

void TargetMark::Update()
{
	if (isSetingTarget())
	{
		// マーカー位置のセット
		D3DXVECTOR3 dire = m_Target->GetPosition() - m_Camera->GetPosition();
		D3DXVec3Normalize(&dire, &dire);
		D3DXVECTOR3 pos = dire * m_Target->GetScale() * 0.5f;
		m_MarkerUI->SetPosition(m_Target->GetPosition() + pos);
	}
}

void TargetMark::Uninit()
{
	m_MarkerUI->SetDestroy();
}

void TargetMark::SetTarget(Enemy * eneym)
{
	m_Target = eneym;
	m_MarkerUI->SetAlpha(1.0f);
}

void TargetMark::ResetTarget()
{
	m_Target = nullptr;
	m_MarkerUI->SetAlpha(0.0f);
}
