#include "Menu.h"

//=============================================================================
//	Class constructor geting bool for know if the menu indication
//	of user or player
Menu::Menu(const bool &comp)
{
	if(comp)
	{
		_sprite.push_back(MENU_ENM_L_3);
		_sprite.push_back(MENU_ENM_L_2);
		_sprite.push_back(MENU_ENM_L_1);
	}
	else
	{
		_sprite.push_back(MENU_USR_L_3);
		_sprite.push_back(MENU_USR_L_2);
		_sprite.push_back(MENU_USR_L_1);
	}
	_sprite.push_back(MENU_LOSE);
	_life = 0;
}

//=============================================================================
//	draw function
void Menu::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();

	switch(_life)
	{
		case 3:
			it = _sprite.begin();
			break;
		case 2:
			it = _sprite.begin()+1;
			break;
		case 1:
			it = _sprite.begin()+2;
			break;
		case 0:
			it = _sprite.begin()+3;
			break;
		default:
			it = _sprite.begin()+3;
			break;
	}

	it->Draw(_cord);
}

//=============================================================================
//	set life for each menu it is another life
void Menu::setLife(const short int &value)
{
	_life = value;
}
