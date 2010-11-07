// A class that reprisent Squar.

#pragma once

//                               Include section
//=============================================================================
#include "Vertex.h"
#include "macros.h"

class Square {

//                             Function section
//=============================================================================

public:

	Square(Vertex topLeft,float size); 
	void move(Vertex shift);
	Vertex  getBoundingCircleCenter();   
	float getSize();
	float getArea();
	float getPerimeter(); 
	void draw(bool board[][MAX_Y+1]);


private:

	void setDefault();
	bool correctCheck(float x, float y, float carrSize);


//                              veribel section
//=============================================================================

	// Difine struct of coordinate of the left corner of the squar.
	Vertex	_leftUp;

	// Difine size of square.
	float	_size;
};