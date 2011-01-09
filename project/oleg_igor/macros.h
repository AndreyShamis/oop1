
#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "Controlable.h"
#include "GameObject.h"

using namespace std;

struct RGB{
	float _r, _g, _b;
};

enum direction {
	UP,DOWN,LEFT,RIGHT,NONE
};

