#include "Wall.h"

//=============================================================================
//	Constructor
Wall::Wall()
{
	_sprite.push_back(WALL);		//	put the image to the cector of sprites
	_movable = false;					//	set not movable
	setSize();						//	set size of image
}
//=============================================================================
//	Draw function
void Wall::Draw()
{
	vector <Sprite>::iterator it;		//	vector iterator
	it = _sprite.begin();				//	get the sprite 
	it->Draw(_cord);					//	draw
}
