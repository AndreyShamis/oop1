#include "Player.h"

//=============================================================================
//	Set some setings
void Player::PlayerStart()
{
	setLife(3);
	_new_cord = _cord;
	_alive = true;
	
}

//=============================================================================
//	Function to set if player is dead
void Player::setDead()
{
	_alive = false;
}

//=============================================================================
//	Function to set if player is alive
void Player::setAlive()
{
	_alive = true;
}
//=============================================================================
//	Function to get if player is dead
bool Player::getAlive()const
{
	return(_alive);
}
//=============================================================================
//	Function to drow the player
void Player::Draw()
{
	vector<Sprite>::iterator it ;			//	vector iteartor
	switch(_way) 
	{
		case KEY_UP:
			it = _sprite.begin()+3; 			
			break ;
		case KEY_DOWN:
			it = _sprite.begin() ; 			
			break ;
		case KEY_LEFT: 
			it = _sprite.begin() +1; 
			break ;
		case KEY_RIGHT:			
			it = _sprite.begin() +2;			
			break ;
		default:
			it = _sprite.begin() ; 			
			break ;
	}
	it->Draw(_cord) ;						//	draw
}

//=============================================================================
//	Return life
short int Player::getLife()const 
{
	return(_life);
}

//=============================================================================
//	Set life
void Player::setLife(const short int &new_Val)
{
	_life = new_Val;
}

//=============================================================================
//	Decrease life
void Player::decLife()
{
	_life--;

}
//=============================================================================
//	Move for player function
void Player::Move(std::vector<Objects *> &_objects)
{
	vector<Objects*>::const_iterator it ;	//	vector iterator

	if(_way == KEY_BOMB  )					//	if key put bomb
	{
		bool can_put_B = true;				//	bool indicaton in can put momb
		//	cheking if the space for put bomb is correct
		for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		{
			if((*it) != this && (*it)->isEnabled() && (*it)->checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
			{
				can_put_B = false;			//	if not return false
				break;
			}
		}

		if(can_put_B)
		{
			//	check if bomb can be puted so put the bomb
			Bomb *new_bomb = new Bomb();
			new_bomb->setCord(_cord);
			_objects.push_back(new_bomb);
			Grafic::addObject(new_bomb);
		}
		_way =		_way_prev;				//	set way direction to be
		//	previuos direction way
	}
	else 
	{
		bool _have_move = true;				//	bool varibale indication to check
											//	if can move
		_new_cord = _cord;					//	set new cord
		mathNewCord();						//	get new cord
		//	checking colisions
		for( it =  _objects.begin() ; it < _objects.end() ; it++ )
			if((*it) != this && !(*it)->getMovable() && (*it)->isEnabled() )
				//	check if have collision in new and old coordinate need for get out from bomb
				if((*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH) 
					&& !(*it)->checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
					if(typeid(**it) == typeid(Fire))
						_alive = false;		//	step on fire
					else
					{						//	give true for move
						_have_move = false;
						break;

					}
		//	present logic for taking
		if(_have_move)
			for( it =  _objects.begin() ; it < _objects.end() ; it++ )
				if((*it) != this && (*it)->isTakeable() && (*it)->isEnabled() )
					if((*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH))
						(*it)->setTaked();
		//	set real coordinate be new mathed coordinates
		if(_have_move)
			_cord = _new_cord;

	}
}

//=============================================================================
//	Math and get new coordinate which be puted in new coordinate variable
void Player::mathNewCord()
{
	//	simple switch by direction
	switch(_way) 
	{
		case KEY_UP:
			changeNewCord(0,-1*STEP_SPEED); 	
			break ;
		case KEY_DOWN:
			changeNewCord(0,STEP_SPEED); 			
			break ;
		case KEY_LEFT: 
			changeNewCord(-1*STEP_SPEED,0); 
			break ;
		case KEY_RIGHT:			
			changeNewCord(STEP_SPEED,0);			
			break ;

	}
}
//=============================================================================
void Player::changeNewCord(const float &x,const float &y)
{
	_new_cord._x+=x;			//	set new x coordiante
	_new_cord._y+=y;			//	set new y coordinate
}


//=============================================================================
//=============================================================================
//=============================================================================