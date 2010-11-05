#include "plus.h"


	Plus::Plus(Vertex topLeft,float size)
	{
		_point = topLeft;
		_size = size;

		if(!correct_check())
		
			setDefault();
	}


	void Plus::move(Vertex shift)
	{
		_tempPoint = _point;
		_point._x += shift._x;
		_point._y += shift._y;
		
		if(!correct_check())
		
			_point = _tempPoint;
		
		
		return;
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
		return(1);
	}

 
	float Plus::getPerimeter()
	{
		return(1);
	}

  
	void Plus::grow(float delta)
	{
		_tempSize = _size;
		_size += delta;

		if(!correct_check())
		
			_size = _tempSize;

		return;

	}

  
	void Plus::draw(bool board[][MAX_Y+1])
	{
		_tempPoint = _point;

		_tempPoint._x++;
		_tempPoint._y++;
		
		
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


	bool Plus::correct_check()
	{
		if((_size < 1 ) || (_point._x < _size) || (_point._y < 0) || (_point._y > (MAX_Y - (_size*3 +1))) || (_point._x > (MAX_X - (_size*2 +1))) )
		{
			return false;
		}
		return true;
	}
 

	void Plus::setDefault()
	{
	
		_point._x = 15;
		_point._y = 15;
		_size = 3;
	}