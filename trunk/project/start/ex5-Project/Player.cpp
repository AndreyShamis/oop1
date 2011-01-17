#include "Player.h"

//=============================================================================
void Player::PlayerStart()
{
	setLife(3);
	_new_cord = _cord;
	_alive = true;
	
}


//=============================================================================
void Player::Draw()
{
	//glClear (GL_COLOR_BUFFER_BIT);

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

////=============================================================================
//
//short int Player::MathMaxStepSpeed()
//{
//
//	if(_way == KEY_UP || _way == KEY_DOWN)
//	{
//		if((int)_cord._y%PIC_WIDTH < STEP_SPEED && (int)_cord._y%PIC_WIDTH > 0)
//			return((int)_cord._y%29 );
//
//	}
//	else if(_way == KEY_RIGHT || _way == KEY_LEFT)
//	{
//		if((int)_cord._x%PIC_WIDTH < STEP_SPEED && (int)_cord._x%PIC_WIDTH > 0)
//			return((int)_cord._x%PIC_WIDTH );
//
//	}
//
//	
//	return(STEP_SPEED);
//}
//=============================================================================
short int Player::getLife()const 
{
	return(_life);
}
//=============================================================================
void Player::setLife(const short int &new_Val)
{
	_life = new_Val;
}
//=============================================================================
void Player::decLife()
{
	_life--;

}
//=============================================================================
void Player::Move(std::vector<Objects *> &_objects)
{
//if(((*it)->_cord._x <= _cord._x && (*it)->_cord._x+27 >= _cord._x) 
//	|| ((*it)->_cord._x <= _cord._x+27 && (*it)->_cord._x+27 >= _cord._x+27) 
//	|| ((*it)->_cord._y <= _cord._y && (*it)->_cord._y+27 >= _cord._y)
//	|| ((*it)->_cord._y <= _cord._y+27) && (*it)->_cord._y+27 >= _cord._y+27)
//	 
//{

// ili eta:	
//if((((*it)->_cord._y+PIC_WIDTH == _cord._y)		&&	(_way == KEY_UP))	||					
//	(((*it)->_cord._y == _cord._y+PIC_WIDTH)	&&	(_way == KEY_DOWN))		||
//	(((*it)->_cord._x == _cord._x+PIC_WIDTH)	&&	(_way == KEY_RIGHT))	||
//	(((*it)->_cord._x+PIC_WIDTH == _cord._x)	&&	(_way == KEY_LEFT)))
//{	
	if(_way == KEY_BOMB)
	{
		_way =		_way_prev;//KEY_DOWN ;
		Bomb *new_bomb = new Bomb();
		new_bomb->setCord(_cord);
		_objects.push_back(new_bomb);
		Grafic::addObject(new_bomb);
	}
	else 
	{
		bool _have_move = true;
		vector<Objects*>::iterator it ;
		_new_cord = _cord;
		mathNewCord();
		for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		{
			if((*it) != this && !(*it)->movable && (*it)->_enabled )
			{
				//	dvoyanaya proverka nujna chtobi vyti s bombi kogfda ee postavil
				if((*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH) && !(*it)->checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
				{
					if(typeid(**it) == typeid(Fire))
					{
						_alive = false;
						decLife();
						std::cout << "Your life is " << getLife() << "\n";
					}
					else
					{
						_have_move = false;
						break;

					}
					
				}
			}
		}

		if(_have_move)
		{
			_cord = _new_cord;
		}
		//else
		//{
		//	_new_cord = _cord;
		//}

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