#include "player.h"


//======== Constructor ====================================
Player::Player()
{
	_haveTurn		=	true;	// can get new turn on map
	_haveBomb		=	true;	// can put bombs on map
	_alive			=	true;	// not killed
	_userSymbol		=	'+';
	_life			=	3;

	srand ((int)(time(0)));		// rand for computer turns


}
//======== SET coordinate =================================
void Player::setCoordinate(Vertex coordinate)
{
	_coordinate		=	coordinate;
	_newCoordinate	=	coordinate;

}
//======== GET coordinate =================================
Vertex Player::getCoordinate()
{
	return(_coordinate);
}
//======== SET Alive ======================================
void Player::setAlive(bool value)
{	
	_life =	3;
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
	if(_computerPlayer)
		_userSymbol = 'X';
	else
		_userSymbol = 'P';
}



bool Player::ifHaveTurn(const char map[][MAP_X],Vertex cord)
{
	int x =	cord._x;
	int y = cord._y;

	//if(this->CheckCorrect(map,)

	if(map[y-1][x] != LANE && map[y+1][x] != LANE && map[y-1][x] != PRESENT && map[y+1][x] != PRESENT
		&& map[y][x-1] != LANE && map[y][x+1] != LANE && map[y][x-1] != PRESENT && map[y][x+1] != PRESENT)
			return(false);
	//  ##
	//  #PB
	//	##
	//*/
	return(true);

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
short Player::getLife()
{
	return(_life);
}

void Player::decLife()
{
	this->_life--;

	if(this->_life<0)
		this->setAlive(false);

}
void Player::Turn(char map[][MAP_X],Bomb *bombs)
{
	int		turnCode;

	if(!ifHaveTurn(map,_coordinate))
		_haveTurn = false;

	while(_haveTurn)
	{
		turnCode = getInput();

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
			if(map[_newCoordinate._y][_newCoordinate._x] == PRESENT)
				bombs->putRandom(map);
				
			this->drowOnMap(map);
			break;
		}
		else
			continue;	
		
	}

	
	if(bombs->checkBomb(map,_newCoordinate,_userSymbol))
		this->decLife();
}

void Player::drowOnMap(char map[][MAP_X])
{
	map[_coordinate._y][_coordinate._x] = LANE;
	_coordinate		=	_newCoordinate;
	_haveTurn		=	false;
	map[_coordinate._y][_coordinate._x] = _userSymbol;
}

bool Player::CheckCorrect(const char map[][MAP_X], Vertex &newcoordinate)
{
	char value = map[newcoordinate._y][newcoordinate._x];

	if(value == LANE || value == PRESENT )
		return true;

	return false;

}

bool Player::HaveBomb()
{
	return(_haveBomb);
}

bool Player::HaveTurn()
{
	return(_haveTurn);
}