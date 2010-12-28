// A class that reprisent player.
//	Class player. The entire logic of the player and the computer logic 
//	is in that file. For better understanding see the description of 
//	functions. It is worth noting that the class starts in two copies, 
//	one for the player and one for the computer.
//	There is also an interesting option to install the game between two 
//	computers. This is done in the class gameController(see readme)
#pragma once

//                               Include section
//=============================================================================
#include <iostream>
#include <windows.h>
#include <stdlib.h>	// for rand
#include <time.h>

#include "config.h"
#include "io.h"
#include "drow.h"
#include "bomb.h"



class Player
{
public :

//                               Function section
//=============================================================================

	
	Player();	// Constructor.
	Vertex	getCoordinate()const;	// GET coordinate
	void	setCoordinate(const Vertex &coordinate);	// SET coordinate
	// A function that difine if user have bomb in this cycle.
	bool	HaveBomb() const;
	// A function that report if the user have turn.
	bool	HaveTurn() const;
	// A function that make player turn.
	void	Turn(char map[][MAP_X],Bomb *bombs,Surprise *surp,bool &exit);
	void	giveNewTurn(); //A function that give to user new turn in new cycle
	bool	getAlive()const;	// GET Alive
	void	setAlive(bool);		// SET Alive
	// A function that return how meny life player have.
	short	getLife() const;
	// A function that get which present user get-have.
	short	getPresent() const;
	// A function that set enemy coordinate.
	void	setEnemyCord(Vertex cord);
	// A function that drow on map the user. 
	void	drowOnMap(char map[][MAP_X]);
	void	setUserSymbol(const char new_sym);		// SET SYMBOL
	
protected:
	
	// A function that convert logic code of potential next step of computer 
	// player.
	void turnLogic(const int &turnCode);
	virtual int	getInput(const char map[][MAP_X],Bomb *bombs)=0;
	
	// A function that decrease life counter.
	void	decLife();	
	// A function that set type of present to user.
	void	setPresent(const short &value);
	// A function that check if new coordinates is correct 
	bool	CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate);
	

//                              veribel section
//=============================================================================

	Vertex		_coordinate;	// curent step.
	Vertex		_newCoordinate; // next step.
	Vertex		_enemyCord;		// Difine enemy coordinate.
	bool		_haveBomb;		// Difine bomb.
	bool		_haveTurn;		// Difine howes Turn.
	bool		_computerPlayer; // Difine if the player is computer.
	bool		_alive;			// Difine if the player is alive.
	char		_userSymbol;	// Difine player Symbol.
	short int	_life;			// Difine life counter.
	short int	_presentGeted;	// The type of presnt which was geted.
								//	in last time.
	int			_computerTryDetectEnemy; // Difine direction of enemy.

};