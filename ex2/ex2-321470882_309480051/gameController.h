#include "config.h"
#include "player.h"

struct GameStatus
{
	unsigned int	_movesCounter;
	int				_userStep;		//	1 = first 2=first
	//unsigned int	_userA_exp;
	//unsigned int	_userB_exp;
	char			_map_Game[MAP_X][MAP_Y];
	char			_menu[8][10];
	char			_statusWindow[10][10];
	bool			_exitGame;

	char			_screen[100][100];


};




class GameController
{
public:
		GameController();
		void Play();
		void Calculate();
private:
		GameStatus _gameStat;
		
		Player _user1;
		Player _user2;
};