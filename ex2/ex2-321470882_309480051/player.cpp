#include "player.h"


//======== Constructor ====================================
Player::Player()
{
	_haveTurn		=	true;	// can get new turn on map
	_haveBomb		=	true;	// can put bombs on map
	_alive			=	true;	// not killed
	_userSymbol		=	'+';	// set unset user symbol
	_life			=	3;		// give user 3 life
	setPresent(0);				// set unset presents have
	
	//	rand for computer player
	srand ((int)(time(0)));		// rand for computer turns


}
//======== SET coordinate =================================
void Player::setCoordinate(const Vertex &coordinate)
{
	_coordinate		=	coordinate;	//	set start coordinates
	_newCoordinate	=	coordinate;	//	temp start coordinates

}
//======== GET coordinate =================================
//	return user coordinates
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

//======== SET IF COMPUTER PLAYER =============================================
//	set if the player is computer
//	true - computer
//	false - human
void Player::setIfComputer(const bool value)
{
	_computerPlayer = value;
}

//=============================================================================
//	give to user new turn in new cycle
void Player::giveNewTurn()
{
	_haveTurn	=	true;	//	give options turn
	_haveBomb	=	true;	//	give oprions put bombs
	setPresent(0);			//	set don`t have any presents
}

//=============================================================================
//	return turn derection
int	Player::getInput(const char map[][MAP_X])
{
	//	computer logic
	if(_computerPlayer)
	{
		int turnCode	=	(rand()% 5) + 1	;
		int bomBrand    =	(rand()% 2) + 1	;

		if(bomBrand == 2 && turnCode == 5)
			turnCode	=	(rand()% 4) + 1;
		
		sleep(50);

		return(turnCode);
	}
	//	player logic
	return(GetTurn());
}

//=============================================================================
//	return how meny life player have
short Player::getLife() const
{
	return(_life);
}

//=============================================================================
//	decrease life counter
void Player::decLife()
{
	_life--;				//	decrese life

	if(_life == 0)			//	if no more life
		setAlive(false);	//	set dead

}

//=============================================================================
void Player::Turn(char map[][MAP_X],Bomb *bombs,Surprise *surp,bool &exit)
{
	int		turnCode;

	turnCode = getInput(map);

	//	set new coordinate be real coordinate
	_newCoordinate	=	_coordinate;	

	//	turn logic
	if(turnCode == KEY_UP && _coordinate._y-1 > 0)
		_newCoordinate._y--;
	else if(turnCode == KEY_DOWN && _coordinate._y+1 < MAP_Y -1)
		_newCoordinate._y++;
	else if(turnCode == KEY_LEFT && _coordinate._x-1 >0)
		_newCoordinate._x--;
	else if(turnCode == KEY_RIGHT && _coordinate._x+1 < MAP_X-1)
		_newCoordinate._x++;
	else if(turnCode ==	KEY_BOMB && _haveBomb)
	{
		//	bomb logic
		if(map[_coordinate._y][_coordinate._x] != BOMB)
		{
			//	put bomb to bomb database
			bombs->putBomb(_coordinate);
			_haveBomb	=	false;
		}
	}
	else if(turnCode ==	EXIT_GAME)
		exit = true;

	//	check if new coordinates have correct values
	if(CheckCorrect(map,_newCoordinate) && turnCode < 5)
	{	
		//	check if this(next) cell have present
		if(map[_newCoordinate._y][_newCoordinate._x] == PRESENT)
		{
			//	get type of presnt and delete the present
			//	from heap
			int surp_type =surp->deleteSuprise(_newCoordinate);
			
			//	check if surp_type > 0but it is unnessory
			if(surp_type) 
			{	//	do this surprise whith bombs
				//	thats mean to function 
				//	in bomb class
				bombs->putSurpriseBomb(surp_type,map);
				//	set type to user for show on screen 
				//	which surprise the player get
				setPresent(surp_type);
			}
		}	

		drowOnMap(map);	//	drow on map new position of player
	}

	//	check if user in aproximity to a blowup
	if(bombs->checkExplodeBomb(_coordinate))
		decLife();	//	if yes decrease life
	
}

//=============================================================================
//	set if user get new presnt 1-3
//	0 dont have any present
void	Player::setPresent(const short &value)
{
	_presentGeted = value;

}

//=============================================================================
//	get which present user get-have
short	Player::getPresent() const
{
	return(_presentGeted);	
}

//=============================================================================
//	drow on map the user 
void Player::drowOnMap(char map[][MAP_X])
{
	//	drow on map empty space in previous cell
	map[_coordinate._y][_coordinate._x] = LANE;
	//	reset coordinates
	_coordinate		=	_newCoordinate;
	//	dont have turn in this cicle
	_haveTurn		=	false;
	//	drow user on new cell positions
	map[_coordinate._y][_coordinate._x] = _userSymbol;
}

//=============================================================================
//	check if new coordinates is correct
//	if yes return true
bool Player::CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate)
{
	//	char to know what is located on the cell
	char value = map[newcoordinate._y][newcoordinate._x];

	//	check if this empty space
	//	or present 
	if(value == LANE || value == PRESENT )
		return true;

	return false;

}

//=============================================================================
//	return if user have bomb in this cycle
bool Player::HaveBomb() const
{
	return(_haveBomb);
}

//=============================================================================
//	return if user have turn in this cycle
bool Player::HaveTurn() const
{
	return(_haveTurn);
}