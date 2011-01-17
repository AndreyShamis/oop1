#include "User.h"

//=============================================================================
User::User()
{
	_sprite.push_back(PLAYER_D);
	_sprite.push_back(PLAYER_L);
	_sprite.push_back(PLAYER_R);
	_sprite.push_back(PLAYER_U);
	_way = KEY_RIGHT;



	movable = 0;
	PlayerStart();
	setSize();
}


//=============================================================================
Vertex *User::getPointerCoordinate()
{
	return(&_cord);
}
void User::setPointerExitGame(bool *ex_game)
{
	_exit_game = ex_game;
}

void User::setPointerReloadGame(bool *re_game)
{
	_reload_game = re_game;
}
//=============================================================================
void User::Press(unsigned char key, int x, int y)
{
	// Get key from keyboord.
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
	// Get key from keyboord.
	switch(key)
	{

	case GLUT_KEY_UP:					//	Up key
		_way = KEY_UP;
	//	PlaySound(L"SOUND/Windows_Notify.wav",NULL,SND_ALIAS | SND_APPLICATION);
		break;
	case GLUT_KEY_RIGHT:				//	Right key
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