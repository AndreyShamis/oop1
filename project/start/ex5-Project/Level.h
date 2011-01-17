#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;
class Level :
	public Objects
{
public:
	Level();
	void Draw();
	void setLevel(const int &level);
private:
	int _level;

};
