#include "Fire.h"

//=============================================================================
//	Class constructor geting filename for fire picture
//	and time for runing
Fire::Fire(const char *filename,const short int &time)
{
	_sprite.push_back(filename);

	_movable = false;
	_timer = time;
	setSize();
}

//=============================================================================
//	destructor
Fire::~Fire()
{
	_sprite.clear();
}

//=============================================================================
//	Draw function
void Fire::Draw()
{
	if(_sprite.size() > 0)
	{
		vector <Sprite>::iterator it;
		it = _sprite.begin();
		if(_timer >= 0)
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