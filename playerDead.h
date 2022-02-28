#pragma once

#include "playerState.h"

class PlayerDead : public PlayerState
{
public:
	PlayerDead(Player* player);
	~PlayerDead() override {}

	void Update(Player* player) override;
};