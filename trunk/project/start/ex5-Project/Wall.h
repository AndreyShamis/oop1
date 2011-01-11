#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;
#define FENCE_RGBA	"RGBA/wall_rgba.txt"

class Wall:public Objects
{
public:
	Wall();
	void Draw();
};
