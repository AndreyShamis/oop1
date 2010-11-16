#include <stdlib.h>	// for rand
#include <time.h>

#include "config.h"
#pragma once

class Surprise
{
public:
	Surprise();
	//~Surprise();

	void CreateSurpise(Vertex coordinate);

private:
	int RandSurprise();
};
