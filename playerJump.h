#pragma once

#include "playerState.h"
#include "counter.h"

class PlayerJump : public PlayerState
{
public:
	PlayerJump(Player* player, D3DXVECTOR3 vel);
	~PlayerJump() override {}
	void Update(Player* player) override;

private:
	D3DXVECTOR3 m_Velocity;
	Counter m_Count;
};