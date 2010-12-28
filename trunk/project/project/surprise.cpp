//	A class that reprisent surprise.
//                               Include section
//=============================================================================
#include "surprise.h"

//                               Function section
//=============================================================================


// Constractor of class surprise.
//=============================================================================
Surprise::Surprise()
{
	srand((int)(time(0)));
	_presentCounter = 0;
}

// Distractor of class surprise.
//=============================================================================
Surprise::~Surprise()
{
	// clear all surprise.
	_PrHeap.clear();
}

// A function that creat surpris.
//=============================================================================
// Input: coordinate to surprise at map.
void Surprise::CreateSurpise(const Vertex &coordinate)
{
	// Difine new present.
	struct PresentHeap new_present;

	new_present._coord = coordinate;
	new_present._type = RandSurprise();

	// Put the new present at vector of presents. 
	_PrHeap.push_back(new_present);

	// Increase presents counter.
	_presentCounter++;

}

// A function that lottrait type of surprise.
//=============================================================================
int Surprise::RandSurprise()
{
	int new_surp =	0;

	new_surp = (rand()%3) + 1;

	return(new_surp);

}

// A function that drow surprises at map.
//=============================================================================
void Surprise::DrowSurprise()
{ 
	for (int i = 0; i < _presentCounter; i++)
	{
		map::getInstance()->setCellValue(_PrHeap[i]._coord._y,_PrHeap[i]._coord._x,PRESENT);
	}	
}

// A function that delete surprise from vector of surprises.
//=============================================================================
// Input: coordinate of surprise that need to be delete.
// Output:  present type it was
short Surprise::deleteSuprise(const Vertex &cord)
{
	int present_type = 0;

	// Search for surprise that need to be delete.
	for (int i = 0; i < _presentCounter; i++)
	{
		if(_PrHeap[i]._coord._x == cord._x 
			&& _PrHeap[i]._coord._y == cord._y)
		{	
			// Delete surprise.
			present_type = _PrHeap[i]._type;
			_PrHeap.erase(_PrHeap.begin()+i);

			// Decrease counter of presents.
			_presentCounter--;
			break;
		}
	}
	return(present_type);
}

// A function that delete all surprises from vector of surprises.
//=============================================================================
void Surprise::deleteAllSuprise()
{
	_PrHeap.clear();
	_presentCounter	=	0;
}

