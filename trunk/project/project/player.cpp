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

//======== SET IF COMPUTER PLAYER =============================================
//	set if the player is computer
//	Input:  true - computer
//			false - human
void Player::setIfComputer(const bool value)
{
	_computerPlayer = value;
}

// A function that give to user new turn in new cycle.
//=============================================================================
void Player::giveNewTurn()
{
	_haveTurn	=	true;	//	give options turn
	_haveBomb	=	true;	//	give oprions put bombs
	setPresent(0);			//	set don`t have any presents
}

// A function that try to detect derection to enemy.
//=============================================================================
// Output: if success to detect - return derection, otherwise - retur false.
short Player::getTurnCodeByDetectEnemy()
{
	//	get diference between coordinates
	int derection_x = ((_enemyCord._x) - (_coordinate._x));
	int derection_y = ((_enemyCord._y) - (_coordinate._y));

	//	get the bigger difference
	if(abs(derection_x) >=abs(derection_y))
	{
		//	select direction
		if(_coordinate._x > _enemyCord._x)
			return KEY_LEFT;
		else
			return KEY_RIGHT;

	}
	else
	{	//	select direction
		if(_coordinate._y > _enemyCord._y)
			return KEY_UP;
		else
			return KEY_DOWN;

	}

	//	else not happened
	//	but if return zero
	return (false);
}

// A function that check if can put bomb and enemy can be blowed.
//=============================================================================
// Output: if yes return true
// else return false.
// ****  the parameter can be changed.
// #### By chenging this parameter, we candifine the game Difficulty.
bool Player::checkEnemyinBombRaound()
{
	//	get the len between two players
	int derection_x = _enemyCord._x - _coordinate._x;
	int derection_y = _enemyCord._y - _coordinate._y;
	
	//	if the len smaller then 2 return true
	if(abs(derection_x) < 2 &&  abs(derection_y) < 2)
		return (true);

	return (false);

}

// A function that performs computer intellect.
//=============================================================================
// Input: map, pointer to object of class bomb.
// Output: return logic code that difine potential next turn of enemy.
short Player::CompIntellect(const char map[][MAP_X],Bomb *bombs)
{
	int turnCode;					//	variable be return

	bool give = false;				//	to exit from while
	bool try_detect_enemy = true;	//	try in cycle get intellect code
	short int computer_trys = 15;	//	emergency exit
	
	_computerTryDetectEnemy++;		//	add to global try intellect

	//	compter can try do turn only 15 
	//	after this hi still stay
	while(!give && computer_trys >0)
	{
		//	decrease trys
		computer_trys--;
		//	reset new coordinates
		_newCoordinate = _coordinate;
		//	get random code
		turnCode	=	(rand()% 4) + 1	;

		if(checkEnemyinBombRaound() 
			&& !bombs->checkIfCellHaveBomb(_coordinate))//	check if player in araound
			return(KEY_BOMB);
		//	check if have barrel in arround and don`t have bombs
		else if(!bombs->checkIfCellHaveBomb(_coordinate) &&
			(map[_coordinate._y-1][_coordinate._x] == BARREL || 
			map[_coordinate._y+1][_coordinate._x] == BARREL||
			map[_coordinate._y][_coordinate._x-1] == BARREL ||
			map[_coordinate._y][_coordinate._x+1] == BARREL) && 
			!bombs->checkExplodeBomb(_coordinate,2) )
			return(KEY_BOMB);
		else if(try_detect_enemy && _computerTryDetectEnemy > 4)
		{
			//	
			_computerTryDetectEnemy = 0;
			//	get derection to enemy
			int try_detect_code = getTurnCodeByDetectEnemy();
			//	check Intellect corect		
			if(!try_detect_code)	
				try_detect_enemy = false;
			else		//	if returned illegal code [1-4]
				turnCode = try_detect_code;
		}
		
		//	if returned illegal code [1-4] or rand
		if(turnCode<5)
		{
			//	do logic to new coorinates
			turnLogic(turnCode);
			//	check on the map 
			if(CheckCorrect(map,_newCoordinate))
			{	
				//	if correct turn
				//	check if in next turn no bombs whith timer 1
				if(bombs->checkExplodeBomb(_newCoordinate,1))
					continue;	//	try another turn
				else
					give = true;//	do new turn
			}
			else	//	incorrect param
				continue;

		}
		//	any else stay
		give = true;
		
	}
	//	sleep to give user see position
	sleep(5);
	//	return code
	return(turnCode);
}
// A function that get turn derection from user.
//=============================================================================
// Input: map, pointer to object of class bomb.
// Output: return turn derection.
int	Player::getInput(const char map[][MAP_X],Bomb *bombs)
{
	//	computer logic
	if(_computerPlayer)
	{
		return(CompIntellect(map,bombs));
	}
	//	player logic
	return(GetTurn());
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
void Player::Turn(char map[][MAP_X], Bomb *bombs, Surprise *surp, bool &exit)
{
	int		turnCode;

	turnCode = getInput(map,bombs);

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

// A function that check if new coordinates is correct 
//=============================================================================
// Input: map, new coordinate.
// Output: if yes return true, otherwise return false.
bool Player::CheckCorrect(const char map[][MAP_X],const Vertex &newcoordinate)
{
	//	char to know what is located on the cell
	char value = map[newcoordinate._y][newcoordinate._x];

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