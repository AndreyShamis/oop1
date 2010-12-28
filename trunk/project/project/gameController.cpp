#include "gameController.h"

//=============================================================================
//	Constractor
GameController::GameController()
{
	_exitGame = false;	//	variable to know when user wants to exit
	//	this also relaited to computer player
}

//=============================================================================
//	Set the options you want to restart the game, including also a new game,
//	that is, if it is only the first game or if someone exploded a bomb must 
//	reload the map and user parameters.
void GameController::RestartGame()
{

	//	second parameter must be smaller then MAP_PATH_LEN
	if(LoadMap(_map_Game,"map2.txt"))
	{
		Vertex	user1_start, 
				user2_start;

		user1_start._x	=	3;
		user1_start._y	=	3;
		user2_start._x	=	MAP_X-3-1;
		user2_start._y	=	MAP_Y-3;

		_user1->setCoordinate( user1_start);
		_user2->setCoordinate( user2_start);

		_bombs->clearBombsAll();
		_presents->deleteAllSuprise();

		_turnCounter	=	0;					//	SET TURN counter 
	}
	else
	{
		std::cout	<< "\n\t\t\tWARNING !!!\n"
					<< "\t\tGame map path incorrect!\n";
		sleep(3000);
		exit(EXIT_FAILURE);

	}

}

//=============================================================================
//	Install the game to overload the game but also for the first game that is, 
//	that would run all sorts of useful things that will be needed during 
//	the game.
void GameController::NewGame()
{
	_user1		=	new User();
	_user2		=	new Computer();	
	_bombs		=	new Bomb();
	_presents	=	new Surprise();

	_exitGame	=	false;

	//	Initialize setings for first player
	_user1->setAlive(true);					//	Have lifes
	_user1->setUserSymbol('P');				//	show on map LIKE P

	//	Initialize setings for second player
	_user2->setAlive(true);					//	Alive
	_user2->setUserSymbol('X');				//	show on map like X

	_user1->setEnemyCord(_user2->getCoordinate());
	_user2->setEnemyCord(_user1->getCoordinate());
	RestartGame();

}

//=============================================================================
void GameController::clearMemory()
{
	//	fre memory used in game
	delete _user1;		
	delete _user2;
	delete _bombs;
	delete _presents;
	
}

//=============================================================================
void GameController::PrintMenu()
{
	system("cls");
	cout	<<	"\n\n\n"
			<<	"\t\t======================================\n"
			<<	"\t\t=                                    =\n"
			<<	"\t\t=         # # # GAME MENU # # #      =\n"
			<<	"\t\t=                                    =\n"
			<<	"\t\t=           * n - New Game           =\n"
			<<	"\t\t=           * q - Exit.              =\n"
			<<	"\t\t=                                    =\n"
			<<	"\t\t======================================\n\n\n"
			<<	"\t\t- = Ilia Gaysinsky & Andrey Shamis = -\n";

}

//=============================================================================
void GameController::Menu()
{
	int		menuCode	=	0;

	while(menuCode!= EXIT_GAME && !_exitGame)
	{
		PrintMenu();
		menuCode = GetTurn();
		
		switch(menuCode)
		{
			case	30:
				NewGame();
				Play();
				clearMemory();
				break;
		}
	}
}

//=============================================================================
//	Function is responsible for the operation executed gameplay.
//	Yet what that player does not lose three times the game will continue. 
//	Function is called from the class of the menus, and after the game ended 
//	the cycle returns to the menu.
void GameController::Play()
{
	
	int user1_prev_life		=	0,	// previuos life to know when reload game
		user2_prev_life		=	0;

	//	show start positions for both users
	_user1->drowOnMap();		//	put on map
	_user2->drowOnMap();		//	put on map

	//	print first map
	PrintMap(_map_Game);

	while(_user1->getAlive() && _user2->getAlive() )
	{
		//	drow surprise on map
		_presents->DrowSurprise();

		user1_prev_life = _user1->getLife();	//	set prev life
		user2_prev_life = _user2->getLife();	//	set prev life

		//	Get turn from fierst user
		_user1->Turn(_bombs,_presents,_exitGame);
		if(_exitGame)
			break;


		_bombs->DrowBomb(_presents);
		_user2->setEnemyCord(_user1->getCoordinate());

		//	Get turn from secons user
		_user2->Turn(_bombs,_presents,_exitGame);
		if(_exitGame)
			break;
		_bombs->DrowBomb(_presents);
		_user1->setEnemyCord(_user2->getCoordinate());
		
		_bombs->bombTurn();	//	do bomb work

		_turnCounter++;
		
		// Print informations to screen
		PrintMap(_map_Game);	//	Print MAP to screen
		printLifes(_user1->getLife(),_user2->getLife());
		printTurnCounter(_turnCounter);
		printSurpriseInfo(_user1->getPresent(),_user2->getPresent());

		_user1->giveNewTurn();			//	set have turns for 1 user
		_user2->giveNewTurn();			//	set have turns for 2 user

		// check if need reload game
		reloadGameChek(user1_prev_life,user2_prev_life);
		
	}

	if(!_exitGame)
		PrintGameResult();

}

//=============================================================================
void GameController::reloadGameChek(const int &us1_l,const int &us2_l)
{
	if((us1_l != _user1->getLife() || us2_l != _user2->getLife()) 
		&& _user1->getLife()> 0 && _user2->getLife() > 0)
	{
		RestartGame();
		_user1->drowOnMap();
		_user2->drowOnMap();
		PrintMap(_map_Game);	//	Print MAP to screen
		printLifes(_user1->getLife(),_user2->getLife());
		printTurnCounter(_turnCounter);
	}
}

//=============================================================================
void GameController::PrintGameResult()
{
	if(_user1->getAlive() == _user2->getAlive())
		std::cout << "\n\t\t $$$$ - $$ Draw! $$ - $$$$ \n";
	else if(_user1->getAlive())
		std::cout << "\t\t###\t !!!!!! You WIN !!!!!! \t###\n";
	else if(_user2->getAlive())
		std::cout << "\t\t###\tYou LOSE!\t###\n";

	cout << "\n\t\tPress x to exit to menu...\n";
	
	while(getChar() != 'x'){};

}