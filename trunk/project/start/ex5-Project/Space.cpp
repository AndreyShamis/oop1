#include "Space.h"

//=============================================================================
Space::Space()
{
	_sprite.push_back(SPACE);
	_movable = true;
	setSize();
}

//=============================================================================

void Space ::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}