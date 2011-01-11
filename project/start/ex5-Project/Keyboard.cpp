#include "Keyboard.h"
vector<Objects*> Keyboard:: _objects;

void Keyboard::Press(unsigned char key, int x, int y)
{
	vector<Objects*>::iterator it ;

	for( it =_objects.begin();it<_objects.end();it++ ) 
		(*it)->Press(key,x,y); ;
}
