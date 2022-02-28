#include "main.h"
#include "resource.h"
#include "renderer.h"
#include "input.h"
#include "player.h"
#include "playerAttack.h"
#include "polygon3D.h"
#include "status.h"
#include "attack.h"
#include "hitPoint.h"
#include "gauge.h"
#include "enemy.h"
#include "scene.h"
#include "movement.h"
#include "myEffekseer.h"
#include "effectDataBase.h"
#include "viewSensor.h"
#include "ADX2/adxSound.h"
#include "playerStateSelector.h"


PlayerAttack::PlayerAttack(Player * player)
{
	player->SetAnimation(AnimationTag::Attack);
	m_EffectHandle = -1;
}

void PlayerAttack::Update(Player * player)
{
	if (player->GetStatus()->GetAttack()->CheckCoolTime())
	{
		D3DXVECTOR3 forward = player->GetForward();
		player->GetStatus()->GetAttack()->ResetCoolTime();
		std::vector<Enemy*> enemys = player->GetScene()->GetGameObjects<Enemy>(ObjectType::eObEnemy);
		bool isHit = false;
		float playerAng = Movement::GetInstance()->GetTwoVecAngle({ Vec3::Forward.x,Vec3::Forward.z }, { -forward.x , -forward.z });
		float power = player->GetStatus()->GetAttack()->GetPower();
		if (forward.x < 0.0f) playerAng *= -1;

		for (auto enemy : enemys)
		{
			isHit = false;
			// ‹Z”­“®
			if (Mouse_IsRightPress() && player->GetTecPoint() >= 100)
			{
				if (D3DXVec3Length(&(enemy->GetPosition() - player->GetPosition())) < 10)
				{
					m_EffectHandle = MyEffekseer::GetInstance()->Play(ResourceData::GetInstance()->GetEffectResource(EffectTag::SpecialAttack), player->GetPosition(), D3DXVECTOR3(0.0f, playerAng + D3DXToRadian(90), D3DXToRadian(90)));
					power = power * 3;
					player->SetTecPoint(0);
					player->GetCostGauge()->DegCapacity(100);
					isHit = true;
				}
			}
			else
			{
				if (player->GetViewSensor()->WithinRange(player->GetPosition(), enemy->GetPosition(), { forward.x, forward.y, -forward.z }, enemy->GetScale()))
				{
					m_EffectHandle = MyEffekseer::GetInstance()->Play(ResourceData::GetInstance()->GetEffectResource(EffectTag::Attack), player->GetPosition() + D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.0f, playerAng + D3DXToRadian(180), 0.0f));
					isHit = true;
				}
			}

			if (isHit)
			{
				enemy->GetStatus()->GetHitPoint()->Damage(power);
				new Polygon3D(player->GetScene(), enemy->GetPosition(), D3DXVECTOR3(10, 10, 0), ResourceTag::tSlash, true, true, 100);
				ADXSound::GetInstance()->Play(9);
			}
		}
	}

	if(player->GetAnimeFrame() >= player->GetAnimeEndFrame())
	{
		MyEffekseer::GetInstance()->Stop(m_EffectHandle);

		player->ChangeState(new PlayerStateSelector());
	}
}
