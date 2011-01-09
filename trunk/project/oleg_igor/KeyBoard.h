
#pragma once

#include "macros.h"
#include "GameObject.h"

class KeyBoard {

public:

	KeyBoard() ;

	void addObj( GameObject *obj ) ;

	static void keyboard(unsigned char key, int x, int y);

private:
	static vector<GameObject*> _vec_objs ;

};