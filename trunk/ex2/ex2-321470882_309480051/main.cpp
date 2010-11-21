/*
 * EX2:: GAME: BOMBER MAN.
 *
 * 
 * 
 * ============================================================================
 * Writen by: Andrey Shamis,  id: 321470882, login: andreysh
 * and:       Ilia Gaisinsky, id: 309480051, login: iliaga
 *      =======================================================================
 *     
*/

//                               Include section
//=============================================================================
#include <stdlib.h>
#include "gameController.h"

//                                 Main section
//=============================================================================
int main()
{

	// Criate object of the class game controler (class of the game).
	GameController game = GameController();
	
	// Open game menu. 
	game.Menu();
	return(EXIT_SUCCESS);
}

//=============================================================================