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
		Vertex temp;			// temporary coordinate

		temp = _bottomLeft;		// set real coordinates

		temp._x +=shift._x;		// math new coordinates
		temp._y +=shift._y;		// --------------------


		if(correctCheck(temp))	//	check if the coordinates good
			_bottomLeft = temp;	//	and update to new coordinates

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

	// function which rotate the steirs 
	bool Stairs::rotate(int angle)
	{
		float tmp_h;					//	previuos height use
		float tmp_w;					//	previous width_use
		bool temp_mirror = _mirror;		//	set previuos mirror
		int temp_angle = angle;			//	set for temp previous ahgle

		//	set new angle
		_angle+= angle;

		tmp_h = _height_use;
		tmp_w = _width_use;


		if(_angle%4 == 0)
		{
			_mirror = true;
			resetParam();
		}
		else if(_angle%4 == 1)
		{
			_mirror = false;
			_height_use = _height*(1);
		}
		else if(_angle%4==2)
		{
			_mirror = true;
			_height_use = _height * (-1);
			_width_use  = _width * (-1);
		}
		else if(_angle%4 == 3)
		{	
			_width_use = _width*(-1);
			_mirror = false;
		}

		// if correct fail return false
		// and set back the parameters before function call
		if(!correctCheck(_bottomLeft))
		{
			_height_use = tmp_h;	//	set previuos height
			_width_use = tmp_w;		//	set previous width
			_mirror = temp_mirror;
			_angle = temp_angle;
			return(false);
		}
		
		return(true);

	}
	void Stairs::draw(bool board[][MAX_Y+1])
	{
	
		float x0,x1,y0,y1;		// temprorary variables for drow 
								// function using

		x0	=	_bottomLeft._x;		// set the temp variables
		x1	=	_bottomLeft._x;		// ----------------------
		y0	=	_bottomLeft._y;		// ----------------------
		y1	=	_bottomLeft._y;		// ----------------------

		for(int step=0;step < _numOfStairs;step++)
		{

			if(_mirror)
				y1-=_height_use;
			else
				x1+=_height_use;

				Line up = Line(x0,y0,x1,y1);
				up.draw(board);
			


			y0 = y1;
			x0 = x1;

			if(_mirror)
				x1+= _width_use;
			else
				y1+=_width_use;

			up = Line(x0,y0,x1,y1);
			up.draw(board);

			if(_mirror)
				x0+=_width_use;
			else
				y0+=_width_use;

		}

		//resetParam();
	}


	bool Stairs::correctCheck(Vertex coor)
	{
		float x_lim = 0;
		float y_lim = 0;

		// math the coordinates of end stairs
		if(_mirror)
		{
				x_lim = coor._x + _width_use*_numOfStairs;
				y_lim = coor._y - _height_use*_numOfStairs;
		}
		else
		{
				x_lim = coor._x + _height_use*_numOfStairs;
				y_lim = coor._y + _width_use*_numOfStairs;
		
		}
		if( (coor._x <0 ||coor._y >= MAX_Y || coor._x >= MAX_X ||coor._y <0 )
			||	( x_lim < 0 || x_lim >= MAX_X || y_lim < 0 || y_lim >= MAX_Y) )
				return(false);
		
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

	//--------- reset With and Height to default function
	void Stairs::resetParam()
	{
		_width_use = _width;		//	set default width
		_height_use = _height;		//	set default height

	}