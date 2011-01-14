#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;

class Bomb:public Objects
{
public:
	Bomb();
	virtual void Draw();
};
