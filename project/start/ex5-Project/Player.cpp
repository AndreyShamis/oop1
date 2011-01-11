#include "Player.h"

//=============================================================================
Player::Player()
{
	_sprite.push_back("RGBA/Player.d_rgba.txt");
	_way = GO_UP;
}
//=============================================================================
void Player::Draw()
{
	//glClear (GL_COLOR_BUFFER_BIT);

	vector<Sprite>::iterator it ;

	it = _sprite.begin() ;
	it->Draw(_cord) ;
}

//=============================================================================

void Player::Move()
{
	switch(_way) 
	{
		case GO_UP:
			changeCord(0,STEP_SPEED); 			
			break ;
		case GO_DOWN:
			changeCord(0,-1*STEP_SPEED); 			
			break ;
		case GO_LEFT: 
			changeCord(-1*STEP_SPEED,0); 
			break ;
		case GO_RIGHT:			
			changeCord(STEP_SPEED,0);			
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