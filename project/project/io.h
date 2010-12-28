// A modul that manage input and output.
//	Module to work with user input .
//	Main function GetTurn, return game vector parameter
#pragma once

//                               Include section
//=============================================================================
#include <conio.h>
#include <iostream>


//                               Function section
//=============================================================================


int GetTurn();	//Get turn function.

//	geting char used in player when the game is over
//	and for show last time tu user the map
char getChar();


bool questionMess();	// Afunction that ask user if he want to exit the game.


