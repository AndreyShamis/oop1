#include <iostream>
#include "square.h"

	Square::Square(Vertex topLeft,float size)
	{
		_leftUp = topLeft;

		_leftUp._x;
		_leftUp._y;

		_size	= size;
		if(!correctCheck())
			setDefault();

	}


	void Square::move(Vertex shift)
	{
		Vertex tempPoint;

		tempPoint = _leftUp;
		_leftUp._x += shift._x;
		_leftUp._y += shift._y;

		if(!correctCheck())
			_leftUp = tempPoint;

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
		Vertex tempPoint;

		tempPoint._x = _leftUp._x + 1;
		tempPoint._y = _leftUp._y + 1;

		for(int i =(int)(tempPoint._x);i<=(_size+tempPoint._x);i++ )
		{
			for(int y=(int)(tempPoint._y); y <=(_size+tempPoint._y);y++)
			{
				if(i == tempPoint._x || y == tempPoint._y
				|| i== tempPoint._x +_size  || y ==tempPoint._y+_size)
				{
					board[i][y] = !board[i][y];
				}
			}
		}
	}

	bool Square::correctCheck()
	{

		if (_leftUp._x >= MAX_X -_size || _leftUp._y >= MAX_Y -_size
			|| _leftUp._x < 0 || _leftUp._y <0 || _size < 1)

			return false;
		
		
		return true;
	}

	void Square::setDefault()
	{
		_leftUp._x =	0;
		_leftUp._y =	0;
		_size	=	10;

	}