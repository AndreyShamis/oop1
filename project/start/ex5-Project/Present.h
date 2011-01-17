/*

	This class provide 


	
*/

#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>

using namespace std ;
class Present:public Objects
{
public:
	Present();
	virtual void Draw();
	short int getPresentType();
private:
	//	This function return the present type
	short int _present_type;
};
