#include "gameController.h"

vector<Objects*> gameController:: _objects;

gameController::gameController()
{
		// Open file.

	ifstream myReadFile;
	myReadFile.open("MAPS/map2.txt");
	
	int countX=0,
		countY=0;

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof())
		{
			// Load line to array.
			char ch = myReadFile.get();
			if(ch == FENCE)			//	zabor
			{
				Wall *wall = new Wall();
				wall->_cord._x = countX;
				wall->_cord._y = countY;
				_objects.push_back(wall);
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
