#include "gameController.h"

vector<Objects*> gameController:: _objects;
Keyboard gameController::_kboard ;
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
				wall->_cord._x = countX*29;
				wall->_cord._y = countY*29;
				_objects.push_back(wall);
				_graf._objects.push_back(wall);
			}
			else if(ch == LANE)		//	space
			{
				Space *lane = new Space();
				lane->_cord._x = countX*29;
				lane->_cord._y = countY*29;
				_objects.push_back(lane);
				_graf._objects.push_back(lane);
			}
			else if(ch == BARREL)	// bochka
			{
				Bochka *bochka = new Bochka();
				bochka->_cord._x = countX*29;
				bochka->_cord._y = countY*29;
				_objects.push_back(bochka);
				_graf._objects.push_back(bochka);
			}
			else if(ch == '\n')
			{
				countY+=1;
				countX=-1;
			}

			
			countX++; // Increase num of line.
		}
	}
	Player *user = new Player();
	user->_cord._x = 2*29;
	user->_cord._y = 5*29;

	_objects.push_back(user);
	_graf._objects.push_back(user);
	_kboard._objects.push_back(user);
	

	glutIdleFunc(gameController::idle);
	glutDisplayFunc(Grafic::Display);  
	glutSpecialFunc(Keyboard::SpecPress);	

	glutKeyboardFunc(Keyboard::Press);

	myReadFile.close();
}

void gameController::idle()
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		(*it)->Move(_objects) ;

	glutPostRedisplay();	

}
