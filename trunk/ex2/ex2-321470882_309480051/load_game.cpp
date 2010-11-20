#include "load_game.h"
#include <fstream>
#include <iostream>

//=============================================================================
bool LoadMap(char map[][MAP_X], char path[MAP_PATH_LEN])
{

	ifstream myReadFile;
	myReadFile.open(path);

	if (myReadFile.is_open()) 
	{
		int counter = 0;
		while (!myReadFile.eof())
		{

			myReadFile.getline(map[counter],MAP_X);
			
			counter++;
		}
	}
	else
	{
		return(false);
	}
	myReadFile.close();

	return(true);
}