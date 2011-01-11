#include "Bochka.h"

Bochka::Bochka()
{
	_sprite.push_back("RGBA/surprise_rgba.txt");
	movable = 0;
}

void Bochka::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}

