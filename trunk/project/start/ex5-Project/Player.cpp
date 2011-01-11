#include "Player.h"

//=============================================================================
Player::Player()
{
	_sprite.push_back("RGBA/Player.d_rgba.txt");
	_sprite.push_back("RGBA/Player.l_rgba.txt");
	_sprite.push_back("RGBA/Player.r_rgba.txt");
	_sprite.push_back("RGBA/Player.u_rgba.txt");
	_way = GO_UP;
}
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
	vector<Objects*>::iterator it ;

	int some_step = 0;
	some_step = STEP_SPEED;
	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if(!(*it)->movable)
		{
			if(_way == GO_UP)
			{
				if(((*it)->_cord._x < _cord._x && (*it)->_cord._x+29 > _cord._x) 
					|| ((*it)->_cord._x < _cord._x+29 && (*it)->_cord._x+29 > _cord._x+29) )
				{
					if((*it)->_cord._y+29 > _cord._y-STEP_SPEED)
					{
						if( (_cord._y) - ((*it)->_cord._y+29) >=0 )
						{
							some_step = (_cord._y) - ((*it)->_cord._y+29);
						}
					}
					else
						some_step = STEP_SPEED;

				}

			}
			else if(_way == GO_DOWN)
			{
				if(((*it)->_cord._x < _cord._x && (*it)->_cord._x+29 > _cord._x) 
					|| ((*it)->_cord._x < _cord._x+29 && (*it)->_cord._x+29 > _cord._x+29) )
				{
					if( (*it)->_cord._y >= _cord._y+29 && (*it)->_cord._y <= _cord._y+STEP_SPEED+29)
					{
						if( ((*it)->_cord._y) -(_cord._y+29)  >=0  )
						{
							some_step = ((*it)->_cord._y) -(_cord._y+29) ;
							break;
						}
					}
					else
						some_step = STEP_SPEED;

				}

			}

			else if(_way == GO_RIGHT)
			{
				if(((*it)->_cord._y+29 > _cord._y+29 && (*it)->_cord._y < _cord._y+29) 
					|| ((*it)->_cord._y+29 > _cord._y && (*it)->_cord._y < _cord._y) 
					|| ( (*it)->_cord._y+29 <= _cord._y+29 && (*it)->_cord._y >= _cord._y ))
				{
					if( (*it)->_cord._x>= _cord._x+29 && (*it)->_cord._x <= _cord._x+STEP_SPEED+29)
					{
						if( ((*it)->_cord._x) -(_cord._x+29)  >=0  )
						{
							some_step = ((*it)->_cord._x) -(_cord._x+29) ;
							break;
						}
					}
					else
						some_step = STEP_SPEED;

				}

			}
			else if(_way == GO_LEFT)
			{
				if(((*it)->_cord._y+29 > _cord._y+29 && (*it)->_cord._y < _cord._y+29) 
					|| ((*it)->_cord._y+29 > _cord._y && (*it)->_cord._y < _cord._y)
					||	((*it)->_cord._y+29 <= _cord._y+29 && (*it)->_cord._y >= _cord._y ) )
				{
					if((*it)->_cord._x+29 > _cord._x-STEP_SPEED)
					{
						if( (_cord._x) - ((*it)->_cord._x+29) >=0 )
						{
							some_step = (_cord._x) - ((*it)->_cord._x+29);
						}
					}
					else
						some_step = STEP_SPEED;

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
void Player::Press(unsigned char key, int x, int y)
{
	// Get key from keyboord.
	switch(key)
	{

	case '8':					//	Up key
		_way = GO_UP;
		break;
	case '6':				//	Right key
		_way = GO_RIGHT;
		break;
	case '4':				//	Left key
		_way = GO_LEFT;
		break;
	case '2':				//	Down key
		_way = GO_DOWN;
		break;
	}

}

//=============================================================================
void Player::SpecPress(int key, int x, int y)
{
	// Get key from keyboord.
	switch(key)
	{

	case GLUT_KEY_UP:					//	Up key
		_way = GO_UP;
		break;
	case GLUT_KEY_RIGHT:				//	Right key
		_way = GO_RIGHT;
		break;
	case GLUT_KEY_LEFT:				//	Left key
		_way = GO_LEFT;
		break;
	case GLUT_KEY_DOWN:				//	Down key
		_way = GO_DOWN;
		break;
	}

}

//=============================================================================
//=============================================================================
//=============================================================================