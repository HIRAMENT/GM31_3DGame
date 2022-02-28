#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "resource.h"
#include "input.h"
#include "boids.h"
#include "enemy.h"
#include "scene.h"
#include "enemyMove.h"
#include "player.h"
#include "enemyAttack.h"
#include "status.h"
#include "attack.h"

EnemyMove::EnemyMove()
{
	m_Boids = new Boids();
}

EnemyMove::~EnemyMove()
{
	BoidsData::GetInstance()->Erasure(m_Boids);
	delete m_Boids;
}

StateResult EnemyMove::Update(Enemy * enemy)
{
	D3DXVECTOR3 adj(0.0f, 0.0f, 0.0f);
	Player* player = Manager::GetInstance()->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	m_Boids->SetTarget(player->GetPosition());
	m_Boids->FlockIt(enemy);

	if (enemy->GetEnemyType() == EnemyType::Boss)
	{
		adj = D3DXVECTOR3(0.0f, 1.5f, 0.0f);
	}

	enemy->SetPosition(m_Boids->GetPosition() + adj);
	enemy->SetRotation(m_Boids->GetRotation());

	if (m_Boids->GetJustDistance() && enemy->GetStatus()->GetAttack()->CheckCoolTime()) {
		enemy->ChangeState(new EnemyAttack);
		return StateResult::Success;
	}

	return StateResult::Execution;
}
