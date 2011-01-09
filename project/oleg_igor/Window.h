
#pragma once

#include "macros.h"
//#include "SomeObject.h"
#include "GameObject.h"


#define DEFAULT_POS_X 100
#define DEFAULT_POS_Y 100

class Window {

public:

	Window(int height, int width, char* prog_name ) ;

	void addObj( GameObject *obj ) ;

	static void display();

private:

	static vector<GameObject *> _vec_objs ;
	static int _width ;
	static int _height ;

	static void init();


};