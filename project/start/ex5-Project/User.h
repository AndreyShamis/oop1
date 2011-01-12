#pragma once
#include "Player.h"
class User:public Player
{
public:
	User();
	virtual void Press(unsigned char key, int x, int y);
	virtual void SpecPress(int key, int x, int y);
};
