// A class that reprisent bomb.

//                               Include section
//=============================================================================
#include "bomb.h"

//                               Function section
//=============================================================================


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
void Bomb::putSurpriseBomb(const short type,char map[][MAP_X])
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

// A function that increase timers of all boms. 
//=============================================================================
void Bomb::increaaseTimer()
{
	// Loop through all bobs.
	for (int i = 0; i < _bombCounter; i++)
	{
		// If current bomb timer is still activated - increase in 5 cycle.
		if(_bombs[i]._timer >= 0)
			_bombs[i]._timer +=5;

		// If the increasing of bomb timer that was made befor set timer to be 
		// biger then 9 - set bomb timer to be 9.
		if(_bombs[i]._timer > 9)
			_bombs[i]._timer = 9;
	}	
}

// A fanction that blowup all bomb at the map.
//=============================================================================
void Bomb::BlowUpAll()
{
	// Loop through all bobs.
	for (int i = 0; i < _bombCounter; i++)
	{
		// Set curnt bomb timer to 0.
		if(_bombs[i]._timer >= 0)
			_bombs[i]._timer = 0;
	}	
}

// A function that criate new bomb and put it at the map.
//=============================================================================
// Input: coordinate of new bomb.
// Output: return true if bomb was puted
//	But it is every time return true
//	it need for future, for example if player can have maximum only 2 bombs
bool Bomb::putBomb(Vertex coordinate)
{
	// Difine new bomb  
	Bomb_S temp_bomb;

	// Set new bomb features.
	temp_bomb._coordinate	=	coordinate;
	temp_bomb._timer		=	START_TIME;
	temp_bomb._alltime		=	START_TIME;

	// add the new bomb to the vector of bobs.
	_bombs.push_back(temp_bomb);

	// Increase bombs counter.
	_bombCounter++;
	
	return(true);
}

// A function that deccrease timers of all bombs.
//=============================================================================
void Bomb::bombTurn()
{
	// Loop through all bobs.
	for (int i = 0; i < _bombCounter; i++)
	{
		_bombs[i]._timer	-=1;
		_bombs[i]._alltime	-=1;

	}
}

// A function that return bomb counter.
//=============================================================================
int Bomb::bombCount()
{
	return(_bombCounter);
}

// A function that drow on map the fire and erese him from map
//=============================================================================
// Input: map, explosion coordinate, pointer to surprise object surp.
void Bomb::BlowUp(char map[][MAP_X],const Vertex &BlowCoord,Surprise *surp)
{
	
	int x = BlowCoord._x -1; 
	int y = BlowCoord._y -1;

	
	Vertex pres_cord;

	// Loop integers.
	int x1,y1;

	for( x1 = x, y1 = y; x1 < x+3 && y1 < y+3; x1++, y1++)
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

// A fanction that erase the blowed-up bomb
//=============================================================================
// Input: map, explosion coordinate.
void Bomb::EraseBlowUp(char map[][MAP_X],const Vertex &BlowCoord)
{
	// Erase bomb it self.
	map[BlowCoord._y][BlowCoord._x] = LANE;

	// Difine up-left coordiate of explosion.
	int x = BlowCoord._x -1; 
	int y = BlowCoord._y -1; ; 

	// Loop integers.
	int x1,y1;

	// Loop though explosion erea.
	for( x1 = x ,y1 = y;x1 < x+3 && y1 < y+3;x1++,y1++)
	{
		// If there is a fire sign - erase it.
		if(x1 != BlowCoord._x && y1 != BlowCoord._y)
		{
			if(map[BlowCoord._y][x1] == FIRE )
				map[BlowCoord._y][x1] = LANE;
			if(map[y1][BlowCoord._x] == FIRE )
				map[y1][BlowCoord._x] = LANE;
		}

	}

}

// A function that rundomly put bomb at map.
//=============================================================================
// Input: map.
void Bomb::putRandom(char map[][MAP_X])
{
	// Difine temprorary coordinates
	int x,y;

	// Loop until we get coordinate of free space at map to put bomb.
	while(true)
	{
		x = rand()%(MAP_X-2)+1;
		y = rand()%(MAP_X-1)+1;

		// If it is free space - put bomb.
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
//	A function that draws the bombing, and also sets the time 
//	on the map before the explosion for each bomb. After the 
//	explosion the next move traces of the explosion is removed.
//=============================================================================
// Input: map, pointer to surprise object surp.
void Bomb::DrowBomb(char map[][MAP_X],Surprise *surp)	
{
	//	for number bombs
	for (int i = 0; i < _bombCounter; i++)
	{	//	check if bomb was puted in this turn cycle
		if(_bombs[i]._timer == START_TIME && _bombs[i]._alltime == START_TIME)
			map[_bombs[i]._coordinate._y][_bombs[i]._coordinate._x] = 'B';
		else if(_bombs[i]._timer == 0)
		{	//	drow fire on map
			BlowUp(map,_bombs[i]._coordinate,surp);	
		}
		else if(_bombs[i]._timer < 0)
		{	//	clear fire from the map
			EraseBlowUp(map,_bombs[i]._coordinate);	//	erase * from map
			_bombs.erase(_bombs.begin()+i);		//	delete this bomb
			_bombCounter--;						//	decrease counter
		}
		else
		{
			//	temp variables
			int x_cord = _bombs[i]._coordinate._x;
			int y_cord = _bombs[i]._coordinate._y;
			//	ascii logic
			map[y_cord][x_cord] =  _bombs[i]._timer + 48;
	
		}
	}
}

// A function that check if the player is now on the bomb that will explode now
//=============================================================================
// Input: coordinate of plaeyr.
//	time of bomb: becose it is used in computer intellect function
// Output:	return true if find bomb 
bool Bomb::checkExplodeBomb(const Vertex &user_cord, const int &intime)
{
	// Loop through all bobs.
	for (int i = 0; i < _bombCounter; i++)
	{
		// Difine up-left coordinate to start chek curent bomb eplosion with 
		// plaeyr.
		int x = _bombs[i]._coordinate._x -1; 
		int y = _bombs[i]._coordinate._y -1; 

		// If curent bomb will blowup next turn - make a chek.
		if(_bombs[i]._timer < intime)
		{
			for(int x1 = x; x1 < x+3; x1++)
					if(x1 == user_cord._x && 
						_bombs[i]._coordinate._y == user_cord._y )

						return(true);

			for(int y1 = y;y1 <y+3;y1++)
					if(y1 == user_cord._y && 
						_bombs[i]._coordinate._x == user_cord._x )

						return(true);
		}
	}
	return false;

}

//=============================================================================
// Input: coordinate of cell.
// Output:	return true if find bomb 
bool Bomb::checkIfCellHaveBomb(const Vertex &cell)
{
	// Loop through all bobs.
	for (int i = 0; i < _bombCounter; i++)
	{
		if(_bombs[i]._coordinate._x == cell._x 
			&& _bombs[i]._coordinate._y == cell._y)
			return(true);
	}
	return false;

}
