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
Vertex Objects::getCord()
{
	return(_cord);
}


bool Objects::checkCollision(const Vertex &topLeft,const float &_Objwidth,const float &_Objheight)
{
	if(
		((_cord._x <= topLeft._x && _cord._x+_Objwidth >= topLeft._x)
		||	(_cord._x+_Objwidth <= topLeft._x+_Objwidth && _cord._x+_Objwidth >= topLeft._x+_Objwidth))
		&& ((_cord._y <= topLeft._x && _cord._y+PIC_WIDTH>= topLeft._y)
		|| (_cord._y+_Objheight <= topLeft._x+_Objheight && _cord._y+PIC_WIDTH>= topLeft._y+_Objheight))
		)
		return true;

	return false;
}