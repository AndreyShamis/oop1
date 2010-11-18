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

	void CreateSurpise(Vertex coordinate);

private:
	int RandSurprise();
	std::vector <PresentHeap> _PrHeap;
};
