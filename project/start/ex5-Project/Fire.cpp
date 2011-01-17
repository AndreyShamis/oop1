#include "Fire.h"

//=============================================================================
Fire::Fire(const char *filename,const short int &time)
{
	_sprite.push_back(filename);

	movable = 0;
	_timer = time;
}

//=============================================================================
void Fire::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	if(_timer >= 0)
	{
		it->Draw(_cord);
	}

}

//=============================================================================
void Fire::setTimer(const short int &newVal)
{
	_timer = newVal;

}

//=============================================================================
short int Fire::getTimer() 
{
	return(_timer);
}

void Fire::decTimer()
{
	_timer--;
}