#include "Computer.h"
#include <time.h>



Computer::Computer(void)
{
	_sprite.push_back(ENEMY_D);
	_sprite.push_back(ENEMY_L);
	_sprite.push_back(ENEMY_R);
	_sprite.push_back(ENEMY_U);
	_way = KEY_UP;

	srand ((int)(time(0)));		// rand for computer turns
	intelect =1;
	movable = 0;
	_computerTryDetectEnemy = 0;
}

void Computer::setUserEnemyCord(const Vertex *_cord)
{
	_user_enemy_cord = _cord;


}
// A function that check if new coordinates is correct 
//=============================================================================
// Input: map, new coordinate.
// Output: if yes return true, otherwise return false.
bool Computer::CheckCorrect(const Vertex &_ncord,std::vector <Objects*> &_objects)
{

	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if(!(*it)->movable)
		{
				if(_way == KEY_UP)
				{
					if((*it)->_cord._y >  _ncord._y)
						continue;
				}
				else if(_way == KEY_DOWN)
				{
					if((*it)->_cord._y <  _ncord._y)
						continue;
				}
				else if(_way == KEY_RIGHT)
				{
					if((*it)->_cord._x <  _ncord._x)
						continue;
				}
				else if(_way == KEY_LEFT)
				{
				if((*it)->_cord._x >  _ncord._x)
						continue;
									
				}
			if(((*it)->_cord._x < _ncord._x && (*it)->_cord._x+29 > _ncord._x) 
				|| ((*it)->_cord._x < _ncord._x+29 && (*it)->_cord._x+29 > _ncord._x+29) 
				||	( (*it)->_cord._x <= _ncord._x && (*it)->_cord._x+29 >= _ncord._x+29 ) 
				||	((*it)->_cord._y+29 > _ncord._y+29 && (*it)->_cord._y < _ncord._y+29) 
				|| ((*it)->_cord._y+29 > _ncord._y && (*it)->_cord._y < _ncord._y) 
				|| ( (*it)->_cord._y+29 <= _ncord._y+29 && (*it)->_cord._y >= _ncord._y ))
			{

				return false;
			}
		}
	}
	return true;

}

// A function that try to detect derection to enemy.
//=============================================================================
// Output: if success to detect - return derection, otherwise - retur false.
short Computer::getTurnCodeByDetectEnemy()
{
	//	get diference between coordinates
	float derection_x = (( (*_user_enemy_cord)._x) - (_cord._x));
	float derection_y = (( (*_user_enemy_cord)._y) - (_cord._y));

	//	get the bigger difference
	if(abs(derection_x) >=abs(derection_y))
	{
		//	select direction
		if(_cord._x > (*_user_enemy_cord)._x)
			return KEY_LEFT;
		else
			return KEY_RIGHT;

	}
	else
	{	//	select direction
		if(_cord._y > (*_user_enemy_cord)._y)
			return KEY_UP;
		else
			return KEY_DOWN;

	}

	//	else not happened
	//	but if return zero
	return (false);
}

//=============================================================================
// Output: if yes return true
// else return false.
// ****  the parameter can be changed.
// #### By chenging this parameter, we candifine the game Difficulty.
bool Computer::checkEnemyinBombRaound()
{
	//	get the len between two players
	float derection_x = (*_user_enemy_cord)._x - _cord._x;
	float derection_y = (*_user_enemy_cord)._y - _cord._y;
	
	//	if the len smaller then 2 return true
	if(abs(derection_x) < 2*29 &&  abs(derection_y) < 2*29)
		return (true);

	return (false);

}

void Computer::turnLogic(const short int &turnCode)
{
	
	//	turn logic
	if(turnCode == KEY_UP)
		_newCoordinate._y-=STEP_SPEED;
	else if(turnCode == KEY_DOWN )
		_newCoordinate._y+=STEP_SPEED;
	else if(turnCode == KEY_LEFT )
		_newCoordinate._x-=STEP_SPEED;
	else if(turnCode == KEY_RIGHT)
		_newCoordinate._x+=STEP_SPEED;
}

void Computer::VirtualPress(std::vector <Objects*> &_objects)
{
	short int turnCode;					//	variable be return
	turnCode	=	(rand()% 4) + 1	;
	static int _next_turn_code;

	bool give = false;				//	to exit from while
	bool try_detect_enemy = true;	//	try in cycle get intellect code
	short int computer_trys = 15;	//	emergency exit

	Vertex _newCoordinate;
	_computerTryDetectEnemy++;		//	add to global try intellect

	while(!give && computer_trys >0)
	{
		if(_next_turn_code > 0)
		{
			turnCode = _next_turn_code;
			_next_turn_code = 0;
			break;
		}
			
			//	decrease trys
		computer_trys--;
		//	reset new coordinates
		_newCoordinate = _cord;
		//	get random code
		turnCode	=	(rand()% 4) + 1	;

		//if(checkEnemyinBombRaound() )
			////&& !bombs->checkIfCellHaveBomb(_coordinate))//	check if player in araound
			//turnCode= KEY_BOMB;
		//	check if have barrel in arround and don`t have bombs
		////else if(!bombs->checkIfCellHaveBomb(_coordinate) &&
		////	(map::getInstance()->getCellValue(_coordinate._y-1,_coordinate._x) == BARREL || 
		////	map::getInstance()->getCellValue(_coordinate._y+1,_coordinate._x) == BARREL||
		////	map::getInstance()->getCellValue(_coordinate._y,_coordinate._x-1) == BARREL ||
		////	map::getInstance()->getCellValue(_coordinate._y,_coordinate._x+1) == BARREL) && 
		////	!bombs->checkExplodeBomb(_coordinate,2) )
		////	return(KEY_BOMB);
		//else 
			if(try_detect_enemy && _computerTryDetectEnemy > 10)
		{
			//	
			if(_computerTryDetectEnemy > 24)
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
			if(CheckCorrect(_newCoordinate,_objects))
			{	
				if(!try_detect_enemy)
				{
					_next_turn_code = turnCode;
				}
				//	if correct turn
				//	check if in next turn no bombs whith timer 1
				////if(bombs->checkExplodeBomb(_newCoordinate,1))
				////	continue;	//	try another turn
				////else
					give = true;//	do new turn
			}
			else	//	incorrect param
				continue;

		}
		//	any else stay
		give = true;
		
	}



		switch(turnCode)
		{
		case 1:
			_way = KEY_UP;
			break;
		case 2:
			_way = KEY_DOWN;
			break;
		case 3:
			_way = KEY_LEFT;
			break;
		case 4:
			_way = KEY_RIGHT;
			break;
		}

}

