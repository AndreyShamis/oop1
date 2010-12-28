#pragma once
#include "player.h"

class User :public Player
{
public:
	User(void);

private:
	int		getInput(const char map[][MAP_X],Bomb *bombs);
};
