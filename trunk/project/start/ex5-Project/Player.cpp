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
//	Function to drow the player
void Player::Draw()
{
	vector<Sprite>::iterator it ;
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
	it->Draw(_cord) ;
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
void Player::Move(std::vector<Objects *> &_objects)
{
	vector<Objects*>::const_iterator it ;

	if(_way == KEY_BOMB  )
	{
		bool can_put_B = true;
		for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		{
			if((*it) != this && (*it)->isEnabled() && (*it)->checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
			{
				can_put_B = false;
				break;
			}
		}
		if(can_put_B)
		{

			Bomb *new_bomb = new Bomb();
			new_bomb->setCord(_cord);
			_objects.push_back(new_bomb);
			Grafic::addObject(new_bomb);
		}
		_way =		_way_prev;
	}
	else 
	{
		bool _have_move = true;

		_new_cord = _cord;
		mathNewCord();
		for( it =  _objects.begin() ; it < _objects.end() ; it++ )
			if((*it) != this && !(*it)->movable && (*it)->isEnabled() )
				//	check if have collision in new and old coordinate need for get out from bomb
				if((*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH) 
					&& !(*it)->checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
					if(typeid(**it) == typeid(Fire))
					{
						_alive = false;
						//decLife();
						//std::cout << "Your life is " << getLife() << "\n";
					}
					else
					{
						_have_move = false;
						break;

					}

		if(_have_move)
			for( it =  _objects.begin() ; it < _objects.end() ; it++ )
				if((*it) != this && (*it)->isTakeable() && (*it)->isEnabled() )
					if((*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH))
						(*it)->setTaked();

		if(_have_move)
			_cord = _new_cord;

	}
}

//=============================================================================
void Player::mathNewCord()
{
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
	_new_cord._x+=x;
	_new_cord._y+=y;
}

//=============================================================================
void Player::changeCord(const float &x,const float &y)
{
	_cord._x+=x;
	_cord._y+=y;
}



//=============================================================================
//=============================================================================
//=============================================================================