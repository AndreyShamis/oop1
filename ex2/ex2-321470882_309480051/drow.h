#pragma once
#include <iostream>
#include "config.h"

using namespace std;	// TODO


void PrintMap(const char map[][MAP_X],int bombCounter);

/*
* Places the cursor in the top left corner of the console screen
*/
void gotoTop();
void printLifes(const int &user1Life,const int &user2Life);
void printTurnCounter(const int &counter);



