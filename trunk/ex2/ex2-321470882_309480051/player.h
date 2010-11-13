#pragma once
#include <iostream>
#include <time.h>
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

	bool HaveBomb();
	bool HaveTurn();
	void Turn(char map[][MAP_X],Bomb *bombs);
	void giveNewTurn();
	bool getAlive();
	void setAlive(bool);
	bool ifHaveTurn(const char map[][MAP_X],Vertex cord);
	void setIfComputer(bool value);
	void setWantStop(bool value);
	bool getWantStop();



private:

	int		getInput();
	

	Vertex	_coordinate;
	Vertex	_newCoordinate;
	bool	CheckCorrect(const char map[][MAP_X], Vertex &newcoordinate);

	bool	_haveBomb;
	bool	_haveTurn;
	bool	_computerPlayer;
	bool	_alive;
	bool	_wantStop;
	

};