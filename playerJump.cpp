#include "main.h"
#include "resource.h"
#include "input.h"
#include "player.h"
#include "playerJump.h"
#include "playerStateSelector.h"

#define JUMP_VALUE   (2.0f)

PlayerJump::PlayerJump(Player* player, D3DXVECTOR3 vel)
	: m_Velocity(vel)
{
	player->SetAnimation(AnimationTag::Jump);
	m_Count = 5.0f;
}

void PlayerJump::Update(Player * player)
{
	m_Count -= 0.1f;

	// Œ³‚ÌˆÊ’u + ˆÚ“®•ûŒü * ˆê‰ñ‚Ì’l + •‚‚­’l
	float ratio = sinf(PI * m_Count.GetRatio());
	float jump = JUMP_VALUE * ratio;
	D3DXVECTOR3 amount = player->GetPosition() + m_Velocity;
	amount.y = jump;

	player->SetTransformPos(amount);

	if(m_Count.GetIsFinish())
	{ 
		player->ChangeState(new PlayerStateSelector());
	}
}
