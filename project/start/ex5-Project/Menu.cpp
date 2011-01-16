#include "Menu.h"

//=============================================================================
Menu::Menu()
{
	_sprite.push_back(WALL);
}

//=============================================================================
void Menu::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	it->Draw(_cord);
}
