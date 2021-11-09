#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "scene.h"
#include "resource.h"
#include "polygon2D.h"
#include "number.h"

Number::Number(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int number, int drawPriority)
	: GameObject(scene, ObjectType::eObNumber,drawPriority)
{
	m_NumberUI = new Polygon2D(scene, { pos.x, pos.y }, { size.x, size.y }, ResourceTag::tNumber, drawPriority);
	m_NumberUI->SetPartition(number);
}

void Number::Uninit()
{
	m_NumberUI->SetDestroy();
}


void Number::ChangeNumber(int num)
{
	m_NumberUI->SetPartition(num);
}

void Number::SetDisplay(bool dis)
{
	m_NumberUI->SetDisplay(dis);
}
