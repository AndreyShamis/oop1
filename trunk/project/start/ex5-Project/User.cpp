#include "User.h"

User::User()
{
	_sprite.push_back("RGBA/Player.d_rgba.txt");
	_sprite.push_back("RGBA/Player.l_rgba.txt");
	_sprite.push_back("RGBA/Player.r_rgba.txt");
	_sprite.push_back("RGBA/Player.u_rgba.txt");
	_way = GO_UP;



	movable = 0;
}

void User::Press(unsigned char key, int x, int y)
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


//=============================================================================
void User::SpecPress(int key, int x, int y)
{
	// Get key from keyboord.
	switch(key)
	{

	case GLUT_KEY_UP:					//	Up key
		_way = GO_UP;
	//	PlaySound(L"SOUND/Windows_Notify.wav",NULL,SND_ALIAS | SND_APPLICATION);
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