#include "Objects.h"

//=============================================================================
Objects::Objects(void)
{
	movable		=	1;
	intelect	=	0;
	_enabled	=	true;
	_takable	=	false;
	_taked		=	false;

}
//=============================================================================
Objects::~Objects()
{
	_sprite.clear();
}
//=============================================================================
void Objects::setSize()
{
	_width		=	_sprite[0]._width;
	_height		=	_sprite[0]._height;
}
//=============================================================================
bool Objects::isTakeable()
{	
	return(_takable);
}

//=============================================================================
bool Objects::isTaked()
{
	return(_taked);
}
//=============================================================================
void Objects::setTaked()
{
	_taked = true;
}
//=============================================================================


bool Objects::checkCollision(const Vertex &topLeft,const float &_Objwidth,
							 const float &_Objheight)
{

	if(((_cord._x <= topLeft._x && _cord._x+PIC_WIDTH-1 >= topLeft._x) 
		||	(_cord._x <= topLeft._x+PIC_WIDTH-1 
		&& _cord._x+PIC_WIDTH-1 >= topLeft._x+PIC_WIDTH))
		&& 
		((_cord._y <= topLeft._y && topLeft._y <= _cord._y+PIC_WIDTH-1)  
		|| (_cord._y <= topLeft._y+PIC_WIDTH-1 
		&& _cord._y+PIC_WIDTH-1>= topLeft._y+PIC_WIDTH)))
		return true;

	return false;
}
//=============================================================================
Vertex Objects::getCord() const
{
	return(_cord);
}
//=============================================================================
void Objects::setCord(const Vertex &newCoordinate)
{
	_cord = newCoordinate;
}
//=============================================================================
void Objects::setCordByFloat(const float &x,const float &y)
{
	_cord._x = x;
	_cord._y = y;
}
//=============================================================================

void Objects::Disable()
{
	_enabled = false;
}
//=============================================================================
bool Objects::isEnabled() const
{
	return (_enabled);
}