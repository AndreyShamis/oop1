#include "line.h"


	Line::(Vertex ends0, Vertex ends1){

		_star = end
	


	Line(Vertex ends[2]);

	Line(float x0, float y0, float x1, float y1);

	Line(Vertex start, float length, float angle);


	Vertex Line::getEnd1();

	Vertex getEnd2();

	float getLength();

	void draw(board[][MAX_Y+1]);



};