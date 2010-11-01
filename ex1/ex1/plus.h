#pragma once
#include "Vertex.h"
#include "macros.h"
#include "line.h"

class Plus
{

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
	Vertex _point;
	float _size;

	void correct_check();
};