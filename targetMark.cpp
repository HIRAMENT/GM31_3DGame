#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "polygon3D.h"
#include "scene.h"
#include "targetMark.h"

TargetMark::TargetMark(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, int drawPriority)
	: GameObject(scene, ObjectType::eObBillboard, drawPriority)
{
	m_Marker = new Polygon3D(scene, pos, {size.x, size.y, 0.0f}, ResourceTag::tShadow, true, true, drawPriority);

	scene->Add(this);
}

void TargetMark::Uninit()
{
	m_Marker->SetDestroy();
}
