#pragma once
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
	Player();

	Vertex getCoordinate();

	void setCoordinate(Vertex coordinate);

	bool	HaveBomb();
	bool	HaveTurn();
	void	Turn(char map[][MAP_X],Bomb *bombs,Surprise *surp);
	void	giveNewTurn();
	bool	getAlive();
	void	setAlive(bool);
	bool	ifHaveTurn(const char map[][MAP_X],Vertex cord);
	void	setIfComputer(const bool value);
	void	setWantStop(bool value);
	bool	getWantStop();
	short	getLife();
	void	drowOnMap(char map[][MAP_X]);
	void	setUserSymbol(const char new_sym);

private:

	int		getInput();
	void	decLife();	

	Vertex	_coordinate;
	Vertex	_newCoordinate;
	bool	CheckCorrect(const char map[][MAP_X], Vertex &newcoordinate);

	bool	_haveBomb;
	bool	_haveTurn;
	bool	_computerPlayer;
	bool	_alive;
	bool	_wantStop;
	char	_userSymbol;

	short int	_life;
	

};