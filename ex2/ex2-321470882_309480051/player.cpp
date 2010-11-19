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
void Player::setCoordinate(const Vertex &coordinate)
{
	_coordinate		=	coordinate;
	_newCoordinate	=	coordinate;

}
//======== GET coordinate =================================
Vertex Player::getCoordinate() const
{
	return(_coordinate);
}
//======== SET Alive ======================================
void Player::setAlive(bool value)
{	
	if(value)		//	if seting alive
		_life =	3;	//	give to user 3 life

	_alive = value;	//	set value
}

//======== GET Alive =========================================================
bool Player::getAlive() const
{
	return(_alive);
}

//======== SET SYMBOL ========================================================
//	may be X or P
void Player::setUserSymbol(const char new_sym)
{
	_userSymbol = new_sym;

}

//======== SET IF COMPUTER PLAYER ============================================
void Player::setIfComputer(const bool value)
{
	_computerPlayer = value;
}


/*
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
	//
	return(true);

}
*/

//=============================================================================
void Player::giveNewTurn()
{
	_haveTurn	=	true;
	_haveBomb	=	true;
}

//=============================================================================
int	Player::getInput() const
{
	if(_computerPlayer)
	{
		int turnCode	=	(rand()% 5) + 1	;
		int bomBrand    =	(rand()% 2) + 1	;

		if(bomBrand == 2 && turnCode == 5)
			turnCode	=	(rand()% 4) + 1;
		
		sleep(50);

		return(turnCode);
	}
	return(GetTurn());
}

/*
void Player::setWantStop(const bool value)
{
	_wantStop = value;
}

bool Player::getWantStop()
{
	return(_wantStop);
}
*/
//=============================================================================
short Player::getLife() const
{
	return(_life);
}

//=============================================================================
void Player::decLife()
{
	this->_life--;

	if(this->_life == 0)
		this->setAlive(false);

}

//=============================================================================
void Player::Turn(char map[][MAP_X],Bomb *bombs,Surprise *surp)
{
	int		turnCode;

	// if not have space to do turn set dont have turn 
	//if(!ifHaveTurn(map,_coordinate))
	//	_haveTurn = false;


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
		if(map[_coordinate._y][_coordinate._x] != BOMB)
		{
			bombs->putBomb(_coordinate);
			_haveBomb	=	false;
		}
	}


	if(this->CheckCorrect(map,_newCoordinate) && turnCode < 5)
	{
		if(map[_newCoordinate._y][_newCoordinate._x] == PRESENT)
		{
			int surp_type =surp->deleteSuprise(_newCoordinate);
			if(surp_type)
				bombs->putSurpriseBomb(surp_type,map);
		}	

		this->drowOnMap(map);
	}

	if(bombs->checkExplodeBomb(_coordinate))
		this->decLife();
	//if(bombs->checkBomb(map,_newCoordinate,_userSymbol))
	//	this->decLife();

	
}

//=============================================================================
void Player::drowOnMap(char map[][MAP_X])
{
	map[_coordinate._y][_coordinate._x] = LANE;
	_coordinate		=	_newCoordinate;
	_haveTurn		=	false;
	map[_coordinate._y][_coordinate._x] = _userSymbol;
}

//=============================================================================
bool Player::CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate)
{
	char value = map[newcoordinate._y][newcoordinate._x];

	if(value == LANE || value == PRESENT )
		return true;

	return false;

}

//=============================================================================
bool Player::HaveBomb() const
{
	return(_haveBomb);
}

//=============================================================================
bool Player::HaveTurn() const
{
	return(_haveTurn);
}