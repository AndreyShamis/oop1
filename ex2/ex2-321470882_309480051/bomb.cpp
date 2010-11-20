#include "bomb.h"


// Bomb class constractor
//=============================================================================
Bomb::Bomb()
{
	// Set bomb couner to 0.
	_bombCounter	=	0;
}

// A function that clear all boms from game fild and reset bomb counter.
//=============================================================================
void Bomb::clearBombsAll()
{	
	_bombCounter	=	0;
	_bombs.clear();
}

// A fanction that realize the implications of surpris on bombs.
//=============================================================================
// Input: type of surprise, map.
void	Bomb::putSurpriseBomb(const short type,char map[][MAP_X])
{
	switch(type)
	{
		// Increase timers of all bobms.
		case BOMB_INC:
			increaaseTimer();
			break;

		// Blowup all bombs at the map.
		case BOMB_BLOW:
			BlowUpAll();
			break;

		// Randomly put bomb at map.
		case BOMB_RAND:
			putRandom(map);
			break;

	}	
}

//=============================================================================
void	Bomb::increaaseTimer()
{
	for (int i = 0; i < _bombCounter; i++)
	{
		if(_bombs[i]._timer >= 0)
			_bombs[i]._timer +=5;
		if(_bombs[i]._timer > 9)
			_bombs[i]._timer = 9;
	}	
}

//=============================================================================
void	Bomb::BlowUpAll()
{
	for (int i = 0; i < _bombCounter; i++)
	{
		if(_bombs[i]._timer >= 0)
			_bombs[i]._timer = 0;
	}	
}

//=============================================================================
bool Bomb::putBomb(Vertex coordinate)
{
	Bomb_S temp_bomb;

	temp_bomb._coordinate	=	coordinate;
	temp_bomb._timer		=	START_TIME;
	temp_bomb._alltime		=	START_TIME;
	_bombs.push_back(temp_bomb);
	_bombCounter++;
	
	return(true);
}

//=============================================================================
void Bomb::bombTurn()
{
	for (int i = 0; i < _bombCounter; i++)
	{
		_bombs[i]._timer	-=1;
		_bombs[i]._alltime	-=1;

	}
}

//=============================================================================
int Bomb::bombCount()
{
	return(_bombCounter);
}

//=============================================================================
void Bomb::BlowUp(char map[][MAP_X],const Vertex &BlowCoord,Surprise *surp)
{

	int x = BlowCoord._x -1; 
	int y = BlowCoord._y -1;
	Vertex pres_cord;

	int x1,y1;

	for( x1 = x, y1 = y; x1 < x+3 && y1 < y+3; x1++,y1++)
	{
		if(x1 != BlowCoord._x && y1 != BlowCoord._y)
		{
			if(map[BlowCoord._y][x1] == LANE )
				map[BlowCoord._y][x1] = FIRE;
			else if(map[BlowCoord._y][x1] == BARREL )
			{
				map[BlowCoord._y][x1] = FIRE;
				pres_cord._x = x1;
				pres_cord._y = BlowCoord._y;
				surp->CreateSurpise(pres_cord);
			}
			if(map[y1][BlowCoord._x] == LANE )
				map[y1][BlowCoord._x] = FIRE;
			else if(map[y1][BlowCoord._x] == BARREL )
			{
				map[y1][BlowCoord._x] = FIRE;
				pres_cord._x = BlowCoord._x;
				pres_cord._y = y1;
				surp->CreateSurpise(pres_cord);
				

			}
		}
	}

	map[BlowCoord._y][BlowCoord._x] = FIRE;

}

//=============================================================================
void Bomb::EraseBlowUp(char map[][MAP_X],const Vertex &BlowCoord)
{
	map[BlowCoord._y][BlowCoord._x] = LANE;

	int x = BlowCoord._x -1; 
	int y = BlowCoord._y -1; ; 
	int x1,y1;

	for( x1 = x ,y1 = y;x1 < x+3 && y1 < y+3;x1++,y1++)
	{
		if(x1 != BlowCoord._x && y1 != BlowCoord._y)
		{
			if(map[BlowCoord._y][x1] == FIRE )
				map[BlowCoord._y][x1] = LANE;
			if(map[y1][BlowCoord._x] == FIRE )
				map[y1][BlowCoord._x] = LANE;
		}

	}

}

//=============================================================================
void Bomb::putRandom(char map[][MAP_X])
{
	int x,y;

	while(true)
	{
		x = rand()%(MAP_X-2)+1;
		y = rand()%(MAP_X-1)+1;

		if(map[y][x] == LANE)
		{
			Vertex coordinate;
			coordinate._x = x;
			coordinate._y = y;
			putBomb(coordinate);
			break;
		}
		else
			continue;
	}
}

//=============================================================================
//	A function that draws the bombing, and also sets the time 
//	on the map before the explosion for each bomb. After the 
//	explosion the next move traces of the explosion is removed.
void Bomb::DrowBomb(char map[][MAP_X],Surprise *surp)
{
	for (int i = 0; i < _bombCounter; i++)
	{
		if(_bombs[i]._timer == START_TIME && _bombs[i]._alltime == START_TIME)
			map[_bombs[i]._coordinate._y][_bombs[i]._coordinate._x] = 'B';
		else if(_bombs[i]._timer == 0)
		{
			BlowUp(map,_bombs[i]._coordinate,surp);	
		}
		else if(_bombs[i]._timer < 0)
		{
			EraseBlowUp(map,_bombs[i]._coordinate);	//	erase * from map
			_bombs.erase(_bombs.begin()+i);		//	delete this bomb
			_bombCounter--;						//	decrease counter
		}
		else
		{
			int x_cord = _bombs[i]._coordinate._x;
			int y_cord = _bombs[i]._coordinate._y;
			//MAGIC
			map[y_cord][x_cord] =  _bombs[i]._timer + 48;
	
		}
	}
}

//=============================================================================
//check if the player is now on the bomb that will explode now
bool Bomb::checkExplodeBomb(const Vertex &user_cord)
{
	for (int i = 0; i < _bombCounter; i++)
	{
		int x = _bombs[i]._coordinate._x -1; 
		int y = _bombs[i]._coordinate._y -1; 

		if(_bombs[i]._timer == 0)
		{
			for(int x1 = x; x1 < x+3; x1++)
					if(x1 == user_cord._x && _bombs[i]._coordinate._y == user_cord._y )
						return(true);

			for(int y1 = y;y1 <y+3;y1++)
					if(y1 == user_cord._y && _bombs[i]._coordinate._x == user_cord._x )
						return(true);
		}
	}


	return false;
}

