#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "obb.h"
#include "shadow.h"
#include "obstancle.h"

Obstancle::Obstancle(Scene * scene, int drawPriority)
	: GameObject(scene, ObjectType::eObObstancle, drawPriority)
{
	scene->Add(this);
}

void Obstancle::Init()
{
}

void Obstancle::Uninit()
{
	delete m_Obb;
	m_Shadow->SetDestroy();
}

void Obstancle::Update()
{
}

void Obstancle::Draw()
{
}
