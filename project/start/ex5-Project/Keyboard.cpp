#include "Keyboard.h"
vector<Objects*> Keyboard:: _objects;

void Keyboard::Press(unsigned char key, int x, int y)
{
	vector<Objects*>::iterator it ;

	for( it =_objects.begin();it<_objects.end();it++ ) 
		(*it)->Press(key,x,y); ;
}

void Keyboard::SpecPress(int key, int x, int y)
{
	vector<Objects*>::iterator it ;

	for( it =_objects.begin();it<_objects.end();it++ ) 
		(*it)->SpecPress(key,x,y); ;
}

void Keyboard::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}