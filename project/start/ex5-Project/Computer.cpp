#include "Computer.h"
#include <time.h>
Computer::Computer(void)
{
	_sprite.push_back("RGBA/enemy.d_rgba.txt");
	_sprite.push_back("RGBA/enemy.l_rgba.txt");
	_sprite.push_back("RGBA/enemy.r_rgba.txt");
	_sprite.push_back("RGBA/enemy.u_rgba.txt");
	_way = GO_UP;

	srand ((int)(time(0)));		// rand for computer turns
	intelect =1;
	movable = 0;
}

void Computer::VirtualPress()
{
		int turnCode;					//	variable be return
		turnCode	=	(rand()% 4) + 1	;

		switch(turnCode)
		{
		case 1:
			_way = GO_UP;
			break;
		case 2:
			_way = GO_DOWN;
			break;
		case 3:
			_way = GO_LEFT;
			break;
		case 4:
			_way = GO_RIGHT;
			break;
		}

}

