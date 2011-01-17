/*

	This class provide present-surprise class

	
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
	//	This function return the present type
	short int getPresentType();
private:
	short int _present_type;		//	indication to know what is the type of present
};
