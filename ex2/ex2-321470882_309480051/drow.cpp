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
	cout << "\n\t# - You have " << user1Life << " lifes.\n";
	cout << "\t# - Computer have " << user2Life << " lifes.\n";

}

//=============================================================================
void printTurnCounter(const int &counter)
{
	cout << "\t TURN N: " << counter << ".\n";
}

//=============================================================================
void printSurpriseInfo(const int &usr1_pr,const int &usr2_pr)
{
	if(usr1_pr)
	{
		std::cout << "Player 1 get ";
		surpDescription(usr1_pr) ;
		std::cout << ".\n";
	}
	if(usr2_pr)
	{
		std::cout << "Player 2 get ";
		surpDescription(usr2_pr) ;
		std::cout << ".\n";
	}
}

void surpDescription(const short &pr)
{
	switch(pr)
	{
	case BOMB_INC:
		std::cout << " increase time by +5";
		break;
	case BOMB_BLOW:
		std::cout << " blowup all bombs";
		break;
	case BOMB_RAND:
		std::cout << " put random bomb";
		break;

	}
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