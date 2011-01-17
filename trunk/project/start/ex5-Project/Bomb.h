#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;

class Bomb:public Objects
{
public:
	Bomb();
	~Bomb();
	virtual void Draw();
	virtual void decTimer();
	virtual short int getTimer();
	virtual void IncereaseTimer();
protected:
};
