#include <windows.h>
#include <winbase.h>
#include <time.h>
#pragma once
#include <iostream>


#include "config.h"


using namespace std;	// TODO



void sleep(unsigned int mseconds);

void PrintMap(const char map[][MAP_X]);
void printSurpriseInfo(const int &,const int &);
void surpDescription(const short &pr);
/*
* Places the cursor in the top left corner of the console screen
*/
void gotoTop();
void printLifes(const int &user1Life,const int &user2Life);
void printTurnCounter(const int &counter);



