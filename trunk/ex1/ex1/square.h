#pragma once

#include "Vertex.h"
#include "macros.h"

class Square{



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
	bool correctCheck();
	Vertex	_leftUp;
	float	_size;




};