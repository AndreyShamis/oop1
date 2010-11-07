// A class that reprisent plus.

#pragma once

//                               Include section
//=============================================================================
#include "Vertex.h"
#include "macros.h"
#include "square.h"

class Plus{

public:

	Plus(Vertex topLeft,float size);
	void move(Vertex shift); 
	Vertex  getTopLeft(); 
	float getSize();
	float getArea(); 
	float getPerimeter();  
	void grow(float delta);  
	void draw(bool board[][MAX_Y+1]); 


private:

	bool correctCheck(float x, float y, float carrSize);
	void setDefault();


	//                              veribel section
//=============================================================================

	// Difine struct of coordinate of the left corner of the plus.
	Vertex _point;

	// Difine size of plus
	float _size;
};