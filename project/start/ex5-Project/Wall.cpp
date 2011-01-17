#include "Wall.h"

//=============================================================================
//	Constructor
Wall::Wall()
{
	_sprite.push_back(WALL);		//	put the image to the cector of sprites
	movable = 0;					//	set not movable
	setSize();						//	set size of image
}
//=============================================================================
//	Draw function
void Wall::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}
