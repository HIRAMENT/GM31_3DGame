#include "main.h"
#include "manager.h"
#include "ADX2/adxSound.h"
#include "enemy.h"
#include "enemyAttack.h"
#include "enemyAttackJump.h"
#include "enemyAttackRush.h"
#include "enemyIdol.h"
#include "player.h"
#include "scene.h"
#include "status.h"
#include "attack.h"
#include "hitPoint.h"
#include "collision.h"

EnemyAttack::EnemyAttack()
{
	int random = rand() % 2;
	if(random == 0)
	{ 
		m_State = new EnemyAttackJump();
	}
	else if(random == 1)
	{
		m_State = new EnemyAttackRush();
	}
}

EnemyAttack::~EnemyAttack()
{
	delete m_State;
}

StateResult EnemyAttack::Update(Enemy * enemy)
{
	StateResult sr = m_State->Update(enemy);

	// �U������
	Player* player = Manager::GetInstance()->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	if (enemy->GetStatus()->GetAttack()->CheckCoolTime() && Collision::GetInstance()->ObbToObb(player->GetObb(), enemy->GetObb()))
	{
		enemy->GetStatus()->GetAttack()->GetCoolTime().Reset();
		player->GetStatus()->GetHitPoint()->Damage(enemy->GetStatus()->GetAttack()->GetPower());
		ADXSound::GetInstance()->Play(9);
	}

	if (sr == StateResult::Success)
	{
		enemy->ChangeState(new EnemyIdol);
	}

	return sr;
}
