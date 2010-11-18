#include "bomb.h"


Bomb::Bomb()
{
	_bombCounter	=	0;
}

void Bomb::clearBombsAll()
{	
	_bombCounter	=	0;
	_bombs.clear();
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
	int x = BlowCoordinate._x -1; 
	int y = BlowCoordinate._y -1; ; 
	for(int x1 = x;x1 < x+3;x1++)
	{
		if(x1 != BlowCoordinate._x)
		{
			if(map[BlowCoordinate._y][x1] == ' ' )
				map[BlowCoordinate._y][x1] = '*';
			else if(map[BlowCoordinate._y][x1] == 'O' )
				map[BlowCoordinate._y][x1] = '$';
		}
	}
	for(int y1 = y;y1 < y+3;y1++)
	{
		if(y1 != BlowCoordinate._y)
		{
			if(map[y1][BlowCoordinate._x] == ' ' )
				map[y1][BlowCoordinate._x] = '*';
			else if(map[y1][BlowCoordinate._x] == 'O' )
				map[y1][BlowCoordinate._x] = '$';
		}
	}
	map[BlowCoordinate._y][BlowCoordinate._x] = '*';


}

void Bomb::EraseBlowUp(char map[][MAP_X],Vertex BlowCoordinate)
{
	map[BlowCoordinate._y][BlowCoordinate._x] = ' ';

	int x = BlowCoordinate._x -1; 
	int y = BlowCoordinate._y -1; ; 
	for(int x1 = x;x1 < x+3;x1++)
	{
		if(x1 != BlowCoordinate._x)
		{
			if(map[BlowCoordinate._y][x1] == '*' )
				map[BlowCoordinate._y][x1] = ' ';
		}
	}
	for(int y1 = y;y1 < y+3;y1++)
	{
		if(y1 != BlowCoordinate._y)
		{
			if(map[y1][BlowCoordinate._x] == '*' )
				map[y1][BlowCoordinate._x] = ' ';
		}
	}

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

bool Bomb::checkBomb(const char map[][MAP_X],Vertex cord,char user)
{
 
	for (int i = 0; i < _bombCounter; i++)
	{
		int x = _bombs[i]._coordinate._x -1; 
		int y = _bombs[i]._coordinate._y -1; 

		if(_bombs[i]._timer == 0)
		{
			for(int x1 = x;x1 < x+3;x1++)
					if(map[_bombs[i]._coordinate._y][x1] == user )
						return(true);

			for(int y1 = y;y1 < y+3;y1++)
					if(map[y1][_bombs[i]._coordinate._x] == user )
						return(true);
		}
	}


	return false;


}