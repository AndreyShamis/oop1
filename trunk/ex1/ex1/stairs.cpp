#include "stairs.h"
#include "line.h"

	Stairs::Stairs(Vertex bottomLeft,float height,float width,int numOfStairs)
	{
		_bottomLeft = bottomLeft;
		_height = height;
		_width = width;
		_numOfStairs = numOfStairs;

		_angle = 0;
		
		resetParam();
		if(!correctCheck(_bottomLeft))
			setDefault();


	}
	
	void Stairs::move(Vertex shift)
	{
		Vertex temp;

		temp = _bottomLeft;

		temp._x +=shift._x;
		temp._y +=shift._y;


		if(correctCheck(temp))
			_bottomLeft = temp;

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
		_angle = angle;

		if(_angle%4 == 1)
		{
			_height_use = _height*(-1);
			_width_use = _width * (1);	
		}
		else if(_angle%4==2)
		{
			_height_use = _height * (-1);
			_width_use  = _width * (-1);
		}
		else if(_angle%4 == 3)
			_width_use = _width*(-1);

		if(!correctCheck(_bottomLeft))
		{
			resetParam();		
			return(false);
		}
		
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

			if(_angle%4 == 0 || _angle%4 == 2)
				y1-=_height_use;
			else
				x1-=_height_use;

				Line up = Line(x0,y0,x1,y1);
				up.draw(board);
			


			y0 = y1;
			x0 = x1;

			if(_angle%4 == 0 || _angle%4 == 2)
				x1+= _width_use;
			else
				y1+=_width_use;

			up = Line(x0,y0,x1,y1);
			up.draw(board);

			if(_angle%4 == 0 || _angle%4 == 2)
				x0+=_width_use;
			else
				y0+=_width_use;

		}

		resetParam();
	}


	bool Stairs::correctCheck(Vertex coor)
	{
		
		if(coor._x <0 || (coor._x+_width_use*_numOfStairs) > MAX_X
			|| coor._y > MAX_Y || (coor._y - _height_use*_numOfStairs) < 0)
		{
			return(false);
		}
		return(true);
	}


	void Stairs::setDefault()
	{
		_bottomLeft._x	=	10;
		_bottomLeft._y	=	10;
		_height			=	2;
		_width			=	2;
		_numOfStairs	=	1;
	}

	void Stairs::resetParam()
	{
		_width_use = _width;
		_height_use = _height;

	}