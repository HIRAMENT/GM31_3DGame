#pragma once

#include "playerState.h"

class PlayerIdle : public PlayerState
{
public:
	PlayerIdle(Player* player);
	~PlayerIdle() override {}

	void Update(Player* player) override;
};