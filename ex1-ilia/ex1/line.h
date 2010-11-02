#include "vertex.h"
#include "macros.h"


	const float DEFAULT_MAX_X = 10; 
	const float DEFAULT_MAX_Y = 10; 
	const float DEFAULT_MIN_X = 0; 
	const float DEFAULT_MIN_Y = 0; 

class Line{

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

	// difine to ends of line:
	Vertex _start;
	Vertex _end;


	

	bool chekLimit(Vertex coordinate);

	bool chekLimit(float coordinate, int limit);

	void setDefault();

	void swap(int &a, int &b);
	

};






