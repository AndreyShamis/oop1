#include "drow.h"


void PrintMap(const char map[][MAP_Y])
{
	int x	=	0,
		y	=	0;

	for(x=0;x<MAP_X;x++)
	{
		//for(y=0;y<MAP_Y;y++)
		//{
			cout << map[x];
		//}
		cout << "\n";
	}

}