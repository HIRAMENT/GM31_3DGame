#pragma once

#include "playerState.h"

class PlayerMove : public PlayerState
{
public:
	PlayerMove(Player* player);
	~PlayerMove()override {}
	void Update(Player* player) override;
};