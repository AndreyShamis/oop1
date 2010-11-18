#include "surprise.h"

Surprise::Surprise()
{
	srand((int)(time(0)));
}
Surprise::~Surprise()
{
	_PrHeap.clear();
}
//Surprise::~Surprise()
//{
//}

void Surprise::CreateSurpise(Vertex coordinate)
{
	struct PresentHeap new_present;

	new_present._coord = coordinate;
	new_present._type = RandSurprise();

	_PrHeap.push_back(new_present);
}

int Surprise::RandSurprise()
{
	int new_surp =0;

	new_surp = (rand()%3) + 1;
	return(new_surp);
}