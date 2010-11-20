// A class that reprisent surprise.

//                               Include section
//=============================================================================
#include <stdlib.h>	// for rand
#include <time.h>
#include <vector>
#include "config.h"
#pragma once

//                               Structur section
//=============================================================================
struct PresentHeap
{
	Vertex		_coord;
	int			_type;
};



class Surprise
{

//                               Function section
//=============================================================================
public:
	// Constractor of class surprise. 
	Surprise();

	// Distractor of class surprise.
	~Surprise();

	// A function that drow surprises at map.
	void	DrowSurprise(char map[][MAP_X]);

	// A function that creat surpris.
	void	CreateSurpise(const Vertex &coordinate);

	// A function that delete surprise from vector of surprises.
	short	deleteSuprise(const Vertex &cord);

	// A function that delete all surprises from vector of surprises.
	void	deleteAllSuprise();

private:

	// A function that lottrait type of surprise.
	int		RandSurprise();


//                              veribel section
//=============================================================================
	int			_presentCounter;
	std::vector <PresentHeap> _PrHeap;

};
