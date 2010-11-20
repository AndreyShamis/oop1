// A class that reprisent surprise.

//                               Include section
//=============================================================================
#include "surprise.h"

//                               Function section
//=============================================================================



//=============================================================================
Surprise::Surprise()
{
	srand((int)(time(0)));
	_presentCounter = 0;
}

//=============================================================================
Surprise::~Surprise()
{
	_PrHeap.clear();
}

//=============================================================================
void Surprise::CreateSurpise(const Vertex &coordinate)
{
	struct PresentHeap new_present;

	new_present._coord = coordinate;
	new_present._type = RandSurprise();

	_PrHeap.push_back(new_present);
	_presentCounter++;

}

//=============================================================================
int Surprise::RandSurprise()
{
	int new_surp =	0;

	new_surp = (rand()%3) + 1;

	return(new_surp);

}

//=============================================================================
void Surprise::DrowSurprise(char map[][MAP_X])
{
	for (int i = 0; i < _presentCounter; i++)
	{
		map[_PrHeap[i]._coord._y][_PrHeap[i]._coord._x] = PRESENT;
	}	
}

//=============================================================================
short Surprise::deleteSuprise(const Vertex &cord)
{
	int present_type = 0;

	for (int i = 0; i < _presentCounter; i++)
	{
		if(_PrHeap[i]._coord._x == cord._x 
			&& _PrHeap[i]._coord._y == cord._y)
		{
			present_type = _PrHeap[i]._type;
			_PrHeap.erase(_PrHeap.begin()+i);
			_presentCounter--;
			break;
		}
	}

	return(present_type);
}

//=============================================================================
void Surprise::deleteAllSuprise()
{
	_PrHeap.clear();
	_presentCounter	=	0;
}

