#include "main.h"
#include "input.h"
#include "player.h"
#include "playerStateSelector.h"
#include "playerMove.h"
#include "playerIdle.h"

void PlayerStateSelector::Update(Player * player)
{
	if (Keyboard_IsPress(DIK_W) || Keyboard_IsPress(DIK_A) || Keyboard_IsPress(DIK_S) || Keyboard_IsPress(DIK_D))
	{
		player->ChangeState(new PlayerMove(player));
	}
	else
	{
		player->ChangeState(new PlayerIdle(player));
	}
}
