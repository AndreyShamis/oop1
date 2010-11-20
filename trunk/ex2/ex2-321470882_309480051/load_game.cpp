// A modul that load game maps from txt file.

//                               Include section
//=============================================================================
#include "load_game.h"
#include <fstream>
#include <iostream>

//                               Function section
//=============================================================================


// A function that load from txt file, map of the game.
//=============================================================================
// Input: 2D char array,															//TODO
/// Output: true if the map load was secsesful.
bool LoadMap(char map[][MAP_X], char path[MAP_PATH_LEN])
{
	// Open file.
	ifstream myReadFile;
	myReadFile.open(path);

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		int counter = 0; // Difine num of line.
		while (!myReadFile.eof())
		{
			// Load line to array.
			myReadFile.getline(map[counter],MAP_X);
			
			counter++; // Increase num of line.
		}
	}
	else
	{
		return(false);
	}
	// Close the file.
	myReadFile.close();

	return(true);
}