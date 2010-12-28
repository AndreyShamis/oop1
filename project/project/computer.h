#pragma once
#include "player.h"

class Computer : public Player
{
public:
	Computer(void);
private:
	int		getInput(const char map[][MAP_X],Bomb *bombs);
	// A function that try to detect derection to enemy.
	short getTurnCodeByDetectEnemy();
	
	// A function that check if can put bomb and enemy can be blowed.
	bool checkEnemyinBombRaound();

	// A function that performs computer intellect.
	short CompIntellect(const char map[][MAP_X],Bomb *bombs);
};
