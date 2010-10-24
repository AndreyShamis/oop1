#include "line.h"


	// start cunstruct function Line
	Line::Line(Vertex ends0,Vertex ends1)
	{
		_start	= ends0;
		_end	= ends1;
		checkCorectCoordinates();
	}	//	end function constructor Line

	// start cunstruct function Line
	Line::Line(Vertex ends[2]) 
	{
		_start	= ends[0];
		_end	= ends[1];
		checkCorectCoordinates();
	}	//	end function constructor Line

	// start cunstruct function Line
	Line::Line(float x0, float y0, float x1, float y1) 
	{
		_start._x	= x0;
		_end._x		= x1;
		_start._y	= y0;
		_end._y		= y1;
		checkCorectCoordinates();

	}	//	end function constructor Line

	// start cunstruct function Line
	Line::Line(Vertex start, float length, float angle)
	{
		_start		= start;	//	set coordinates	
		_len		= length;	//	set lentgh
		_angle		= angle;

	}	//	end function constructor Line

	// start  function getEnd1
	Vertex Line::getEnd1()
	{
		return _start;
	}	//	end function getEnd1

	// start  function getEnd2
	Vertex Line::getEnd2()
	{
		return _end;
	}	//	end function getEnd2

	// start  function getLength
	float Line::getLength()
	{
		return _len;
	}	//	end function getLength

	//	Function draw
	void Line::draw(bool board[][MAX_Y+1]) // INT
	{
		for(int i=0;i<MAX_X;i++)
		{
			for(int y=0;y<MAX_Y;y++)
			{
				if(_start._x == i && _start._y==y)
					board[i][y] = true;

			}

		}


	}	//	end function draw

	void Line::CorectCoordinates()
	{
		if(_start._x < 0 || _start._x > MAX_X || _end._x < 0 || _end._x > MAX_X 
			|| _start._y < 0 || _start._y > MAX_Y || _end._y < 0 || _end._y > MAX_Y)
		{
			_start._x	=	0;
			_start._y	=	0;
			_end._x		=	10;
			_end._y		=	10
		}
	}

