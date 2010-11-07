
#include <iostream>
#pragma once

#include "Vertex.h"
#include "macros.h"


struct VertexLine
{
	Vertex _start;
	Vertex _end;
};

class Stairs
{

public:
	Stairs(Vertex bottomLeft,float height,float width,int numOfStairs) ;
	void move(Vertex shift);
	Vertex  getBotLeft();
	float getHeight();
	float getWidth();
	bool rotate(int angle);
	void draw(bool board[][MAX_Y+1]);

private:

	Vertex _bottomLeft;
	float _height;
	float _width;

	float _width_use;
	float _height_use;
	
	int _angle;
	int _numOfStairs;
	void setDefault();
	bool correctCheck(Vertex coor);
	void resetParam();
};