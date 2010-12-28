//		A class that reprisent surprise.
//	Management class gifts in the game.
//	The class runs in a single copy and keeps a database of 
//	gifts in the form of a vector.
//                               Include section
//=============================================================================
#include <stdlib.h>	// for rand
#include <time.h>
#include <vector>
#include "map.h"
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
	void	DrowSurprise();

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
