#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "hitPoint.h"
#include "experiencePoint.h"
#include "level.h"
#include "attack.h"
#include "status.h"

Status::Status(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int atk, int dfe, int exp, int level, int hp, int dim)
	:GameObject(scene, ObjectType::eObStatus, 1000)
	, m_Difence(dfe)
{
	m_Attack = new Attack(atk);
	m_Exp = new ExperiencePoint(exp);
	m_Level = new Level(level);
	m_HitPoint = new HitPoint(scene, pos, size, hp, dim);

	scene->Add(this);
}

void Status::Update()
{
	m_HitPoint->Update();
	m_Attack->Update();
}

void Status::Uninit()
{
	m_HitPoint->Unitit();
	delete m_Attack;
	delete m_Exp;
	delete m_Level;
	delete m_HitPoint;
}
