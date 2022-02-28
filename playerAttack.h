#pragma once

#include "playerState.h"

class PlayerAttack : public PlayerState
{
public:
	PlayerAttack(Player* player);
	~PlayerAttack(){}
	void Update(Player* player);

private:
	unsigned int m_EffectHandle;
};