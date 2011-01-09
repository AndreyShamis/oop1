

#pragma once

//#include "macros.h"
#include "GameObject.h"
#include "Sprite.h"

using namespace std ;

#define BOX_PIC "sprites/box_rgba.txt"

class Box: public GameObject {
public:
	
	Box(double xPos, double yPos) ;

	virtual void draw();

	Sprite getSprite() ;

private:
//	vector<Sprite> _sprites ;
};