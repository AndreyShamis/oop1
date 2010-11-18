#pragma once

#define MAP_X 21
#define MAP_Y 20

#define PRESENT '$'
#define BOMB	'B'
#define FENCE	'#'
#define LANE	' '
#define BARREL	'O'
#define FIRE	'*'

//	surprise type
#define BOMB_INC	1
#define BOMB_BLOW	2
#define BOMB_RAND	3


struct Vertex
{
		int _x;
		int _y;

};

