#pragma once
#include "config.h"
#include "io.h"
#include "drow.h"
#include "player.h"
#include "bomb.h"
#include "load_game.h"
#include "surprise.h"




struct GameStatus
{
	char			_map_Game[MAP_Y][MAP_X];
	bool			_exitGame;
	Bomb			*bombs;
	Surprise		*presents;

};


class GameController
{
public:
		GameController();
		~GameController();
		
		void Menu();
private:
		void RestartGame();
		void PrintMenu();
		void NewGame();
		GameStatus _gameStat;
		void Play();
		Player *_user1;
		Player *_user2;
		unsigned int _turnCounter;
};