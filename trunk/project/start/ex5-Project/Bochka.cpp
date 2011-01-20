#include "Bochka.h"

//=============================================================================
//	Class constructor
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
	vector <Sprite>::iterator it;		//	vector iterator
	it = _sprite.begin();				//	get the sprite 
	it->Draw(_cord);					//	draw

}

