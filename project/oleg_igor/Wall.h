

#pragma once

//#include "macros.h"
#include "GameObject.h"
#include "Sprite.h"
#include <vector>

using namespace std ;

#define WALL_PIC "sprites/wall_rgba.txt"

class Wall: public GameObject {
public:
	
	Wall(double xPos, double yPos) ;

	virtual void draw() ;

	Sprite getSprite() ;

private:

//	vector<Sprite> _sprites ;


};