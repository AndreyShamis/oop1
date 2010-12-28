#include "map.h"

map* map::_instance = NULL;

//=============================================================================
//	singleton :: getInsatnce of sigleton
//	if object not created create him
map* map::getInstance()
{
	if(_instance == NULL)
		_instance = new map;

	return _instance;

}

char map::getCellValue(const int &Y,const int &X) const
{
	return('a');
}

void map::setCellValue(const int &Y,const int &X,const char newValue)
{
	;
}

// A function that load from txt file, map of the game.
//=============================================================================
// Input: array to put map , and path to map file															
// Output: true if the map load was secsesful.
bool map::LoadMap( char path[MAP_PATH_LEN])
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
			//myReadFile.getline(map[counter],MAP_X);
			
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