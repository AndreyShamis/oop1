/*

	This class provide for User Player
	for more inforamtion about all function look to cpp file	
*/

#pragma once
#include "Player.h"
#include <windows.h> // for PlaySound()
class User:public Player
{
public:
	User();
	virtual void Press(unsigned char key, int x, int y);
	virtual void SpecPress(int key, int x, int y);
	//	Return pointer to coordinate used in Computer Intelegence
	Vertex *getPointerCoordinate();
	//	Set pointer to exit Game variable in game Controller
	void setPointerExitGame(bool *ex_game);
	//	Set pointer to reload Game variable in game Controller
	void setPointerReloadGame(bool *re_game);
private:
	bool	*_exit_game;		//	pointer to exit game
	bool	*_reload_game;		//	pointer to reload game
};
