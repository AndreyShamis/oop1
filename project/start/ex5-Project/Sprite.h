/*
	Sprite class
*/

#pragma once
#include "Config.h"
#include <fstream>
#include <iostream>
#include <glut.h>
#include <string.h>
class Sprite
{
public:
	//=============================================================================
	// Constructor
	Sprite(const char* filename);
	//=============================================================================
	//	Draw function
	void Draw(const Vertex &cord);
	//=============================================================================
	//	return height
	int getHeight();
	//=============================================================================
	//	return width
	int getWidth();
private:
	RGBA **_image;
	int _height;		//	height of image
	int _width;			//	width of image
	
};
