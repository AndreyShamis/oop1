#include "gameController.h"

	
GameController::GameController()
{

	


	_user1 = new Player();
	_user2 = new Player();	
	_gameStat.bombs	=	new Bomb();

}
void GameController::NewGame()
{
	LoadMap(_gameStat._map_Game);


	//_gameStat._menu		=	LaodMenu.menu;
	//_gameStat._statusWindow	= LoadStatus.status

	_gameStat._movesCounter	=	0;
	_gameStat._exitGame	=	false;

	Vertex	user1_start, 
			user2_start;

	user1_start._x	=	2;
	user1_start._y	=	2;
	user2_start._x	=	MAP_Y-3;
	user2_start._y	=	MAP_X-3-1;

	_user1->setCoordinate( user1_start);
	_user1->setIfComputer(false);
	_user1->setAlive(true);

	_user2->setCoordinate( user2_start);
	_user2->setIfComputer(true);
	_user2->setAlive(true);

	_gameStat.bombs->clearBombsAll();

}
GameController::~GameController()
{

	delete _user1;
	delete _user2;
	delete _gameStat.bombs;
	
}

void GameController::PrintMenu()
{
	cout	<<	"n - New Game\n"
			<<	"q - Exit.\n";

}
void GameController::Menu()
{
	int		menuCode	=	0;

	while(menuCode!= 10)
	{
		PrintMenu();
		menuCode = GetTurn();
		
		system("cls");
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

	_user1->drowOnMap(_gameStat._map_Game);
	_user2->drowOnMap(_gameStat._map_Game);

	PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());
	while(_user1->getAlive() && _user2->getAlive() )
	{
		//&& !_user1->getWantStop()
		//while(_user1->HaveTurn())
		//{
			_user1->Turn(_gameStat._map_Game,_gameStat.bombs);
			_gameStat.bombs->DrowBomb(_gameStat._map_Game);
			//PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());
		//}
		//while(_user2->HaveTurn())
		//{
			//if(!_user1->getWantStop())
				_user2->Turn(_gameStat._map_Game,_gameStat.bombs);
			//PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());
		//}

		_gameStat.bombs->DrowBomb(_gameStat._map_Game);
		
		PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());

		_user1->giveNewTurn();
		_user2->giveNewTurn();

		_gameStat.bombs->bombTurn();

	}

	if(_user1->getAlive() == _user2->getAlive())
		std::cout << "Teko!\n";
	else if(_user1->getAlive())
		std::cout << "!!!!!!!!!!!!!!!!!You WIN!!!!!!!!!!!!!!!!!!!\n";
	else if(_user2->getAlive())
		std::cout << "\t\t###\tYou LOSE!\t###\n";
	
	//char a='0';

	cout << "Press x to exit to menu...\n";
	
	while(getChar() != 'x'){};
		 

}