#include "line.h"
#include <stdlib.h>
#include <stdio.h>

	// start cunstruct function Line
	Line::Line(Vertex ends0,Vertex ends1)
	{
		_start	= ends0;	//
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

		_end._x		=	_start._x+_len*cos(angle);
		_end._y		=	_start._y-_len*sin(angle);

		checkCorectCoordinates();

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
	/*
	*	// source of code
	*	http://www.codekeep.net/snippets/e39b2d9e-0843-4405-8e31-44e212ca1c45.aspx
	*
	*/
		int p1x = (int)(_start._x+1);
		int p1y = (int)(_start._y+1);
		int p2x = (int)(_end._x+1);
		int p2y = (int)(_end._y+1);
		
		int F, x, y;

		if (p1x > p2x)  // Swap points if p1 is on the right of p2
		{
			swap(p1x, p2x);
			swap(p1y, p2y);
		}

		// Handle trivial cases separately for algorithm speed up.
		// Trivial case 1: m = +/-INF (Vertical line)
		if (p1x == p2x)
		{
			if (p1y > p2y)  // Swap y-coordinates if p1 is above p2
			{
				swap(p1y, p2y);
			}

			x = p1x;
			y = p1y;
			while (y <= p2y)
			{
				board[x][y] = true;
				y++;
			}
			return;
		}
		// Trivial case 2: m = 0 (Horizontal line)
		else if (p1y == p2y)
		{
			x = p1x;
			y = p1y;

			while (x <= p2x)
			{
				board[x][y] = true;
				x++;
			}
			return;
		}


		int dy            = p2y - p1y;  // y-increment from p1 to p2
		int dx            = p2x - p1x;  // x-increment from p1 to p2
		int dy2           = (dy << 1);  // dy << 1 == 2*dy
		int dx2           = (dx << 1);
		int dy2_minus_dx2 = dy2 - dx2;  // precompute constant for speed up
		int dy2_plus_dx2  = dy2 + dx2;


		if (dy >= 0)    // m >= 0
		{
			// Case 1: 0 <= m <= 1 (Original case)
			if (dy <= dx)   
			{
				F = dy2 - dx;    // initial F

				x = p1x;
				y = p1y;
				while (x <= p2x)
				{
					board[x][y] = true;
					if (F <= 0)
					{
						F += dy2;
					}
					else
					{
						y++;
						F += dy2_minus_dx2;
					}
					x++;
				}
			}
			// Case 2: 1 < m < INF (Mirror about y=x line
			// replace all dy by dx and dx by dy)
			else
			{
				F = dx2 - dy;    // initial F

				y = p1y;
				x = p1x;
				while (y <= p2y)
				{
					board[x][y] = true;
					if (F <= 0)
					{
						F += dx2;
					}
					else
					{
						x++;
						F -= dy2_minus_dx2;
					}
					y++;
				}
			}
		}
		else    // m < 0
		{
			// Case 3: -1 <= m < 0 (Mirror about x-axis, replace all dy by -dy)
			if (dx >= -dy)
			{
				F = -dy2 - dx;    // initial F

				x = p1x;
				y = p1y;
				while (x <= p2x)
				{
					board[x][y] = true;
					if (F <= 0)
					{
						F -= dy2;
					}
					else
					{
						y--;
						F -= dy2_plus_dx2;
					}
					x++;
				}
			}
			// Case 4: -INF < m < -1 (Mirror about x-axis and mirror 
			// about y=x line, replace all dx by -dy and dy by dx)
			else    
			{
				F = dx2 + dy;    // initial F

				y = p1y;
				x = p1x;
				while (y >= p2y)
				{
					board[x][y] = true;
					if (F <= 0)
					{
						F += dx2;
					}
					else
					{
						x++;
						F += dy2_plus_dx2;
					}
					y--;
				}
			}
		}
	}	//	end function draw

	void Line::checkCorectCoordinates()
	{
		if(_start._x < 0 || _start._x > MAX_X || _end._x < 0 || _end._x > MAX_X 
			|| _start._y < 0 || _start._y > MAX_Y || _end._y < 0 || _end._y > MAX_Y)
		{
			_start._x	=	0;
			_start._y	=	0;
			_end._x		=	10;
			_end._y		=	10;
		}



	}

	void Line::swap(int &x,int &y)
	{
		int temp = y;
		y	=	x;
		x	=	temp;
	}
