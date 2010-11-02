#include "stairs.h"
#include "line.h"

	Stairs::Stairs(Vertex bottomLeft,float height,float width,int numOfStairs)
	{
		_bottomLeft = bottomLeft;
		_height = height;
		_width = width;
		_numOfStairs = numOfStairs;

		correctCheck();

	}
	
	void Stairs::move(Vertex shift)
	{
		;
	}
	Vertex  Stairs::getBotLeft()
	{
		return(_bottomLeft);
	}
	float Stairs::getHeight()
	{
		return(_height);
	}
	float Stairs::getWidth()
	{
		return(_width);
	}
	bool Stairs::rotate(int angle)
	{
		return(true);
	}
	void Stairs::draw(bool board[][MAX_Y+1])
	{
	
		float x0,x1,y0,y1;

		x0	=	_bottomLeft._x;
		x1	=	_bottomLeft._x;
		y0	=	_bottomLeft._y;
		y1	=	_bottomLeft._y;

		for(int step=0;step < _numOfStairs;step++)
		{
			y1-=_height;
			Line up = Line(x0,y0,x1,y1);
			up.draw(board);
			//up = NULL;
			y0 = y1;
			x1+= _width;
			up = Line(x0,y0,x1,y1);
			up.draw(board);
			x0+=_width;

		}
	}

	void Stairs::correctCheck()
	{
		if(_bottomLeft._x <0 || _bottomLeft._x+(_width*_numOfStairs) > MAX_X
			|| _bottomLeft._y > MAX_Y || _bottomLeft._y - _height*_numOfStairs < 0)
		{
			std::cout << "Error\n" <<	_bottomLeft._x << " " << _bottomLeft._y << "\n";
			_bottomLeft._x	=	10;
			_bottomLeft._y	=	10;
			_height			=	2;
			_width			=	2;
			_numOfStairs	=	1;
		}
	}