// A class that reprisent player.

//                               Include section
//=============================================================================
#include "player.h"

//                               Function section
//=============================================================================

//======== Constructor ========================================================
Player::Player()
{
	_haveTurn		=	true;	// can get new turn on map
	_haveBomb		=	true;	// can put bombs on map
	_alive			=	true;	// not killed
	_userSymbol		=	'+';	// set unset user symbol
	_life			=	3;		// give user 3 life
	setPresent(0);				// set unset presents have
	
	//	rand for computer player
	_computerTryDetectEnemy = 0;
	srand ((int)(time(0)));		// rand for computer turns


}
//======== SET coordinate =====================================================
// Input: new coordinate of player at map.
void Player::setCoordinate(const Vertex &coordinate)
{
	_coordinate		=	coordinate;	//	set start coordinates
	_newCoordinate	=	coordinate;	//	temp start coordinates

}
//======== GET coordinate =====================================================
// Output: return user coordinates
Vertex Player::getCoordinate() const
{
	return(_coordinate);
}
//======== SET Alive ==========================================================
// Input: if life - true, otherwise - false.
void Player::setAlive(bool value)
{	
	if(value)		//	if seting alive
		_life =	3;	//	give to user 3 life

	_alive = value;	//	set value
}

//======== GET Alive ==========================================================
bool Player::getAlive() const
{
	return(_alive);
}

//======== SET SYMBOL =========================================================
// Input: symbol of player. may be X or P
void Player::setUserSymbol(const char new_sym)
{
	_userSymbol = new_sym;

}

// A function that give to user new turn in new cycle.
//=============================================================================
void Player::giveNewTurn()
{
	_haveTurn	=	true;	//	give options turn
	_haveBomb	=	true;	//	give oprions put bombs
	setPresent(0);			//	set don`t have any presents
}

// A function that return how meny life player have.
//=============================================================================
short Player::getLife() const
{
	return(_life);
}

// A function that set enemy coordinate.
//=============================================================================
void Player::setEnemyCord(Vertex cord)
{
	_enemyCord = cord;
}

// A function that decrease life counter.
//=============================================================================
void Player::decLife()
{
	_life--;				//	decrese life

	if(_life == 0)			//	if no more life
		setAlive(false);	//	set dead

}

// A function that convert logic code of potential next step of computer 
// player.
//=============================================================================
// Input: logic code that difine potential next turn of enemy.
// (complite logic turn to new coordinates but the newcoordinates must be 
// checked so it is not exactly new coordinates, its potential new coordinates.
void Player::turnLogic(const int &turnCode)
{
	//	turn logic
	if(turnCode == KEY_UP && _coordinate._y-1 > 0)
		_newCoordinate._y--;
	else if(turnCode == KEY_DOWN && _coordinate._y+1 < MAP_Y -1)
		_newCoordinate._y++;
	else if(turnCode == KEY_LEFT && _coordinate._x-1 >0)
		_newCoordinate._x--;
	else if(turnCode == KEY_RIGHT && _coordinate._x+1 < MAP_X-1)
		_newCoordinate._x++;
}
// A function that make player turn.
//=============================================================================
// Input: map, pointer to object bomb, pointer to object surprise, exit status.
void Player::Turn(Bomb *bombs, Surprise *surp, bool &exit)
{

	int		turnCode;

	turnCode = getInput(bombs);

	//	set new coordinate be real coordinate
	_newCoordinate	=	_coordinate;	

	if(turnCode > 0 && turnCode <5)
		turnLogic(turnCode);
	else if(turnCode ==	KEY_BOMB && _haveBomb)
	{
		//	bomb logic
		//if(map[_coordinate._y][_coordinate._x] != BOMB)
		if(!bombs->checkIfCellHaveBomb(_coordinate))
		{
			//	put bomb to bomb database
			bombs->putBomb(_coordinate);
			_haveBomb	=	false;
		}
	}
	else if(turnCode ==	EXIT_GAME)
		exit = true;

	//	check if new coordinates have correct values
	if(CheckCorrect(_newCoordinate) && turnCode < 5)
	{	
		//	check if this(next) cell have present
		if(map::getInstance()->getCellValue(_newCoordinate._y,_newCoordinate._x) == PRESENT)
		{
			//	get type of presnt and delete the present
			//	from heap
			int surp_type =surp->deleteSuprise(_newCoordinate);
			
			//	check if surp_type > 0but it is unnessory
			if(surp_type) 
			{	//	do this surprise whith bombs
				//	thats mean to function 
				//	in bomb class
				bombs->putSurpriseBomb(surp_type);
				//	set type to user for show on screen 
				//	which surprise the player get
				setPresent(surp_type);
			}
		}	

		drowOnMap();	//	drow on map new position of player
	}

	//	check if user in aproximity to a blowup
	if(bombs->checkExplodeBomb(_coordinate,1))
		decLife();	//	if yes decrease life
	
}

// A function that set type of present to user.
//=============================================================================
//	set if user get new presnt 1-3
//	0 dont have any present
void	Player::setPresent(const short &value)
{
	_presentGeted = value;

}

// A function that get which present user get-have.
//=============================================================================
//Output: return which present user get-have
short	Player::getPresent() const
{
	return(_presentGeted);	
}

// A function that drow on map the user. 
//=============================================================================
// Input: map.
void Player::drowOnMap()
{
	//	drow on map empty space in previous cell
	map::getInstance()->setCellValue(_coordinate._y,_coordinate._x,LANE);
	//	reset coordinates
	_coordinate		=	_newCoordinate;
	//	dont have turn in this cicle
	_haveTurn		=	false;
	//	drow user on new cell positions
	map::getInstance()->setCellValue(_coordinate._y,_coordinate._x,_userSymbol);
}

// A function that check if new coordinates is correct 
//=============================================================================
// Input: map, new coordinate.
// Output: if yes return true, otherwise return false.
bool Player::CheckCorrect(const Vertex &newcoordinate)
{
	//	char to know what is located on the cell
	char value = map::getInstance()->getCellValue(newcoordinate._y,newcoordinate._x);

	//	check if this empty space
	//	or present 
	if(value == LANE || value == PRESENT || value == FIRE)
		return true;

	return false;

}

// A function that difine if user have bomb in this cycle.
//=============================================================================
// Output: return true if user have bomb in this cycle.
bool Player::HaveBomb() const
{
	return(_haveBomb);
}

// A function that report if the user have turn.
//=============================================================================
// Output: return true if user have turn in this cycle
bool Player::HaveTurn() const
{
	return(_haveTurn);
}