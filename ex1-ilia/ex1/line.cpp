#include "line.h"


	Line::Line(Vertex ends0, Vertex ends1){

		if(chekLimit(ends0) && chekLimit(ends0))
		{
			_start	= ends0;
			_end	= ends1;
		}
		else
		{
			setDefault();	
		}
	}

	Line::Line(Vertex ends[2]){
	

		if(chekLimit(ends[0]) && chekLimit(ends[1]))
		{
			_start	= ends[0];
			_end	= ends[1];
		}
		else
		{
			setDefault();	
		}
	}

	Line::Line(float x0, float y0, float x1, float y1){
	
		if(chekLimit(x0,MAX_X)&&
		   chekLimit(y0,MAX_Y)&&
		   chekLimit(x1,MAX_X)&&
		   chekLimit(y1,MAX_Y))
		{
			_start._x = x0;
			_start._y = y0;
			_end._x   = x1;
			_end._y   = y1;
		}
		else
		{
			setDefault();	
		}
	}


/*
	Line::Line(Vertex start, float length, float angle){

		if(!chekLimit(start))
		{
			setDefault();
			return;
		}

		_length		= length;	
		_angle		= angle;

	}
*/


	Vertex Line::getEnd1(){

		return _start;
	}

		

	Vertex Line::getEnd2(){

		return _end;
	}


//	float Line::getLength(){

//		return _length;
//	}


/*
Draws a line between two points p1(p1x,p1y) and p2(p2x,p2y).
This function is based on the Bresenham's line algorithm and is highly 
optimized to be able to draw lines very quickly. There is no floating point 
arithmetic nor multiplications and divisions involved. Only addition, 
subtraction and bit shifting are used. 
*/
	void Line::draw(bool board[][MAX_Y + 1] ){
	
		int F, x, y;
		int p1x = (int)_start._x;
		int p1y = (int)_start._y;
		int p2x = (int)_end._x;
		int p2y = (int)_end._y;




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
				board[x+1][y+1] = true;
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
				board[x+1][y+1] = true;
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
					board[x+1][y+1] = true;
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
					board[x+1][y+1] = true;
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
					board[x+1][y+1] = true;
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
					board[x+1][y+1] = true;
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
	}




	bool Line::chekLimit(Vertex coordinate){
	
	
		return (chekLimit(coordinate._x, MAX_X) && chekLimit(coordinate._y, MAX_Y));
	}
	
	bool Line::chekLimit(float coordinate, int limit){
	
		if(coordinate >= limit || coordinate < 0)

			return false;
	
		return true;
	}


	void Line::setDefault(){
	
		_start._x = DEFAULT_MIN_X;
		_start._y = DEFAULT_MIN_X;
		_end._x   = DEFAULT_MAX_X;
		_end._y   = DEFAULT_MAX_Y;
	}

	void Line::swap(int &a, int &b){

		int temp   = a;
		a		   = b;
		b		   = temp;

		return;
	}
