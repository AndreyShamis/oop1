// A class that reprisent Line.

#pragma once

//                               Include section
//=============================================================================
#include "Vertex.h"
#include "macros.h"


//                                Const section
//=============================================================================
const double _PAI = 3.14159265;

class Line {

//                               Function section
//=============================================================================
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

	void setDefault();
	bool correctCheck(Vertex start, Vertex end);
	void swap(int &x,int &y);

//                              veribel section
//=============================================================================

	// Difine struct of coordinate of the one end of line.
	Vertex _start;

	// Difine struct of coordinate of the enother end of line.
	Vertex _end;

	// Difine lenth of line.
	float	_len;

	// Difine angle of line at graph.
	float	_angle;
};
