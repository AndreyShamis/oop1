// Configuration file.

#pragma once

// map limits:
#define MAP_X 21	
#define MAP_Y 20
//	this file include all constants used in program

// Define sign on map:
#define PRESENT '$'	
#define BOMB	'B'
#define FENCE	'#'
#define LANE	' '
#define BARREL	'O'
#define FIRE	'*'

//	surprise type:
#define BOMB_INC	1
#define BOMB_BLOW	2
#define BOMB_RAND	3

#define MAP_PATH_LEN 20	// lenth of row.

#define EXIT_GAME	10	//-	exit -game
#define SAVE_GAME	20	//-	save
#define NEW_GAME	30	//-	new game
#define KEY_UP	1	//up
#define KEY_DOWN	2	//down
#define KEY_LEFT	3	//left
#define KEY_RIGHT 	4	//right
#define KEY_BOMB	5	//put bomb

struct Vertex			// Coordinate.
{
		int _x;
		int _y;

};

