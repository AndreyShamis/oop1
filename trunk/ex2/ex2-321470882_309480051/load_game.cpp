#include "load_game.h"
#include <fstream>
#include <iostream>

//=============================================================================
void LoadMap(char map[][MAP_X])
{

	ifstream myReadFile;
	myReadFile.open("map3.txt");

	if (myReadFile.is_open()) 
	{
		int counter = 0;
		while (!myReadFile.eof())
		{

			myReadFile.getline(map[counter],MAP_X);
			
			counter++;
		}
	}

	myReadFile.close();

}