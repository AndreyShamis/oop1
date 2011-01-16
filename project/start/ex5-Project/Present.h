#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>

using namespace std ;
class Present:public Objects
{
public:
	Present();
	virtual void Draw();

private:
	short int _present_type;
};
