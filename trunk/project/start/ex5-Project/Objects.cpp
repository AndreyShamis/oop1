#include "Objects.h"

//=============================================================================
//	Class constructor 
Objects::Objects(void)
{
	_movable	=	true;			//	if can move over object
	_intelect	=	false;			//	if intelect for computer
	_enabled	=	true;			//	if enabled
	_takable	=	false;			//	if can be taked
	_taked		=	false;			//	if taked

}
//=============================================================================
//	destructor
Objects::~Objects()
{
	_sprite.clear();
}
//=============================================================================
//	return if can move over object
bool Objects::getMovable()
{
	return(_movable);
}

//=============================================================================
//	seting size by geting the of pictures
void Objects::setSize()
{
	_width		=	_sprite[0].getWidth();
	_height		=	_sprite[0].getHeight();
}

//=============================================================================
// check if the object can be taked
bool Objects::isTakeable()
{	
	return(_takable);
}

//=============================================================================
//	check if the object is taked
bool Objects::isTaked()
{
	return(_taked);
}

//=============================================================================
//	set the object be taked
void Objects::setTaked()
{
	_taked = true;
}
//=============================================================================
//	check colision function
bool Objects::checkCollision(const Vertex &topLeft,const float &_Objwidth,
							 const float &_Objheight)
{

	if(((_cord._x <= topLeft._x && _cord._x+PIC_WIDTH-1 >= topLeft._x) 
		||	(_cord._x <= topLeft._x+_Objwidth-1 
		&& _cord._x+PIC_WIDTH-1 >= topLeft._x+_Objwidth))
		&& 
		((_cord._y <= topLeft._y && topLeft._y <= _cord._y+PIC_WIDTH-1)  
		|| (_cord._y <= topLeft._y+_Objheight-1 
		&& _cord._y+PIC_WIDTH-1>= topLeft._y+_Objheight)))
		return true;

	return false;
}
//=============================================================================
//	return coordinate
Vertex Objects::getCord() const
{
	return(_cord);
}
//=============================================================================
//	set coordiante function
void Objects::setCord(const Vertex &newCoordinate)
{
	_cord = newCoordinate;
}
//=============================================================================
//	set coordinate by 2 lfoat variables
void Objects::setCordByFloat(const float &x,const float &y)
{
	_cord._x = x;
	_cord._y = y;
}
//=============================================================================
//	set object be desabled
void Objects::Disable()
{
	_enabled = false;
}
//=============================================================================
//	check if the object is enabled
bool Objects::isEnabled() const
{
	return (_enabled);
}