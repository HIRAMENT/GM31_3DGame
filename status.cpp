#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "hitPoint.h"
#include "experiencePoint.h"
#include "level.h"
#include "attack.h"
#include "status.h"

Status::Status(Scene * scene, StatusInfo * info)
	: GameObject(scene, ObjectType::eObStatus, 100)
{
	m_Attack = new Attack(info->m_AttackPower, info->m_AttackCoolTime);
	m_Exp = new ExperiencePoint(info->m_ExpValue);
	m_Level = new Level(info->m_LevelValue);
	if (info->m_HitPointDimention == 2) 
	{
		m_HitPoint = new HitPoint2D(scene, info->m_HitPointPos, info->m_HitPointSize, info->m_HitPointValue);
	}
	else if (info->m_HitPointDimention == 3)
	{
		m_HitPoint = new HitPoint3D(scene, info->m_HitPointPos, info->m_HitPointSize, info->m_HitPointValue);
	}

	scene->Add(this);
}

void Status::Update()
{
	m_HitPoint->Update();
	m_Attack->Update();
}

void Status::Uninit()
{
	m_HitPoint->Uninit();
	delete m_Attack;
	delete m_Exp;
	delete m_Level;
	delete m_HitPoint;
}
