

#include "KeyBoard.h"

vector<GameObject*> KeyBoard:: _vec_objs;

KeyBoard::KeyBoard() { }

void KeyBoard::addObj( GameObject *obj ) {
	_vec_objs.push_back( obj ) ;
};

// A callback function for the event of a keyboard button pressed
void KeyBoard::keyboard(unsigned char key, int x, int y) { 

	vector<GameObject*>::iterator it ;

	for( it =  _vec_objs.begin() ; it < _vec_objs.end() ; it++ ) {
		(*it)->keyboard(key,x,y); ;
	}
}