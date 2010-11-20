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
	Vertex	getCoordinate()const;
	void	setCoordinate(const Vertex &coordinate);
	bool	HaveBomb() const;
	bool	HaveTurn() const;
	void	Turn(char map[][MAP_X],Bomb *bombs,Surprise *surp,bool &exit);
	void	giveNewTurn();
	bool	getAlive()const;
	void	setAlive(bool);
	void	setIfComputer(const bool value);
	short	getLife() const;
	short	getPresent() const;
	
	void	drowOnMap(char map[][MAP_X]);
	void	setUserSymbol(const char new_sym);
	
	//bool	ifHaveTurn(const char map[][MAP_X],Vertex cord);
	//void	setWantStop(const bool value);
	//bool	getWantStop();
private:
	int		getInput() const; 
	void	decLife();	
	void	setPresent(const short &value);
	bool	CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate);

	Vertex		_coordinate;
	Vertex		_newCoordinate;
	bool		_haveBomb;
	bool		_haveTurn;
	bool		_computerPlayer;
	bool		_alive;
	//bool		_wantStop;
	char		_userSymbol;
	short int	_life;
	short int	_presentGeted;
	

};