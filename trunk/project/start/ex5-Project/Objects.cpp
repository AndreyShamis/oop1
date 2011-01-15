#include "Objects.h"

Objects::Objects(void)
{
	movable = 1;
	intelect = 0;
	_enabled = true;
}


Vertex Objects::getCord()
{
	return(_cord);
}

