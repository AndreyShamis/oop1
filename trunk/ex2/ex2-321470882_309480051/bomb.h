// A class that reprisent bomb.

#pragma once

//                               Include section
//=============================================================================
#include "config.h"
#include "surprise.h"
#include <vector>


//                               Difinetion section
//=============================================================================
#define START_TIME 4 // Difine start time of bomb timer.


//                               Structur section
//=============================================================================
// Difine bomb stractur.
struct Bomb_S
{
	Vertex		_coordinate;
	short int	_timer;
	short int	_alltime;

};

class Bomb
{
//                               Function section
//=============================================================================
public:
	// Constractor.
	Bomb();	
	// A function that criate new bomb and put it at the map.
	bool	putBomb(Vertex coordinate);

	// A function that deccrease timers of all bombs.
	void	bombTurn();

	// A function that return bomb counter.         
	int		bombCount();

	//	A function that draws the bombing.
	void	DrowBomb(char map[][MAP_X],Surprise *surp);

	// A function that clear all boms from game fild and reset bomb counter.
	void	clearBombsAll();

	// A function that check if the player is now on the bomb that will explode
	// now
	bool	checkExplodeBomb(const Vertex &user_cord, const int &intime);

	// A fanction that realize the implications of surpris on bombs.
	void	putSurpriseBomb(const short type,char map[][MAP_X]);

	bool	checkIfCellHaveBomb(const Vertex &cell);
	
private:

	// A function that drow bombs blowup end erease the fire from map
	void	BlowUp(char map[][MAP_X],const Vertex &BlowCoord,Surprise *surp);

	// A function that increase timers of all boms. 
	void	increaaseTimer();

	// A fanction that blowup all bomb at the map.
	void	BlowUpAll();

	// A function that rundomly put bomb at map.
	void	putRandom(char map[][MAP_X]);

	// A fanction that erase the blowed-up bomb
	void	EraseBlowUp(char map[][MAP_X],const Vertex &BlowCoord);

//                              veribel section
//=============================================================================

	int				_bombCounter;	// Difine bombs counter
	std::vector <Bomb_S>_bombs;		// Difine Bombs vector.

};