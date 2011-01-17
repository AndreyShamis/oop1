#include "Computer.h"




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
	PlayerStart();
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
		if((*it) == NULL)
		{
			std::cout << "Error::Computer::CheckCorrect\n";
			exit(EXIT_FAILURE);
		}
		else if(!(*it)->movable && (*it)->_enabled)
		{
				Vertex it_cord;
				it_cord = (*it)->getCord();
				if(_way == KEY_UP)
				{
					if(it_cord._y >  _ncord._y)
						continue;
				}
				else if(_way == KEY_DOWN)
				{
					if(it_cord._y <  _ncord._y)
						continue;
				}
				else if(_way == KEY_RIGHT)
				{
					if(it_cord._x <  _ncord._x)
						continue;
				}
				else if(_way == KEY_LEFT)
				{
				if(it_cord._x >  _ncord._x)
						continue;
									
				}
			if( ( it_cord._x <= _cord._x && it_cord._x+27 >= _cord._x) 
				|| (it_cord._x <= _cord._x+27 && it_cord._x+27 >= _cord._x+27) 
				|| (it_cord._y <= _cord._y && it_cord._y+27 >= _cord._y)
				|| ( it_cord._y <= _cord._y+27 && it_cord._y+27 >= _cord._y+27)
				)
			{
				// ili eta:	
				if(((it_cord._y+PIC_WIDTH == _cord._y)		&&	(_way == KEY_UP))	||					
					((it_cord._y == _cord._y+PIC_WIDTH)	&&	(_way == KEY_DOWN))		||
					((it_cord._x == _cord._x+PIC_WIDTH)	&&	(_way == KEY_RIGHT))	||
					((it_cord._x+PIC_WIDTH == _cord._x)	&&	(_way == KEY_LEFT)))


					{

						return false;
					}
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
bool Computer::checkEnemyinBombRaound()
{
	//	get the len between two players
	float derection_x = (*_user_enemy_cord)._x - _cord._x;
	float derection_y = (*_user_enemy_cord)._y - _cord._y;
	
	//	if the len smaller then 2 return true
	if(abs(derection_x) < 2*PIC_WIDTH &&  abs(derection_y) < 2*PIC_WIDTH)
		return (true);

	return (false);

}

//=============================================================================
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

//=============================================================================
bool Computer::checkIfCellHaveBomb(std::vector <Objects*> &_objects,const Vertex &_coordinate)
{
	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		if((*it) == NULL)
		{
			std::cout << "Error::Computer::checkIfCellHaveBomb\n";
			exit(EXIT_FAILURE);
		}
		else if(typeid(**it) == typeid(Bomb)  && (*it)->_enabled)
		{
			if((*it)->checkCollision(_coordinate,PIC_WIDTH,PIC_WIDTH))
			//if(((*it)->_cord._x <= _coordinate._x && (*it)->_cord._x+PIC_WIDTH>= _coordinate._x) 
			//	|| ((*it)->_cord._x <= _coordinate._x+PIC_WIDTH && (*it)->_cord._x+PIC_WIDTH>= _coordinate._x+27) 
			//	|| ((*it)->_cord._y <= _coordinate._y && (*it)->_cord._y+PIC_WIDTH>= _coordinate._y)
			//	|| ((*it)->_cord._y <= _coordinate._y+PIC_WIDTH) && (*it)->_cord._y+PIC_WIDTH >= _coordinate._y+PIC_WIDTH)
				 
			{
					cout << "Have bomb\n";
					return(true);
			}
		}
	}

		return(false);
}





bool Computer::checkExplodeBomb(std::vector <Objects*> &_objects,const Vertex &newCord)
{

	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{

		if((*it) == NULL)
		{
			std::cout << "Error::Computer::checkExplodeBomb\n";
			exit(EXIT_FAILURE);
		}
		else if(typeid(**it) == typeid(Fire) && (*it)->_enabled)
		{
			if((*it)->checkCollision(newCord,PIC_WIDTH,PIC_WIDTH))
				return true;
		}
	}

	return false;
}
bool Computer::checkForBarrel(std::vector <Objects*> &_objects)
{

	Vertex	_lcord = _cord,
			_rcord = _cord,
			_ucord = _cord,
			_dcord = _cord;

	_lcord._x -= PIC_WIDTH;
	_rcord._x += PIC_WIDTH;
	_ucord._y -= PIC_WIDTH;
	_dcord._y += PIC_WIDTH;

	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{


		if(typeid(**it) == typeid(Bochka) && (*it)->_enabled)
		{
			if((*it)->checkCollision(_ucord,PIC_WIDTH,PIC_WIDTH) 
			|| (*it)->checkCollision(_dcord,PIC_WIDTH,PIC_WIDTH)
			|| (*it)->checkCollision(_lcord,PIC_WIDTH,PIC_WIDTH)
			|| (*it)->checkCollision(_rcord,PIC_WIDTH,PIC_WIDTH))
				return true;
		}
	}

	return false;
}
//=============================================================================
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

	turnCode = _way;
	while(!give && computer_trys >0 && (int)_cord._x%PIC_WIDTH == 0 && (int)_cord._y%PIC_WIDTH == 0)
	{
		if(_next_turn_code > 0)
		{
			turnCode = _next_turn_code;
			_next_turn_code = 0;
			break;
		}
			
		computer_trys--;					//	decrease trys
		_newCoordinate = _cord;				//	reset new coordinates
		turnCode	=	(rand()% 4) + 1	;	//	get random code

		if(checkEnemyinBombRaound() && !checkIfCellHaveBomb(_objects,_cord))//	check if player in araound
		{	
			turnCode= KEY_BOMB;
		}
		//	check if have barrel in arround and don`t have bombs
		else if(!checkIfCellHaveBomb(_objects,_cord) && checkForBarrel(_objects))
				turnCode = KEY_BOMB;
		else if(try_detect_enemy && _computerTryDetectEnemy > 6)
		{
			//	
			if(_computerTryDetectEnemy > 11)
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
				if(checkExplodeBomb(_objects,_newCoordinate))
					continue;
				else
					give = true;//	do new turn

			}
			else	//	incorrect param
				continue;

		}
		//	any else stay
		give = true;
		
	}

	if(turnCode == KEY_BOMB)
	{
		_way =		_way_prev;//KEY_DOWN ;
		Bomb *new_bomb = new Bomb();
		new_bomb->setCord(_cord);
		_objects.push_back(new_bomb);
		Grafic::addObject(new_bomb);
	}
	else
	{
		_way_prev = _way;
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
	


}

