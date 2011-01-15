#include "Player.h"

//=============================================================================
void Player::PlayerStart()
{
	setLife(3);
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

//=============================================================================

short int Player::MathMaxStepSpeed()
{

	if(_way == KEY_UP || _way == KEY_DOWN)
	{
		if((int)_cord._y%PIC_WIDTH < STEP_SPEED && (int)_cord._y%PIC_WIDTH > 0)
			return((int)_cord._y%29 );

	}
	else if(_way == KEY_RIGHT || _way == KEY_LEFT)
	{
		if((int)_cord._x%PIC_WIDTH < STEP_SPEED && (int)_cord._x%PIC_WIDTH > 0)
			return((int)_cord._x%PIC_WIDTH );

	}

	
	return(STEP_SPEED);
}
short int Player::getLife()const 
{
	return(_life);
}

void Player::setLife(const short int &new_Val)
{
	_life = new_Val;
}

void Player::decLife()
{
	_life--;

}

void Player::Move(std::vector<Objects *> &_objects)
{
	
	if(_way == KEY_BOMB)
	{
		_way =		_way_prev;//KEY_DOWN ;
		Bomb *new_bomb = new Bomb();
		new_bomb->_cord = _cord;
		_objects.push_back(new_bomb);
		Grafic::addObject(new_bomb);
		return ;
	}

	
	int some_step = 0;
	some_step = STEP_SPEED;//MathMaxStepSpeed();


	vector<Objects*>::iterator it ;

	

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if(!(*it)->movable && (*it)->_enabled )
		{
			if(((*it)->_cord._x <= _cord._x && (*it)->_cord._x+27 >= _cord._x) 
				|| ((*it)->_cord._x <= _cord._x+27 && (*it)->_cord._x+27 >= _cord._x+27) 
				|| ((*it)->_cord._y <= _cord._y && (*it)->_cord._y+27 >= _cord._y)
				|| ((*it)->_cord._y <= _cord._y+27) && (*it)->_cord._y+27 >= _cord._y+27)
				 
			{
				// ili eta:	
				if((((*it)->_cord._y+PIC_WIDTH == _cord._y)		&&	(_way == KEY_UP))	||					
					(((*it)->_cord._y == _cord._y+PIC_WIDTH)	&&	(_way == KEY_DOWN))		||
					(((*it)->_cord._x == _cord._x+PIC_WIDTH)	&&	(_way == KEY_RIGHT))	||
					(((*it)->_cord._x+PIC_WIDTH == _cord._x)	&&	(_way == KEY_LEFT)))
				{
					if(typeid(**it) == typeid(Fire))
					{
						_alive = false;
						decLife();
						std::cout << "Your life is " << getLife() << "\n";
					}
					else
						some_step = 0;
					
				}
				
				// ili eta:
				/*if(_way == KEY_UP)
				{
					if(((*it)->_cord._y+PIC_WIDTH >= _cord._y-some_step) && ((*it)->_cord._y+27 < _cord._y))  
						some_step = (_cord._y) - ((*it)->_cord._y+28);
				}
				else if(_way == KEY_DOWN)
				{
					if(((*it)->_cord._y <= _cord._y+PIC_WIDTH+some_step) && ((*it)->_cord._y > _cord._y+27))	
					{
						some_step = ((*it)->_cord._y) -(_cord._y+PIC_WIDTH) ;
						cout << some_step << "\n"; 
					}
				}
				else if(_way == KEY_RIGHT)
				{
					if(((*it)->_cord._x <= _cord._x+PIC_WIDTH+some_step) && ((*it)->_cord._x > _cord._x+27))	
						some_step = ((*it)->_cord._x) -(_cord._x+28) ;
				}
				else if(_way == KEY_LEFT)
				{
					if(((*it)->_cord._x+28 >= _cord._x-some_step) && ((*it)->_cord._x+27 < _cord._x))
						some_step = (_cord._x) - ((*it)->_cord._x+28);

									
				}*/
			}
		}
	}

	switch(_way) 
	{
		case KEY_UP:
			changeCord(0,-1*some_step); 	
			break ;
		case KEY_DOWN:
			changeCord(0,some_step); 			
			break ;
		case KEY_LEFT: 
			changeCord(-1*some_step,0); 
			break ;
		case KEY_RIGHT:			
			changeCord(some_step,0);			
			break ;

	}


}

//=============================================================================
void Player::changeCord(float x, float y)
{
	_cord._x+=x;
	_cord._y+=y;
}



//=============================================================================
//=============================================================================
//=============================================================================