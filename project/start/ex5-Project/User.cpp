#include "User.h"

User::User()
{
	_sprite.push_back(PLAYER_D);
	_sprite.push_back(PLAYER_L);
	_sprite.push_back(PLAYER_R);
	_sprite.push_back(PLAYER_U);
	_way = KEY_UP;



	movable = 0;
}

void User::Press(unsigned char key, int x, int y)
{
	// Get key from keyboord.
	switch(key)
	{
	case ' ':				//	Down key
		_way_prev = _way;
		_way = KEY_BOMB;
		break;
	case '8':				//	Up key
		_way = KEY_UP;
		break;
	case '6':				//	Right key
		_way = KEY_RIGHT;
		break;
	case '4':				//	Left key
		_way = KEY_LEFT;
		break;
	case '2':				//	Down key
		_way = KEY_DOWN;
		break;

	}

}

//=============================================================================


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