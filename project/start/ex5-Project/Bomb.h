#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <time.h>
#include "bomb.h"
#include <vector>
using namespace std ;

class Bomb:public Objects
{
public:
	Bomb();
	virtual void Draw();
	void decTimer();
	short int getTimer() ;
protected:
	short int _timer;
};
