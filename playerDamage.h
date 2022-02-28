#pragma once

#include "playerState.h"

class PlayerDamage : public PlayerState
{
public:
	PlayerDamage(Player* player);
	~PlayerDamage() override {}

	void Update(Player* player) override;
};