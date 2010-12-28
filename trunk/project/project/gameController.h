//	Game CONTROLLER
//	This class is the heart of the game. The class is able to download the 
//	game and while some may be a player runs out three lives is the game 
//	cycle. After that displays a menu where you can leave the game or start
//	a new game.
//
//=============================================================================
#pragma once
#include "config.h"
#include "io.h"
#include "drow.h"
#include "map.h"
#include "user.h"
#include "computer.h"
#include "bomb.h"
#include "load_game.h"
#include "surprise.h"


//	Game controller class
class GameController
{
public:		
		GameController();				//	constructor
		void	Menu();					//	menu called from main
private:
		User			*_user1;			//	player structure
		Computer		*_user2;			//	player 2 structure

		void	RestartGame();			//	rload game
		void	PrintMenu();			//	print menu
		void	NewGame();				//	do new game
		void	PrintGameResult();		//	printing gmae rsult
		//	check if need reload nnew game
		void	reloadGameChek(const int &us1_l,const int &us2_l);
		void	Play();					//	play function to start game cycle
		void	clearMemory();			//	clear used db structure

		char			_map_Game[MAP_Y][MAP_X];	//	map structure
//		//std::Vector <char> _ma
		bool			_exitGame;					//	bool if need to exit
		Bomb			*_bombs;					//	bombs structure
		Surprise		*_presents;					//	surprise structure
		unsigned int	_turnCounter;				//	turn counter
};