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

EnemyMove::EnemyMove()
{
	m_Boids = new Boids();
}

EnemyMove::~EnemyMove()
{
	delete m_Boids;
}

StateResult EnemyMove::Update(Enemy * enemy)
{
	Player* player = Manager::GetInstance()->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	m_Boids->SetTarget(player->GetPosition());
	m_Boids->FlockIt(enemy);

	enemy->SetPosition(m_Boids->GetPosition());
	enemy->SetRotation(m_Boids->GetRotation());

	if (m_Boids->GetJustDistance()) {
		enemy->ChangeState(new EnemyAttack);
		return StateResult::Success;
	}

	return StateResult::Execution;
}
