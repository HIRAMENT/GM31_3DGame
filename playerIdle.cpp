#include "main.h"
#include "resource.h"
#include "input.h"
#include "player.h"
#include "playerIdle.h"
#include "playerMove.h"
#include "playerJump.h"
#include "playerAttack.h"
#include "status.h"
#include "attack.h"

PlayerIdle::PlayerIdle(Player * player)
{
	player->SetAnimation(AnimationTag::Idle);
}

void PlayerIdle::Update(Player * player)
{
	// 移動に移行
	if (Keyboard_IsPress(DIK_W) || Keyboard_IsPress(DIK_A) || Keyboard_IsPress(DIK_S) || Keyboard_IsPress(DIK_D))
	{
		player->ChangeState(new PlayerMove(player));
	}

	// ジャンプに移行
	if (Keyboard_IsPress(DIK_SPACE))
	{
		player->ChangeState(new PlayerJump(player ,D3DXVECTOR3(0.0f, 0.0f, 0.0f)));
	}

	// 攻撃に移行
	if (Mouse_IsLeftTrigger() && player->GetStatus()->GetAttack()->CheckCoolTime())
	{
		player->ChangeState(new PlayerAttack(player));
	}
}
