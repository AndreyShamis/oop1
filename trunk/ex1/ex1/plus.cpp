// A class that reprisent plus.
 
//                               Include section
//=============================================================================
#include "plus.h"

//                             Function section
//=============================================================================

	// Constracter of plus.
	Plus::Plus(Vertex topLeft,float size)
	{
		// Set plus top left corner coordinate.
		_point = topLeft;
		// set size of the plus side.
		_size = size;

		// Check if the seted data is correct.
		if(!correctCheck(_point._x, _point._y, _size))

			// If not correct - set default data.
			setDefault();
	}

	// A function that move the plus on the board
	// Input: value of shift the coordinate.
	void Plus::move(Vertex shift)
	{
		// If the new coordinate is ok - save them.
		if(correctCheck(_point._x + shift._x, _point._y + shift._y, _size))
		{
			_point._x += shift._x;
			_point._y += shift._y;
		}
	}

	// A function that return top left coordinate of plus.
	Vertex  Plus::getTopLeft()
	{
		return (_point);
	}

	// A function that return current size of plus side.
	float Plus::getSize()
	{
		return(_size);
	}


	float Plus::getArea()
	{
		return(_size * _size * 5);
	}

	// A function that return current plus area.
	float Plus::getPerimeter()
	{
		return(1);
	}

	// A function that increases Each sides of plus in delta. 
	// Input: increas value.
	void Plus::grow(float delta)
	{
		// If the new size of side is ok - save that.
		if(correctCheck(_point._x, _point._y,_size + delta))
		{
			_size += delta;
		}
	}

	// A function that drow the plus on the boolian board.
	// Input: boolian board.
	// Method: Drow 5 small squar using squar class.
	void Plus::draw(bool board[][MAX_Y+1])
	{
		// Difine struct of temprorary coordinate of the left corner of the pluse. 
		Vertex _tempPoint = _point;
		
		// Drow top small squar.
		Square tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);
		
		// Drow senteral small squar.
		_tempPoint._y += _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);

		// Drow right small squar.
		_tempPoint._x -= _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);

		// Drow left small squar.
		_tempPoint._x += _size*2;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);

		// Drow boton small squar.
		_tempPoint._x -= _size;
		_tempPoint._y += _size;
		tempSquare = Square(_tempPoint, _size);
		tempSquare.draw(board);
	}

	// A function that check the cooordinate for corection.
	// Input: Plus coordinate of top left corner, size of Plus side.
	// Output: true if corect, atherwise return false.
	bool Plus::correctCheck(float x, float y, float currSize)
	{
		// Chek the right condition:
		if((x < currSize) || (y < 0) || (y > (MAX_Y - (currSize*3 +1))) || 
		   (x > (MAX_X - (currSize*2 +1))) || (currSize < 1 ))
		
			return false;
		
		return true;
	}
 
	// A fanction that set default coordinate and size of side of squar.
	void Plus::setDefault()
	{
	
		_point._x = 15;
		_point._y = 15;
		_size = 3;
	}