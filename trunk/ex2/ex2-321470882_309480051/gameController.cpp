#include "gameController.h"

	
GameController::GameController()
{
	_user1 = new Player();
	_user2 = new Player();	
	_gameStat.bombs	=	new Bomb();
	_gameStat.presents	=	new Surprise();


}
void GameController::RestartGame()
{
	LoadMap(_gameStat._map_Game);

	Vertex	user1_start, 
			user2_start;

	user1_start._x	=	3;
	user1_start._y	=	3;
	user2_start._x	=	MAP_Y-3;
	user2_start._y	=	MAP_X-3-1;

	_user1->setCoordinate( user1_start);
	_user2->setCoordinate( user2_start);

	_gameStat.bombs->clearBombsAll();
	_gameStat.presents->deleteAllSuprise();

}
void GameController::NewGame()
{
	

	_turnCounter	=	0;
	_gameStat._exitGame	=	false;

	
	_user1->setIfComputer(false);
	_user1->setAlive(true);
	_user1->setUserSymbol('P');

	
	_user2->setIfComputer(true);
	_user2->setAlive(true);
	_user2->setUserSymbol('X');

	this->RestartGame();

}
GameController::~GameController()
{

	delete _user1;
	delete _user2;
	delete _gameStat.bombs;
	delete _gameStat.presents;
	
}

void GameController::PrintMenu()
{
	system("cls");
	cout	<<	"\n\t\t### GAME MENU ###\n"
			<<	"\t\t * n - New Game\n"
			<<	"\t\t * q - Exit.\n";

}
void GameController::Menu()
{
	int		menuCode	=	0;

	while(menuCode!= 10)
	{
		PrintMenu();
		menuCode = GetTurn();
		
		
		switch(menuCode)
		{
			case	30:
				Play();
				break;
		}
	}
}

void GameController::Play()
{
	NewGame();

	int user1_prev_life,user2_prev_life;

	_user1->drowOnMap(_gameStat._map_Game);
	_user2->drowOnMap(_gameStat._map_Game);

	PrintMap(_gameStat._map_Game);

	while(_user1->getAlive() && _user2->getAlive() )
	{
		_gameStat.presents->DrowSurprise(_gameStat._map_Game);

		user1_prev_life = _user1->getLife();
		user2_prev_life = _user2->getLife();

		//	Get turn from fierst user
		_user1->Turn(_gameStat._map_Game,_gameStat.bombs,_gameStat.presents);
		_gameStat.bombs->DrowBomb(_gameStat._map_Game,_gameStat.presents);

		//	Get turn from secons user
		_user2->Turn(_gameStat._map_Game,_gameStat.bombs,_gameStat.presents);
		_gameStat.bombs->DrowBomb(_gameStat._map_Game,_gameStat.presents);
		
		PrintMap(_gameStat._map_Game);	//	Print MAP to screen

		_user1->giveNewTurn();			//	set have turns for 1 user
		_user2->giveNewTurn();			//	set have turns for 2 user

		_gameStat.bombs->bombTurn();	//	do bomb work

		printLifes(_user1->getLife(),_user2->getLife());
		_turnCounter++;
		printTurnCounter(_turnCounter);


		this->reloadGameChek(user1_prev_life,user2_prev_life);
		

	}


	this->PrintGameResult();
		 

}

void GameController::reloadGameChek(const int &us1_l,const int &us2_l)
{
	if((us1_l != _user1->getLife() || us2_l != _user2->getLife()) 
		&& _user1->getLife()> 0 && _user2->getLife() > 0)
	{
		this->RestartGame();
		_user1->drowOnMap(_gameStat._map_Game);
		_user2->drowOnMap(_gameStat._map_Game);
		PrintMap(_gameStat._map_Game);	//	Print MAP to screen
	}
}

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