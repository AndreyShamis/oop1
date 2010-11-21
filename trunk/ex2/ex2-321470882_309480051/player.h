// A class that reprisent player.

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

	void	setIfComputer(const bool value);	// SET IF COMPUTER PLAYER

	// A function that return how meny life player have.
	short	getLife() const;

	// A function that get which present user get-have.
	short	getPresent() const;
	
	void setEnemyCord(Vertex cord);
	// A function that drow on map the user. 
	void	drowOnMap(char map[][MAP_X]);

	void	setUserSymbol(const char new_sym);		// SET SYMBOL
	
private:

	void turnLogic(const int &turnCode);

	// A function that get turn derection from user.
	int		getInput(const char map[][MAP_X],Bomb *bombs);

	// A function that decrease life counter.
	void	decLife();	

	// A function that set type of present to user.
	void	setPresent(const short &value);

	// A function that check if new coordinates is correct 
	bool	CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate);

	short getTurnCodeByDetectEnemy();
	
	bool checkEnemyinBombRaound();

	short CompIntellect(const char map[][MAP_X],Bomb *bombs);


//                              veribel section
//=============================================================================

	Vertex		_coordinate;	// curent step.
	Vertex		_newCoordinate; // next step.
	Vertex		_enemyCord;
	bool		_haveBomb;		// Difine bomb.
	bool		_haveTurn;		// Difine howes Turn.
	bool		_computerPlayer; // Difine if the player is computer.
	bool		_alive;			// Difine if the player is alive.
	char		_userSymbol;	// Difine player Symbol.
	short int	_life;			// Difine life counter.
	short int	_presentGeted;	//														//TODO
	
	int			_computerTryDetectEnemy;

};