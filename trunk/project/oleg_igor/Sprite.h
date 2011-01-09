
#pragma once
//#include "macros.h"
//#include <GL/glut.h>
//#include <stdlib.h>
#include <fstream>

#include <GL/glut.h>

using namespace std ;

struct RGBA{
	float  _r, _g, _b, _a;
};


class Sprite{
	
public:
	Sprite(const char* filename);
	void draw(float xPos, float yPos);
	int getWidth() ;
	int getHeight() ;
private:
	int _height;
	int _width;
	RGBA** _imageMatrix;
};