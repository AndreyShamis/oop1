#include "bomb.h"


Bomb::Bomb()
{
	_bombCounter	=	0;
}
bool Bomb::putBomb(Vertex coordinate)
{
	Bomb_S temp_bomb;

	temp_bomb._coordinate	=	coordinate;
	temp_bomb._timer		=	4;
	_bombs.push_back(temp_bomb);
	_bombCounter++;
	return(true);
}
void Bomb::bombTurn()
{
	for (int i = 0; i < _bombCounter; i++)
	{
		_bombs[i]._timer-=1;

	}
}

int Bomb::bombCount()
{
	return(_bombCounter);
}

void Bomb::BlowUp(char map[][MAP_X],Vertex BlowCoordinate)
{
	map[BlowCoordinate._y][BlowCoordinate._x] = '*';

	map[BlowCoordinate._y][BlowCoordinate._x+1] = '*';
	map[BlowCoordinate._y][BlowCoordinate._x-1] = '*';

	map[BlowCoordinate._y+1][BlowCoordinate._x] = '*';
	map[BlowCoordinate._y-1][BlowCoordinate._x] = '*';

}

void Bomb::EraseBlowUp(char map[][MAP_X],Vertex BlowCoordinate)
{
	map[BlowCoordinate._y][BlowCoordinate._x] = ' ';

	map[BlowCoordinate._y][BlowCoordinate._x+1] = ' ';
	map[BlowCoordinate._y][BlowCoordinate._x-1] = ' ';

	map[BlowCoordinate._y+1][BlowCoordinate._x] = ' ';
	map[BlowCoordinate._y-1][BlowCoordinate._x] = ' ';

}

void Bomb::DrowBomb(char map[][MAP_X])
{
	for (int i = 0; i < _bombCounter; i++)
	{
		if(_bombs[i]._timer == 4)
			map[_bombs[i]._coordinate._y][_bombs[i]._coordinate._x] = 'B';
		else if(_bombs[i]._timer == 0)
		{
			BlowUp(map,_bombs[i]._coordinate);
		}
		else if(_bombs[i]._timer < 0)
		{
			EraseBlowUp(map,_bombs[i]._coordinate);
			_bombs.erase(_bombs.begin()+i);
			_bombCounter--;
		}
		else
			map[_bombs[i]._coordinate._y][_bombs[i]._coordinate._x] =  _bombs[i]._timer + 48;
	}
}