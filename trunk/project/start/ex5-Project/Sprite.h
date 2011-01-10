#pragma once
#include "Config.h"
#include <fstream>
#include <iostream>
#include <glut.h>
class Sprite
{
public:
	Sprite(const char* filename);
	void draw(float xPos, float yPos);
	RGBA **_image;
	int _height;
	int _width;
};
