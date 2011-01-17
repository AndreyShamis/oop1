#include "Wall.h"

//=============================================================================
Wall::Wall()
{
	_sprite.push_back(WALL);
	movable = 0;
	setSize();
}
//=============================================================================
void Wall::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}
