#include "User.h"

//=============================================================================
//	Constructor of User
User::User()
{
	//	put the grafic into vector of spritess
	_sprite.push_back(PLAYER_D);
	_sprite.push_back(PLAYER_L);
	_sprite.push_back(PLAYER_R);
	_sprite.push_back(PLAYER_U);
	_way = KEY_RIGHT;

	_movable = false;			//	set not movable
	PlayerStart();			//	set some settings
	setSize();				//	set size
}


//=============================================================================
//	Return pointer to coordinate used in Computer Intelegence
Vertex *User::getPointerCoordinate()
{
	return(&_cord);			//	return the value
}

//=============================================================================
//	Set pointer to exit Game variable in game Controller
void User::setPointerExitGame(bool *ex_game)
{
	_exit_game = ex_game;	//	set pointer
}

//=============================================================================
//	Set pointer to reload Game variable in game Controller
void User::setPointerReloadGame(bool *re_game)
{
	_reload_game = re_game;	//	set pointer
}
//=============================================================================
void User::Press(unsigned char key, int x, int y)
{
	// Get the key from keyboord.
	switch(key)
	{
	case BOMP_KEY_S:				//	Down key
		_way_prev = _way;
		_way = KEY_BOMB;
		break;
	case BOMB_KEY_B:				//	Down key
		_way_prev = _way;
		_way = KEY_BOMB;
		break;
	case TOP_KEY:				//	Up key
		_way = KEY_UP;
		break;
	case RIGHT_KEY:				//	Right key
		_way = KEY_RIGHT;
		break;
	case LEFT_KEY:				//	Left key
		_way = KEY_LEFT;
		break;
	case DOWN_KEY:				//	Down key
		_way = KEY_DOWN;
		break;
	case EXIT_KEY:				//	Down key
		*_exit_game = true;
		break;
	case RELOAD_GAME:				//	Down key
		*_reload_game = true;
		break;
	}

}

//=============================================================================
void User::SpecPress(int key, int x, int y)
{
	// Get the key from keyboord.
	switch(key)
	{

	case GLUT_KEY_UP:				//	Up key
		_way = KEY_UP;
		break;
	case GLUT_KEY_RIGHT:			//	Right key
		_way = KEY_RIGHT;
		break;
	case GLUT_KEY_LEFT:				//	Left key
		_way = KEY_LEFT;
		break;
	case GLUT_KEY_DOWN:				//	Down key
		_way = KEY_DOWN;
		break;
	}

}