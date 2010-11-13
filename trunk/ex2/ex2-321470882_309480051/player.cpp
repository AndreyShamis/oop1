#include "player.h"


//======== Constructor ====================================
Player::Player()
{
	_haveTurn		=	true;	// can get new turn on map
	_haveBomb		=	true;	// can put bombs on map
	_alive			=	true;	// not killed
	srand ((int)(time(0)));		// rand for computer turns

}
//======== SET coordinate =================================
void Player::setCoordinate(Vertex coordinate)
{
	_coordinate = coordinate;

}
//======== GET coordinate =================================
Vertex Player::getCoordinate()
{
	return(_coordinate);
}
//======== SET Alive ======================================
void Player::setAlive(bool value)
{
	_alive = value;
}
//======== GET Alive ======================================
bool Player::getAlive()
{
	return(_alive);
}

void Player::setIfComputer(bool value)
{
	_computerPlayer = value;

}



bool Player::ifHaveTurn(const char map[][MAP_X],Vertex cord)
{
	int x =	cord._x;
	int y = cord._y;

	//if(this->CheckCorrect(map,)

	if(map[y-1][x] != ' ' && map[y+1][x] != ' ' && map[y-1][x] != '$' && map[y+1][x] != '$'
		&& map[y][x-1] != ' ' && map[y][x+1] != ' '&& map[y][x-1] != '$' && map[y][x+1] != '$')
			return(false);
	//  ##
	//  #PB
	//	##
	//*/
	return(true);

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
		int turnCode	=	(rand()% 5) + 1	;
		int bomBrand    =	(rand()% 2) + 1	;

		if(bomBrand == 2 && turnCode == 5)
			turnCode	=	(rand()% 4) + 1;
			
		return(turnCode);
	}
	return(GetTurn());
}

void Player::setWantStop(bool value)
{
	_wantStop = value;
}

bool Player::getWantStop()
{
	return(_wantStop);
}
void Player::Turn(char map[][MAP_X],Bomb *bombs)
{
	int		turnCode;
	char		user;

	if(!ifHaveTurn(map,_coordinate))
		_haveTurn = false;

	
	if(_computerPlayer)
		user = 'X';
	else
		user = 'P';

	while(_haveTurn)
	{
		turnCode = getInput();
		/*
		if(turnCode == 10 && questionMess())
			exit(EXIT_SUCCESS);

		else if(turnCode == 30 && questionMess())
		{
			setWantStop(true);
			break;
		}
		*/

		//	set new coordinate be real coordinate
		_newCoordinate	=	_coordinate;	

		if(turnCode == 1 && _coordinate._y-1 > 0)
			_newCoordinate._y--;
		else if(turnCode == 2 && _coordinate._y+1 < MAP_Y -1)
			_newCoordinate._y++;
		else if(turnCode == 3 && _coordinate._x-1 >0)
			_newCoordinate._x--;
		else if(turnCode == 4 && _coordinate._x+1 < MAP_X-1)
			_newCoordinate._x++;
		else if(turnCode	==	5 && _haveBomb)
		{
			bombs->putBomb(_coordinate);
			_haveBomb	=	false;
		}
		else
			continue;

		if(this->CheckCorrect(map,_newCoordinate) && turnCode < 5)
		{
			map[_coordinate._y][_coordinate._x] = ' ';
			_coordinate		=	_newCoordinate;
			_haveTurn		=	false;
			map[_coordinate._y][_coordinate._x] = user;
			break;
		}
		else
			continue;	
		
	}

	
	if(bombs->checkBomb(map,_newCoordinate,user))
		setAlive(false);
	
}


bool Player::CheckCorrect(const char map[][MAP_X], Vertex &newcoordinate)
{
	char value = map[newcoordinate._y][newcoordinate._x];

	if(value == ' ' || value == '$' )
		return true;

	return false;

}
