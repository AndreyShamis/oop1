#include "Present.h"

//=============================================================================
Present::Present()
{
	_sprite.push_back(BOMB_SURPRISE);
	movable = 1;
}

//=============================================================================
void Present::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	it->Draw(_cord);
}