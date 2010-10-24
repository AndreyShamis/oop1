#include "line.h"

	Line::Line(Vertex ends0,Vertex ends1)
	{
		_start = ends0;
		_end = ends1;
	}


	Line::Line(Vertex ends[2]) 
	{
		_start = ends[0];
		_end = ends[1];

	}


	Line::Line(float x0, float y0, float x1, float y1) 
	{
		_start._x = x0;
		_end._x = x1;
		_start._y = y0;
		_end._y = y1;	

	}

	Line::Line(Vertex start, float length, float angle)
	{
		_start = start;	

	}



	Vertex Line::getEnd1()
	{
		
		return _start;
	}
	Vertex Line::getEnd2()
	{
		return _end;
	}
	float Line::getLength()
	{
		return 1;
	}
	void Line::draw(bool board[][MAX_Y+1]) // INT
	{
		for(int i=0;i<MAX_X;i++)
		{
			for(int y=0;y<MAX_Y;y++)
			{
				if(board[i][y])
					;
				else
					;
			}

		}
	}

