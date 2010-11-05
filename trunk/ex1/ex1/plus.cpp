#include "plus.h"


	Plus::Plus(Vertex topLeft,float size)
	{
		_point = topLeft;
		_size = size;

		if(!correctCheck(_point._x, _point._y, _size))
		
			setDefault();
	}


	void Plus::move(Vertex shift)
	{

		if(correctCheck(_point._x + shift._x, _point._y + shift._y, _size))
		{
			_point._x += shift._x;
			_point._y += shift._y;
		}
	}

	Vertex  Plus::getTopLeft()
	{
		return (_point);
	}

 
	float Plus::getSize()
	{
		return(_size);
	}


	float Plus::getArea()
	{
		return(_size * _size * 5);
	}

 
	float Plus::getPerimeter()
	{
		return(1);
	}

  
	void Plus::grow(float delta)
	{

		if(correctCheck(_point._x, _point._y,_size + delta))
		{
			_size += delta;
		}
	}


	void Plus::draw(bool board[][MAX_Y+1])
	{
		_tempPoint = _point;

		//_tempPoint._x++;
		//_tempPoint._y++;
		
		
		Square tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);
		
		
		_tempPoint._y += _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);


		_tempPoint._x -= _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);


		_tempPoint._x += _size*2;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);


		_tempPoint._x -= _size;
		_tempPoint._y += _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);
	}

	bool Plus::correctCheck(float x, float y, float currSize)
	{
		if((x < currSize) || (y < 0) || (y > (MAX_Y - (currSize*3 +1))) || 
		   (x > (MAX_X - (currSize*2 +1))) || (currSize < 1 ))
		
			return false;
		
		return true;
	}
 

	void Plus::setDefault()
	{
	
		_point._x = 15;
		_point._y = 15;
		_size = 3;
	}