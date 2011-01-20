#include "Level.h"

//=============================================================================
//	Class constructor 
Level::Level()
{
	_sprite.push_back(LEVEL_1_PIC);
	_sprite.push_back(LEVEL_2_PIC);
	_sprite.push_back(LEVEL_3_PIC);
	_sprite.push_back(LEVEL_4_PIC);
	_sprite.push_back(LEVEL_5_PIC);
	_level = 1;
}


//=============================================================================
//	Function to draw object
void Level::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	int some_lvl = _level-1;

	it = _sprite.begin()+some_lvl;


	it->Draw(_cord);
}

//=============================================================================
//	Function to set level
void Level::setLevel(const int &level)
{
	_level =level;
}