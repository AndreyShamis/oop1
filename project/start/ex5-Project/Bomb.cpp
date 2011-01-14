#include "Bomb.h"

Bomb::Bomb()
{
//	_sprite.push_back(BOMB_BEFOR);
	_sprite.push_back(BOMB_STEP_ONE);
	_sprite.push_back(BOMB_STEP_TWO);
	_sprite.push_back(BOMB_SURPRISE);
	movable = 0;
}

void Bomb::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}
