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
// Input: array to put map , and path to map file															
// Output: true if the map load was secsesful.
bool LoadMap()
{
	// Open file.
	ifstream myReadFile;
	myReadFile.open("MAPS/map1.txt");

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