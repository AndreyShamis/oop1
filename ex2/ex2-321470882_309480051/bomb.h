#pragma once
#include "config.h"
#include "surprise.h"
#include <vector>

#define START_TIME 4

struct Bomb_S
{
	Vertex		_coordinate;
	short int	_timer;
	short int	_alltime;

};

class Bomb
{
public:
	Bomb();
	bool	putBomb(Vertex coordinate);
	void	bombTurn();
	int		bombCount();
	void	DrowBomb(char map[][MAP_X],Surprise *surp);

	void	clearBombsAll();
	bool	checkExplodeBomb(const Vertex &user_cord);
	//bool	checkBomb(const char map[][MAP_X],Vertex cord,char user);
	void	putSurpriseBomb(const short type,char map[][MAP_X]);

	
private:

	//void	DeleteBomb(const int &indexOfBomb);
	void	BlowUp(char map[][MAP_X],const Vertex &BlowCoord,Surprise *surp);
	void	increaaseTimer();
	void	BlowUpAll();
	void	putRandom(char map[][MAP_X]);
	void	EraseBlowUp(char map[][MAP_X],const Vertex &BlowCoord);

	int				_bombCounter;
	std::vector <Bomb_S>_bombs;

};