// A class (////TODO) that reprisent drowing to the screen tasks.

//                               Include section
//=============================================================================
#include "drow.h"
#include <windows.h>

//                               Function section
//=============================================================================

// A function that print the map of game fild.
//=============================================================================
// Input: map.
void PrintMap(const char map[][MAP_X])				//TODO
{
	int x	=	0;
	
	system("cls");
	
	for(x=0;x<MAP_Y;x++)
	{
		cout << map[x];
		cout << "\n";
	}
	
}

// A function that print life status of user and the computer.
//=============================================================================
// Input: user and computer life couners (resived by refference)
void printLifes(const int &user1Life,const int &user2Life)
{
	cout << "\n\t# - You have " << user1Life << " lifes.\n";
	cout << "\t# - Computer have " << user2Life << " lifes.\n";

}

// A function that print turn counter
//=============================================================================
// Input: turn counter.
void printTurnCounter(const int &counter)
{
	cout << "\t TURN N: " << counter << ".\n";
}

//=============================================================================
/*void PrintMenu()
{
	cout	<<	"\n\t\t### GAME MENU ###\n"
			<<	"\t\tn - New Game\n"
			<<	"\t\tq - Exit.\n";

}

/*
* Places the cursor in the top left corner of the console screen
*/

// A function that Places the cursor in the top left corner of the console 
// screen.
//=============================================================================
void gotoTop()
{
	HANDLE screen_buffer_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(screen_buffer_handle, coord);
}

// A function that make dilay.
//=============================================================================
// Input: dilay time (in seconds).
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + (clock());
	while (goal > clock());
}