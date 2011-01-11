#include "Bochka.h"

Bochka::Bochka()
{
	_sprite.push_back("RGBA/surprise_rgba.txt");
}

void Bochka::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}

