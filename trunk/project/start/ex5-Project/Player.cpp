#include "Player.h"


//=============================================================================
void Player::Draw()
{
	//glClear (GL_COLOR_BUFFER_BIT);

	vector<Sprite>::iterator it ;
	switch(_way) 
	{
		case GO_UP:
			it = _sprite.begin()+3; 			
			break ;
		case GO_DOWN:
			it = _sprite.begin() ; 			
			break ;
		case GO_LEFT: 
			it = _sprite.begin() +1; 
			break ;
		case GO_RIGHT:			
			it = _sprite.begin() +2;			
			break ;

		default:
			break;
	}
	it->Draw(_cord) ;
}

//=============================================================================

void Player::Move(std::vector<Objects *> &_objects)
{
	

	int some_step = 0;
	some_step = STEP_SPEED;


	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if(!(*it)->movable)
		{
			if(((*it)->_cord._x < _cord._x && (*it)->_cord._x+27 > _cord._x) 
				|| ((*it)->_cord._x < _cord._x+27 && (*it)->_cord._x+27 > _cord._x+27) 
				||	( (*it)->_cord._x <= _cord._x && (*it)->_cord._x+27 >= _cord._x+27 ) 
				||	((*it)->_cord._y+27 > _cord._y+27 && (*it)->_cord._y < _cord._y+27) 
				|| ((*it)->_cord._y+27 > _cord._y && (*it)->_cord._y < _cord._y) 
				|| ( (*it)->_cord._y+27 <= _cord._y+27 && (*it)->_cord._y >= _cord._y ))
			{
				if(_way == GO_UP)
				{
						if((*it)->_cord._y+27 > _cord._y-STEP_SPEED)
							if( (_cord._y) - ((*it)->_cord._y+27) >=0 )
								some_step = (_cord._y) - ((*it)->_cord._y+29);

				}
				else if(_way == GO_DOWN)
				{
						if( (*it)->_cord._y >= _cord._y+27 && (*it)->_cord._y <= _cord._y+STEP_SPEED+27)
							if( ((*it)->_cord._y) -(_cord._y+27)  >=0  )
								some_step = ((*it)->_cord._y) -(_cord._y+29) ;

				}

				else if(_way == GO_RIGHT)
				{
						if( (*it)->_cord._x>= _cord._x+27 && (*it)->_cord._x <= _cord._x+STEP_SPEED+27)
							if( ((*it)->_cord._x) -(_cord._x+27)  >=0  )
								some_step = ((*it)->_cord._x) -(_cord._x+29) ;

				}
				else if(_way == GO_LEFT)
				{
						if((*it)->_cord._x+27 > _cord._x-STEP_SPEED)
							if( (_cord._x) - ((*it)->_cord._x+27) >=0 )
								some_step = (_cord._x) - ((*it)->_cord._x+29);
									
				}
			}
		}
	}

	switch(_way) 
	{
		case GO_UP:
			changeCord(0,-1*some_step); 	

			break ;
		case GO_DOWN:
			changeCord(0,some_step); 			
			break ;
		case GO_LEFT: 
			changeCord(-1*some_step,0); 
			break ;
		case GO_RIGHT:			
			changeCord(some_step,0);			
			break ;

		default:
			break;
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