#include "player.h"



Player::Player(Vertex coordinate,bool Computer)
{
	_coordinate		=	coordinate;
	_haveTurn		=	true;
	_haveBomb		=	true;
	_computerPlayer	=	Computer;
	srand ((int)(time(0)));

}
Vertex Player::getCoordinate()
{
	return(_coordinate);
}

bool Player::HaveBomb()
{
	return(_haveBomb);
}

bool Player::HaveTurn()
{
	return(_haveTurn);
}

void Player::giveNewTurn()
{
	_haveTurn	=	true;
	_haveBomb	=	true;
}

int	Player::getInput()
{
	if(_computerPlayer)
	{
		
		int turnCode	=	(rand()% 4) + 1	;
		return(turnCode);
	}
	return(GetTurn());
}

void Player::Turn(char map[][MAP_X],Bomb *bombs)
{
	int turnCode;

	while(_haveTurn)
	{
		turnCode = getInput();

		_newCoordinate	=	_coordinate;

		if(turnCode == 1 && _coordinate._y-1 > 0)
		{
			_newCoordinate._y--;
		}
		else if(turnCode == 2 && _coordinate._y+1 < MAP_Y-1)
		{
			_newCoordinate._y++;
		}
		else if(turnCode == 3 && _coordinate._x-1 >0)
		{
			_newCoordinate._x--;
		}
		else if(turnCode == 4 && _coordinate._x+1 < MAP_X-1)
		{
			_newCoordinate._x++;
		}
		else if(turnCode	==	5 && _haveBomb)
		{
			bombs->putBomb(_coordinate);
			_haveBomb	=	false;
		}
		else
			continue;


		if(CheckCorrect(map,_newCoordinate) && turnCode < 5)
		{
			map[_coordinate._y][_coordinate._x] = ' ';
			_coordinate		=	_newCoordinate;
			_haveTurn		=	false;

			if(_computerPlayer)
				map[_coordinate._y][_coordinate._x] = 'X';
			else
				map[_coordinate._y][_coordinate._x] = 'P';

			break;
			//PrintMap(map);
			//turnCode = GetTurn();
		}
		else
		{
			continue;
		}

		if(turnCode == 99)
		{
			;
		}
		
		
	}
	
}

bool Player::CheckCorrect(const char map[][MAP_X], Vertex &newcoordinate)
{
	char value = map[newcoordinate._y][newcoordinate._x];

	if(value == ' ' || value == '$' )
		return true;

	return false;

}
