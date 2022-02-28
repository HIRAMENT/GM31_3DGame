#include "main.h"
#include "resource.h"
#include "scene.h"
#include "player.h"
#include "playerDead.h"

PlayerDead::PlayerDead(Player * player)
{
	player->SetAnimation(AnimationTag::Dead);
}

void PlayerDead::Update(Player * player)
{ 
	if (player->GetAnimeFrame() >= player->GetAnimeEndFrame() - 5)
	{
		player->SetisDead(true);
	}
}
