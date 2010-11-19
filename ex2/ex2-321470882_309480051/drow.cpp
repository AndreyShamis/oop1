#include "drow.h"
#include <windows.h>

//=============================================================================
void PrintMap(const char map[][MAP_X])
{
	int x	=	0;
	
	
	system("cls");
	
	for(x=0;x<MAP_Y;x++)
	{
		cout << map[x];
		cout << "\n";
	}
	
}

//=============================================================================
void printLifes(const int &user1Life,const int &user2Life)
{
	cout << "You have " << user1Life << " lifes.\n";
	cout << "Computer have " << user2Life << " lifes.\n";

}

//=============================================================================
void printTurnCounter(const int &counter)
{
	cout << "TURN: " << counter << "\n";
}

//=============================================================================
void PrintMenu()
{
	cout	<<	"\n\t\t### GAME MENU ###\n"
			<<	"\t\tn - New Game\n"
			<<	"\t\tq - Exit.\n";

}

/*
* Places the cursor in the top left corner of the console screen
*/
void gotoTop()
{
	HANDLE screen_buffer_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(screen_buffer_handle, coord);
}

//=============================================================================
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + (clock());
	while (goal > clock());
}