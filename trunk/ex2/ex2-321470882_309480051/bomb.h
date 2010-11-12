#pragma once
#include "config.h"
#include <vector>
struct Bomb_S
{
	Vertex		_coordinate;
	short int	_timer;

};

class Bomb
{
public:
	Bomb();
	bool	putBomb(Vertex coordinate);
	void	bombTurn();
	int		bombCount();
	void	DrowBomb(char map[][MAP_X]);
	void	BlowUp(char map[][MAP_X],Vertex BlowCoordinate);
	void	EraseBlowUp(char map[][MAP_X],Vertex BlowCoordinate);
	void	clearBombsAll();
	bool	checkBomb(const char map[][MAP_X],Vertex cord,char user);

	
private:

	void DeleteBomb(int indexOfBomb);

	int				_bombCounter;
	std::vector <Bomb_S>_bombs;

};