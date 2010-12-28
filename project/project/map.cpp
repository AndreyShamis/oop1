#include "map.h"

map* map::_instance = NULL;

//=============================================================================
//	singleton :: getInsatnce of sigleton
//	if object not created create him
map* map::getInstance()
{
	if(_instance == NULL)
		_instance = new map;

	return _instance;

}

char map::getCellValue(const int &Y,const int &X) const
{
	return('a');
}

void map::setCellValue(const int &Y,const int &X,const char newValue)
{
	;
}