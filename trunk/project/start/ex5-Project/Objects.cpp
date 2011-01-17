#include "Objects.h"

//=============================================================================
Objects::Objects(void)
{
	movable = 1;
	intelect = 0;
	_enabled = true;
}

Objects::~Objects()
{
	_sprite.clear();
}
//=============================================================================


bool Objects::checkCollision(const Vertex &topLeft,const float &_Objwidth,const float &_Objheight)
{
	
	/*if(topLeft._y + STEP_SPEED > _cord._y || topLeft._y+STEP_SPEED < _cord._y)
		return false;
	else if(topLeft._x + STEP_SPEED > _cord._x || topLeft._x+STEP_SPEED < _cord._x)
		return false;
	else*/ 
	if(
		(
		(_cord._x <= topLeft._x && _cord._x+PIC_WIDTH-1 >= topLeft._x) ||	(_cord._x <= topLeft._x+PIC_WIDTH-1 && _cord._x+PIC_WIDTH-1 >= topLeft._x+PIC_WIDTH)
		)
		&& 
		(
		(_cord._y <= topLeft._y && topLeft._y <= _cord._y+PIC_WIDTH-1)  || (_cord._y <= topLeft._y+PIC_WIDTH-1 && _cord._y+PIC_WIDTH-1>= topLeft._y+PIC_WIDTH)
		)
	)
		return true;

	return false;
}

Vertex Objects::getCord() const
{
	return(_cord);
}
void Objects::setCord(const Vertex &newCoordinate)
{
	_cord = newCoordinate;
}

void Objects::setCordByFloat(const float &x,const float &y)
{
	_cord._x = x;
	_cord._y = y;
}


void Objects::Disable()
{
	_enabled = false;
}

bool Objects::isEnabled() const
{
	return (_enabled);
}