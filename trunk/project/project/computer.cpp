#include "computer.h"


// A function that get turn derection from user.
//=============================================================================
// Input: map, pointer to object of class bomb.
// Output: return turn derection.
int	Computer::getInput(Bomb *bombs)
{

	return(CompIntellect(bombs));	

}

// A function that try to detect derection to enemy.
//=============================================================================
// Output: if success to detect - return derection, otherwise - retur false.
short Computer::getTurnCodeByDetectEnemy()
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
bool Computer::checkEnemyinBombRaound()
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
short Computer::CompIntellect(Bomb *bombs)
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
			(map::getInstance()->getCellValue(_coordinate._y-1,_coordinate._x) == BARREL || 
			map::getInstance()->getCellValue(_coordinate._y+1,_coordinate._x) == BARREL||
			map::getInstance()->getCellValue(_coordinate._y,_coordinate._x-1) == BARREL ||
			map::getInstance()->getCellValue(_coordinate._y,_coordinate._x+1) == BARREL) && 
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
			if(CheckCorrect(_newCoordinate))
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