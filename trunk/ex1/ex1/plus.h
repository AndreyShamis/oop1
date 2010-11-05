#pragma once
#include "Vertex.h"
#include "macros.h"
#include "line.h"
#include "square.h"

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
	Vertex _tempPoint;
	float _size;
	float _tempSize;

	bool correct_check();

	void setDefault();
};