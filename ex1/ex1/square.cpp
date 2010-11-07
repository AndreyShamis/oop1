// A class that reprisent Squar

//                               Include section
//=============================================================================
#include "square.h"

//                             Function section
//=============================================================================

	// Constarctor of Squar
	Square::Square(Vertex topLeft,float size)
	{
		// Set left up point coordinate. 
		_leftUp = topLeft;

		// Set size of squar sides.
		_size	= size;

		// Check if the seted data is correct.
		if(!correctCheck(_leftUp._x, _leftUp._y, _size))

			// If not correct - set default data.
			setDefault();
	}

	// A function that move the squar at the board
	// Input: value of shift the coordinate.
	void Square::move(Vertex shift)
	{
		// If the new coordinate is ok - save them.
		if(correctCheck(_leftUp._x + shift._x, _leftUp._y  + shift._y, _size))
		{
			_leftUp._x += shift._x;
			_leftUp._y += shift._y;
		}
	}

	// A function that return current Bounding Circle Center of the squar.
	Vertex  Square::getBoundingCircleCenter()
	{
		Vertex v1;
		v1._x = 10;
		return(v1);
	}

	// A function that return current size of squar side.
	float Square::getSize()
	{
		return(_size);
	}

	// A function that return current square area.
	float Square::getArea()
	{
		return(_leftUp._x*_leftUp._y);
	}

	// A function that return current square perimeter.
	float Square::getPerimeter()
	{
		return(_size*4);
	}

	// A function that drow the squre on the boolian board.
	// Input: boolian board.
	void Square::draw(bool board[][MAX_Y+1])
	{
		// Difine struct of temprorary coordinate of the left corner of the 
		// square..
		Vertex tempPoint;

		// Set temp coordinate
		tempPoint._x = _leftUp._x + 1;
		tempPoint._y = _leftUp._y + 1;

		// Drow the squar
		for(int i =(int)(tempPoint._x);i<=(_size+tempPoint._x);i++ )
		{
			for(int y=(int)(tempPoint._y); y <=(_size+tempPoint._y);y++)
			{
				// If it is the coordinate where the side of the squar are 
				// going - drow.
				if(i == tempPoint._x || y == tempPoint._y
				|| i== tempPoint._x +_size  || y ==tempPoint._y+_size)
				{
					board[i][y] = !board[i][y];
				}
			}
		}
	}

	// A function that check the cooordinate for corection.
	// Input: Square coordinate of top left corner, size of squre.
	// Output: true if corect, atherwise return false.
	bool Square::correctCheck(float x, float y, float carrSize)
	{
		// Chek the right condition:
		if (x >= MAX_X - carrSize || y >= MAX_Y - carrSize
			|| x < 0 || y <0 || carrSize < 1)

			return false;
		
		return true;
	}

	// A fanction that set default coordinate and size of side of squar.
	void Square::setDefault()
	{
		_leftUp._x =	0;
		_leftUp._y =	0;
		_size	=	10;

	}