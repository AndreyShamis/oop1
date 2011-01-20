#include "Keyboard.h"
vector<Objects*> Keyboard:: _objects;

//=============================================================================
//	Special key  function used in glud
void Keyboard::Press(unsigned char key, int x, int y)
{
	vector<Objects*>::iterator it ;

	for( it =_objects.begin();it<_objects.end();it++ ) 
		(*it)->Press(key,x,y); ;
}

//=============================================================================
//	Special key press function used in glud
void Keyboard::SpecPress(int key, int x, int y)
{
	vector<Objects*>::iterator it ;

	for( it =_objects.begin();it<_objects.end();it++ ) 
		(*it)->SpecPress(key,x,y); ;
}

//=============================================================================
//	add object to vector
void Keyboard::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}

//=============================================================================
//	Clear object from vector
void Keyboard::ClearObjects()
{
	_objects.clear();
}