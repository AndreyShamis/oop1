#include "Bomb.h"

Bomb::Bomb()
{
	
	_sprite.push_back(BOMB_STEP_ONE);
	_sprite.push_back(BOMB_STEP_TWO);
	_sprite.push_back(BOMB_BEFOR);
	_sprite.push_back(BOMB_SURPRISE);
	movable = 0;
	_timer = 30;
}

short int Bomb::getTimer() 
{
	return(_timer);
}
void Bomb::Draw()
{
	vector <Sprite>::iterator it;

	if(_timer > 20)
		it = _sprite.begin();
	else if(_timer> 10)
		it = _sprite.begin()+1;
	else if(_timer>3)
		it = _sprite.begin()+2;
	else
		it = _sprite.begin()+3;

	it->Draw(_cord);
	decTimer();
}

void Bomb::decTimer()
{
	_timer--;
}