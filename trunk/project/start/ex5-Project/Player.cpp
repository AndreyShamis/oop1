#include "Player.h"

Player::Player()
{
	_sprite.push_back("RGBA/Player.d_rgba.txt");
}

void Player::Draw()
{
	//glClear (GL_COLOR_BUFFER_BIT);

	vector<Sprite>::iterator it ;

	it = _sprite.begin() ;
	it->Draw(_cord) ;
}

void Player::Move()
{
	switch(_way) 
	{
		case GO_UP:
			changeCord(0,-2); 			
			break ;
		case GO_DOWN:
			changeCord(0,2); 			
			break ;
		case GO_LEFT: 
			changeCord(-2,0); 
			break ;
		case GO_RIGHT:			
			changeCord(2,0);			
			break ;

		default:
			break;
	}
}

void Player::changeCord(float x, float y)
{
	_cord._x+=x;
	_cord._y+=y;
}
void Player::Press(unsigned char key, int x, int y)
{

	int result = 0;	// Difine result of presed key from keyboord.

	// Get key from keyboord.
	switch(key)
	{
	case 'q':				//	q key
		result	=	10;
		break;
	case 's':				//	S key
		result	=	20;
		break;
	case 'n':				//	N key
		result	=	30;
		break;

	case ' ':				//	Space key
		result	=	5;
		break;
	case 'b':				//	b key
		result	=	5;
		break;

	case 0x48:				//	Up key
		result	=	1;
		_way = GO_UP;
		break;
	case '8':					//	Up key
		result	=	1;
		_way = GO_UP;
		break;

	case 0x4d:				//	Right key
		result	=	4;
		_way = GO_RIGHT;
		break;
	case '6':				//	Right key
		result	=	4;
		_way = GO_RIGHT;
		break;

	case 0x4b:				//	Left key
		result	=	3;
		_way = GO_LEFT;
		break;
	case '4':				//	Left key
		result	=	3;
		_way = GO_LEFT;
		break;

	case 0x50:				//	Down key
		result	=	2;
		_way = GO_DOWN;
		break;
	case '2':				//	Down key
		result	=	2;
		_way = GO_DOWN;
		break;
	}

}