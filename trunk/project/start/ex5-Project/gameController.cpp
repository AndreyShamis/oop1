#include "gameController.h"

vector<Objects*> gameController:: _objects;

gameController::gameController()
{
		// Open file.

	ifstream myReadFile;
	myReadFile.open("");
	
	int countX=0,
		countY=0;

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof())
		{
			// Load line to array.
			char ch = getchar();
			if(ch == FENCE)			//	zabor
			{
				
			}
			else if(ch == LANE)		//	space
			{

			}
			else if(ch == BARREL)	// bochka
			{

			}
			else if(ch == '\n')
			{
				countY+=1;
				countX=-1;
			}

			
			countX++; // Increase num of line.
		}
	}

	glutDisplayFunc(Grafic::Display);  
	myReadFile.close();
}

gameController::~gameController(void)
{
}
