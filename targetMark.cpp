#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "scene.h"
#include "billboard.h"
#include "targetMark.h"

TargetMark::TargetMark(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, int drawPriority)
	: GameObject(scene, ObjectType::eObBillboard, drawPriority)
{
	m_Marker = new Billboard(scene, pos, size, ResourceTag::tShadow, true, drawPriority);

	scene->Add(this);
}

void TargetMark::Uninit()
{
	m_Marker->SetDestroy();
}