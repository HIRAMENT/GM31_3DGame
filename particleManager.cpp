#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "texture.h"
#include "scene.h"
#include "polygon2D.h"
#include "particle.h"
#include "particleManager.h"

ParticleManager::ParticleManager(class Scene* scene,ParticleInfo* info)
	: GameObject(scene, ObjectType::eObParticle, info->m_DrawPriority)
	, m_ParticleInfo(*info)
	, m_ProductionInterval(info->m_ProductionInterval)
{
	CreateParticle();
	scene->Add(this);
}

void ParticleManager::Uninit()
{
	m_Particles.clear();
}

void ParticleManager::Update()
{
	m_ProductionInterval -= 0.1f;

	if (m_ProductionInterval.GetIsFinish()){
		m_ProductionInterval.Reset();
		CreateParticle();
	}

	m_Particles.remove_if([](Particle* particle) {return particle == nullptr; });
}

void ParticleManager::CreateParticle()
{
	int prodaction;
	if (m_ParticleInfo.m_ProductionMax == m_ParticleInfo.m_ProductionMin) {
		prodaction = m_ParticleInfo.m_ProductionMax;
	}
	else{
		prodaction = rand() % (m_ParticleInfo.m_ProductionMax - m_ParticleInfo.m_ProductionMin) + m_ParticleInfo.m_ProductionMin;
	}

	for (int i = 0; i < prodaction; i++)
	{
		if (m_ParticleInfo.m_is2Dimension) 
		{
			m_Particles.emplace_back(new Particle2D(GetScene(), &m_ParticleInfo));
		}
		else
		{
			m_Particles.emplace_back(new Particle3D(GetScene(), &m_ParticleInfo));
		}
	}
}
