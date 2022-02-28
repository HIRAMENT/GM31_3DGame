#include "main.h"
#include "resource.h"
#include "player.h"
#include "playerDamage.h"
#include "playerStateSelector.h"
#include "ADX2/adxSound.h"
#include "status.h"
#include "hitPoint.h"
#include "playerDead.h"

PlayerDamage::PlayerDamage(Player * player)
{
	player->SetAnimation(AnimationTag::Hit);
	ADXSound::GetInstance()->Play(7);
}

void PlayerDamage::Update(Player * player)
{
	if (player->GetStatus()->GetHitPoint()->GetHitPoint() <= 0)
	{
		player->ChangeState(new PlayerDead(player));
	}

	if (player->GetAnimeFrame() >= player->GetAnimeEndFrame())
	{
		player->ChangeState(new PlayerStateSelector());
	}
}
