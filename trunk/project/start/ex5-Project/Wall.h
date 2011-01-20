/*

	This class provide  a well wich can not be exploded
	for more inforamtion about all function look to cpp file	
*/

#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;


class Wall:public Objects
{
public:
	//	Constructor
	Wall();

	//	Draw function
	void Draw();

};
