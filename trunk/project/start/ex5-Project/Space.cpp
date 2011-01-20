#include "Space.h"

//=============================================================================
//	Class constructor 
Space::Space()
{
	_sprite.push_back(SPACE);
	_movable = true;
	setSize();
}

//=============================================================================
//	Function to draw object
void Space ::Draw()
{
	vector <Sprite>::iterator it;		//	vector iterator
	it = _sprite.begin();				//	get the sprite 
	it->Draw(_cord);					//	draw
}