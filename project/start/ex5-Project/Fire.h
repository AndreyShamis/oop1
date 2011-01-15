#pragma once
#include <vector>
#include "Objects.h"
#include "Sprite.h"

using namespace std ;


class Fire:public Objects
{
public:
	Fire(const char *filename);
	virtual void Draw();
};
