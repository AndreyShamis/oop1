
#pragma once

//#include "macros.h"

//#include <vector>
//#include "GameObject.h"

class Controlable {
public:
	
//	virtual void move( /*vector<GameObject *> _vec_objs */) = 0 ;

	virtual void keyboard(unsigned char key, int x, int y) = 0; 

private:

};