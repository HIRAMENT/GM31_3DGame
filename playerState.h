#pragma once

class Player;

class PlayerState 
{
public:
	virtual ~PlayerState() {};
	virtual void Update(Player* player) = 0;
};