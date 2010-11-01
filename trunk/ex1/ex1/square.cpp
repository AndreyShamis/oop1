#include <iostream>
#include "square.h"

	Square::Square(Vertex topLeft,float size)
	{
		_leftUp = topLeft;
		_size	= size;
		correctCheck();
	}


	void Square::move(Vertex shift)
	{
		//clearBoard();
		;
	}


	Vertex  Square::getBoundingCircleCenter()
	{
		Vertex v1;
		v1._x = 10;
		return(v1);
	}


	float Square::getSize()
	{
		return(_size);
	}


	float Square::getArea()
	{
		return(_leftUp._x*_leftUp._y);
	}


	float Square::getPerimeter()
	{
		return(_size*4);
	}


	void Square::draw(bool board[][MAX_Y+1])
	{

		for(int i =(int)(_leftUp._x);i<=(_size+_leftUp._x);i++ )
		{
			for(int y=(int)(_leftUp._y); y <=(_size+_leftUp._y);y++)
			{
				if(i == _leftUp._x || y == _leftUp._y
				|| i== _leftUp._x +_size  || y ==_leftUp._y+_size)
				{
					board[i][y] = true;
				}
			}
		}
	}

	void Square::correctCheck()
	{
		if (_leftUp._x-_size > MAX_X || _leftUp._y -_size > MAX_Y 
			|| _leftUp._x < 0 || _leftUp._y <0 )
		{
			_leftUp._x =	0;
			_leftUp._y =	0;
			_size	=	10;

		}
	}