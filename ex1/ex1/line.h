#pragma once
#include "Vertex.h"
#include "macros.h"


class Line {

public:

	Line(Vertex ends0, Vertex ends1);
	Line(Vertex ends[2]);  
	Line(float x0, float y0, float x1, float y1); 
	Line(Vertex start, float length, float angle);

	Vertex getEnd1();
	Vertex getEnd2();
	float getLength();
	void draw(bool board[][MAX_Y+1]);


private:

	Vertex _start;
	Vertex _end;

	void checkCorectCoordinates(float x0, float y0, float x1, float y1);

	float	_len;
	float	_angle;
	
	void swap(int &x,int &y);

};
