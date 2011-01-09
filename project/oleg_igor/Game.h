
#pragma once

//#include "macros.h"
#include "Window.h"
#include "KeyBoard.h"
#include "GameObject.h"
#include "Wall.h"
#include "Box.h"
#include "Player.h"
#include <vector>

using namespace std ;



#define PROG_NAME "Play With Fire"

#define STAGE_1 "maps/stage2.txt"

#define WALL '#'
#define BOX 'O'

#define DEFAULT_WIN_HEIGHT 500
#define DEFAULT_WIN_WIDTH 550

#define MAX_BOARD_WIDTH 20
#define MAX_BOARD_HEIGHT 20

class Game{
public:

	Game();

	void play() ;

	                                                                                // to build distractor

private:

	static vector<GameObject*> _vec_objs;

	Window _window ;
	static KeyBoard _keyBoard ;

	static void idle();

	void read_board( char *file_name ) ;
};