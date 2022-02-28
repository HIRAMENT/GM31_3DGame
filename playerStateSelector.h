#pragma once

#include "playerState.h"

class PlayerStateSelector : public PlayerState
{
public:
	PlayerStateSelector() {}
	~PlayerStateSelector() {}

	void Update(Player* player) override;
};