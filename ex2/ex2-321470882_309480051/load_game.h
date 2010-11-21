// A modul that load game maps from txt file.

//                               Include section
//=============================================================================
#include "config.h"
#include <fstream>
#include <iostream>

//                               Using section
//=============================================================================
using namespace std;

//                               Function section
//=============================================================================

// A function that load from txt file, map of the game.
bool LoadMap(char map[][MAP_X], char path[MAP_PATH_LEN]);