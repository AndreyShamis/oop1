#include "gameController.h"

	
GameController::GameController()
{
	//_gameStat._map_Game = LoagGame.Map;
	//_gameStat._menu		=	LaodMenu.menu;
	//_gameStat._statusWindow	= LoadStatus.status
	_gameStat._userStep = 1;
	_gameStat._movesCounter	=	0;
	_gameStat._exitGame	=	false;
	
	_user1._coordinates._x = 3;
	_user1._coordinates._y = 3;

	_user2._coordinates._x = 17;
	_user2._coordinates._y = 17;	
}




void GameController::Play()
{
	;
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
	_gameStat._map_Game[_user1._nextCoordinates._x][_user1._nextCoordinates._y] = 'P';
	_gameStat._map_Game[_user2._nextCoordinates._x][_user2._nextCoordinates._y] = 'L';


	for(int i =0; i < BombLen;i++)
	{

	}

}