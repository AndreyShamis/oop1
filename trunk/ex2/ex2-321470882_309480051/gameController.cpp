#include "gameController.h"

	
GameController::GameController()
{
	LoadMap(_gameStat._map_Game);


	//_gameStat._menu		=	LaodMenu.menu;
	//_gameStat._statusWindow	= LoadStatus.status
	_gameStat._userStep = 1;
	_gameStat._movesCounter	=	0;
	_gameStat._exitGame	=	false;
	
	Vertex user1_start, user2_start;
	user1_start._x	=	1;
	user1_start._y	=	1;
	user2_start._x	=	16;
	user2_start._y	=	16;
	_user1 = new Player(user1_start,false);
	_user2 = new Player(user2_start,true);	
	_gameStat.bombs	=	new Bomb();
}




void GameController::Play()
{


	
	PrintMap(_gameStat._map_Game,0);

	

	while(1==1)
	{
		while(_user1->HaveTurn())
		{
			_user1->Turn(_gameStat._map_Game,_gameStat.bombs);
			PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());
		}
		while(_user2->HaveTurn())
		{
			_user2->Turn(_gameStat._map_Game,_gameStat.bombs);
			PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());
		}

		_gameStat.bombs->DrowBomb(_gameStat._map_Game);
		
		PrintMap(_gameStat._map_Game,_gameStat.bombs->bombCount());

		_user1->giveNewTurn();
		_user2->giveNewTurn();

		_gameStat.bombs->bombTurn();

	}

		
//		Drow board =	Drow;


		//	while(!_gameStat.exitGame)
		//	{
				// drow

				//while( user get not legall input)
				//{	// get user 1 legal input\
				//	
				//	get step
				//	if(1/2/3/4/5) if(checkIlegal)
						
				//
				//		user1.next step < 1 2 3 4 5
				//  else
				//		get step
				//	second while
				//	if(6/7/8)
				//	6	reset Play
				//	7 save second while continue
				//	8 exit destructor exit
				//	------------------
				//}

				//while( user get not legall input)
				//{	// get user 2 legal input\
				//	if(get 1 / 2 / 3 / 4 / 5)
						
				//}

				//calcilate
			//}
}

void GameController::Calculate()
{	
	;
	/*
	if(Bomb)
	{	bombLen + Bomb.chekLen;

		if(


	_gameStat._map_Game[_user1._nextCoordinates._x][_user1._nextCoordinates._y] = 'P';
	_gameStat._map_Game[_user2._nextCoordinates._x][_user2._nextCoordinates._y] = 'L';


	for(int i =0; i < BombCount;i++)
	{
		_gameStat._map_Game[Bomb.x][Bomb.y]--;
		if(_gameStat._map_Game[Bomb.x][Bomb.y] == 0 )
		{
			for(int x = Bomb[i].x-1;x<Bomb[i].x+1;x++)
			{
				
			}
			for(int i = Bomb.y-1;i<Bomb.y+1;i++)
			{

			}
		}
	}
	*/

}