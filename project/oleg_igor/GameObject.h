
#pragma once

//#include "macros.h"
#include "Controlable.h"
#include "Drawable.h"
#include "Sprite.h"
#include <vector>

using namespace std ;

class GameObject: public Controlable, public Drawable {
public:
	GameObject( double xPos, double yPos ) ;

	virtual void draw() {};
	virtual void keyboard( unsigned char key, int x, int y ) {};
	virtual void move( vector<GameObject*> &all_objs ) {};

	double getxPos() ;
	double getyPos() ;

	virtual Sprite getSprite() ;

protected:
	vector<Sprite> _sprites ;

	double _xPos ;
	double _yPos ;
};