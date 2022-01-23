#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "resource.h"
#include "input.h"
#include "enemy.h"
#include "enemyDamage.h"
#include "enemyIdol.h"
#include "player.h"
#include "scene.h"

#define DECCOUNT  (0.05f)
#define KNOCKBACK (2.0f)

EnemyDamage::EnemyDamage()
{
	m_FrameCount = 1.0f;
}

StateResult EnemyDamage::Update(Enemy* enemy)
{
	Player* player = Manager::GetInstance()->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	D3DXVECTOR2 normal = D3DXVECTOR2(enemy->GetPosition().x - player->GetPosition().x, enemy->GetPosition().z - player->GetPosition().z);
	D3DXVec2Normalize(&normal, &normal);
	D3DXVECTOR3 velocity = D3DXVECTOR3(normal.x * KNOCKBACK, 0.0f, normal.y * KNOCKBACK);

	m_FrameCount -= DECCOUNT;

	enemy->SetPosition(enemy->GetPosition() + (velocity * DECCOUNT));

	if (m_FrameCount.GetIsFinish())
	{
		enemy->ChangeState(new EnemyIdol);
		return StateResult::Success;
	}

	return StateResult::Execution;
}