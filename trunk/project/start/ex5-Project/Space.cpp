#include "Space.h"

Space::Space()
{
	_sprite.push_back("RGBA/space_rgba.txt");
	movable = 1;
}

void Space ::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}