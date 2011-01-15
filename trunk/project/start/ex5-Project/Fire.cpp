#include "Fire.h"

Fire::Fire(const char *filename)
{
	_sprite.push_back(filename);

	movable = 0;
	_timer = 30;
}

void Fire::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	it->Draw(_cord);

}
