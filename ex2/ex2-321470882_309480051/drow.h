// A modul (class ////TODO) that reprisent drowing to the screen tasks.

//                               Include section
//=============================================================================
#include <windows.h>
#include <winbase.h>
#include <time.h>
#pragma once
#include <iostream>
#include "config.h"


using namespace std;	// TODO


//                               Function section
//=============================================================================

// A function that make dilay.
void sleep(unsigned int mseconds);

// A function that print the map of game fild.
void PrintMap(const char map[][MAP_X]);

// A function that Places the cursor in the top left corner of the console 
// screen.
void gotoTop();

// A function that print life status of user and the computer.
void printLifes(const int &user1Life,const int &user2Life);

// A function that print turn counter
void printTurnCounter(const int &counter);

// A function that print surprise information.
void printSurpriseInfo(const int &,const int &);

// A function that print surprise discription depend on surprise type.
void surpDescription(const short &pr);

