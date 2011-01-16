#pragma once
#include "Config.h"
#include <fstream>
#include <iostream>
#include <glut.h>
#include <string.h>
class Sprite
{
public:
	Sprite(const char* filename);
	~Sprite();
	void Draw(const Vertex &cord);
	RGBA **_image;
	int _height;
	int _width;
	
};
