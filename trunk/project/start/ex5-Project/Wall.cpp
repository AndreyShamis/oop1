#include "Wall.h"


Wall::Wall()
{
	_sprite.push_back(FENCE_RGBA);
}

void Wall::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}
