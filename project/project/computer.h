#pragma once
#include "player.h"

class Computer : public Player
{
public:
	Computer();
private:

	int	getInput(Bomb *bombs);
	// A function that try to detect derection to enemy.
	short getTurnCodeByDetectEnemy();
	
	// A function that check if can put bomb and enemy can be blowed.
	bool checkEnemyinBombRaound();

	// A function that performs computer intellect.
	short CompIntellect(Bomb *bombs);

	int	_computerTryDetectEnemy; // Difine direction of enemy.

};
