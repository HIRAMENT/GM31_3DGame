#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "enemy.h"
#include "enemyDead.h"
#include "effectDataBase.h"
#include "myEffekseer.h"
#include "resource.h"
#include "particle.h"
#include "particleManager.h"
#include "player.h"
#include "scene.h"

EnemyDead::EnemyDead(Enemy* enemy)
{
	m_Time = 5.0f;
	CreateParticle(enemy->GetPosition());
	m_EffectHandle = MyEffekseer::GetInstance()->Play(ResourceData::GetInstance()->GetEffectResource(EffectTag::Dead), enemy->GetPosition(), enemy->GetRotation());
}

StateResult EnemyDead::Update(Enemy * enemy)
{
	m_Time -= 0.1f;

	float scale = m_Time.GetRest() / m_Time.GetMax();
	enemy->SetScale(D3DXVECTOR3(scale,scale, scale));

	if (m_Time.GetIsFinish())
	{
		MyEffekseer::GetInstance()->Stop(m_EffectHandle);
		Player* player = Manager::GetInstance()->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
		player->AddCost(10);
		enemy->SetDestroy();
		return StateResult::Success;
	}

	return StateResult::Execution;
}

void EnemyDead::CreateParticle(D3DXVECTOR3 pos)
{
	ParticleInfo info;
	info.m_Position = pos;
	info.m_TextureTag = ResourceTag::tParticleCircle;
	info.m_DrawPriority = 2;
	info.m_ProductionInterval = 0.0f;
	info.m_BlendMode = BlendMode::ADDITION;
	info.m_ProductionType = ProductionType::Point;
	info.m_is2Dimension = false;
	info.m_isCurve = false;
	info.m_isBillboard = true;
	info.m_ProductionOnes = true;
	info.m_AngleMin = 0;
	info.m_AngleMax = 360;
	info.m_LifeSpanMin = 0.3f;
	info.m_LifeSpanMax = 0.6f;
	info.m_ProductionMin = 75;
	info.m_ProductionMax = 100;
	info.m_ScaleMin = 0.1f;
	info.m_ScaleMax = 0.5f;
	info.m_SpeedMin = 0.1f;
	info.m_SpeedMax = 0.2f;
	info.m_RedMin = 0.0f;
	info.m_RedMax = 0.0f;
	info.m_GreenMin = 0.0f;
	info.m_GreenMax = 1.0f;
	info.m_BlueMin = 1.0f;
	info.m_BlueMax = 1.0f;
	info.m_AlphaMin = 0.5f;
	info.m_AlphaMax = 0.8f;
	info.m_GravityUse = false;
	new ParticleManager(Manager::GetInstance()->GetScene(), &info);
}
