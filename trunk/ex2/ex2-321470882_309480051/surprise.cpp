#include "surprise.h"

Surprise::Surprise()
{
	srand((int)(time(0)));
}

//Surprise::~Surprise()
//{
//}

void Surprise::CreateSurpise(Vertex coordinate)
{
	;
}

int Surprise::RandSurprise()
{
	int new_surp =0;

	new_surp = (rand()%3) + 1;
	return(new_surp);
}