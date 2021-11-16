#pragma once

class AStar 
{
private:
	struct Node
	{
		D3DXVECTOR3 position;
		float cost;
		float comcost;
		bool isOpen;
		float heuristics;
	};
};