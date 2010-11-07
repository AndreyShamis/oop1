#pragma once
#include "Vertex.h"
#include "macros.h"


class Stairs
{

public:
	Stairs(Vertex bottomLeft,float height,float width,int numOfStairs);
	void move(Vertex shift);			//	moving the steirs by seting shift
	Vertex  getBotLeft();				//	return start coordinate in Vertex
	float getHeight();					//	return height
	float getWidth();					//	return width
	bool rotate(int angle);				//	rotate the steirs by angle * 90
	void draw(bool board[][MAX_Y+1]);

private:

	Vertex _bottomLeft;		//	Vertex coordinate
	float _height;			//	default height
	float _width;			//	default width

	float _width_use;		//	program drow using width
	float _height_use;		//	program drow using height
	bool _mirror;			//	2 and 4 square used

	int _angle;				//	real angle
	int _numOfStairs;		//	number of steirs
	
	//	private functions
	void setDefault();		//	set default parameters 	
	bool correctCheck(Vertex coor);	//	check if new data is correct
	void resetParam();		//	reset height and width from default
};