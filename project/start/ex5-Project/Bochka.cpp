#include "Bochka.h"

//=============================================================================
Bochka::Bochka()
{
	_sprite.push_back(SURPRISE);
	_movable = false;
	setSize();
}

//=============================================================================
//	Draw function
void Bochka::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}

