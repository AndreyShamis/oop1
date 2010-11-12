#include "drow.h"
#include <windows.h>

void PrintMap(const char map[][MAP_X],int bombCounter)
{
	int x	=	0;
		

	gotoTop();
	for(x=0;x<MAP_Y;x++)
	{
		cout << map[x];
		cout << "\n";
	}

	cout << bombCounter << "\n";
	
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

