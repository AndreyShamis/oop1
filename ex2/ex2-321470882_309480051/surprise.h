#include <stdlib.h>	// for rand
#include <time.h>
#include <vector>
#include "config.h"
#pragma once

struct PresentHeap
{
	Vertex	_coord;
	int		_type;
};

class Surprise
{
public:
	Surprise();
	~Surprise();
	void DrowSurprise(char map[][MAP_X]);
	void CreateSurpise(const Vertex coordinate);
	short deleteSuprise(const Vertex cord);
	void deleteAllSuprise();

private:
	int RandSurprise();
	int _presentCounter;
	std::vector <PresentHeap> _PrHeap;
};
