#pragma once
#include "config.h"
#include "io.h"
#include "drow.h"
#include "player.h"
#include "bomb.h"
#include "load_game.h"
#include "surprise.h"


class GameController
{
public:		
		GameController();
		void	Menu();
private:
		Player		*_user1;
		Player		*_user2;

		void	RestartGame();
		void	PrintMenu();
		void	NewGame();
		void	PrintGameResult();
		void	reloadGameChek(const int &us1_l,const int &us2_l);
		void	Play();
		void	clearMemory();

		char			_map_Game[MAP_Y][MAP_X];
		bool			_exitGame;
		Bomb			*_bombs;
		Surprise		*_presents;
		unsigned int	_turnCounter;
};