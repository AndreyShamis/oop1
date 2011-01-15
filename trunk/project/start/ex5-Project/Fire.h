#pragma once
#include <vector>
#include "Objects.h"
#include "Sprite.h"

using namespace std ;


class Fire:public Objects
{
public:
	Fire(const char *filename,const short int &time);
	virtual void Draw();
	void setTimer(const short int &newVal);
	short int getTimer(); 
};
