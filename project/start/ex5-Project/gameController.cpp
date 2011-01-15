#include "gameController.h"
#include <typeinfo>

struct graf_point
{
	struct nightb *_nb;
	Vertex _cord;
	struct graf_point *_next;
};

struct nightb
{
	struct nightb *_next_nb;
};

vector<Objects*> gameController:: _objects;
Keyboard gameController::_kboard ;
//Grafic gameController::_graf;
gameController::gameController()
{
		// Open file.
		bool **lines = NULL;
	int map_width = -1;
	int map_height= -1;
	ifstream myReadFile;
	myReadFile.open("MAPS/map7.txt");
	
	int countX=0,
		countY=0;

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		//myReadFile >> map_height >> map_width;
		//lines = new bool*[map_height]	  ;
		//for(int i=0;i < map_height;i++)
		//{
		//	lines[i] = new bool[map_width];
		//}
		//
		while (!myReadFile.eof())
		{
			// Load line to array.
			
			char ch = myReadFile.get();

			//if(ch == BARREL || ch == LANE)
			//	lines[countY][countX] = true;
			//else
			//	lines[countY][countX] = false;

			if(ch == FENCE)			//	zabor
			{
				Wall *wall = new Wall();
				wall->_cord._x = countX*28;
				wall->_cord._y = countY*28;
				_objects.push_back(wall);
				_graf.addObject(wall);
			}
			else if(ch == LANE)		//	space
			{
				Space *lane = new Space();
				lane->_cord._x = countX*28;
				lane->_cord._y = countY*28;
				_objects.push_back(lane);
				_graf.addObject(lane);
			}
			else if(ch == BARREL)	// bochka
			{
				Bochka *bochka = new Bochka();
				bochka->_cord._x = countX*28;
				bochka->_cord._y = countY*28;
				_objects.push_back(bochka);
				_graf.addObject(bochka);
			}
			else if(ch == '\n')
			{
				countY+=1;
				countX=-1;
			}

			
			countX++; // Increase num of line.
		}
	}
	_user = new User();
	_user->_cord._x = 1*28;
	_user->_cord._y = 1*28;
	_comp = new Computer();
	_comp->_cord._x = 18*28;
	_comp->_cord._y = 18*28;

	_objects.push_back(_user);
	_graf.addObject(_user);
	_kboard.addObject(_user);

	_comp->setUserEnemyCord(&_user->_cord);
	_objects.push_back(_comp);
	_graf.addObject(_comp);
	_kboard.addObject(_comp);	

PlaySound(L"SOUND/Windows_Notify.wav",NULL,SND_ALIAS | SND_APPLICATION);

		//struct graf_point *_head = NULL;
		//struct graf_point *temp;

		//for(int y=0;y < map_height;y++)
		//{
		//	for(int x=0;x < map_width;x++)
		//	{
		//		if(lines[y][x])
		//		{
		//			temp = new struct graf_point;
		//			temp->_next = NULL;
		//			temp->_cord._x = x;
		//			temp->_cord._y = y;
		//			if(_head == NULL)
		//				_head = temp;
		//			else
		//			{
		//				temp->_next = _head;
		//				_head = temp;
		//			}
		//		}
		//	}
		//}

		//// teper nade probejatsya po vsey resheme i sdelat sosedey
		//temp = _head;
		//struct nightb *_nTemp;

		//while(temp != NULL && 1==2)
		//{
		//	int x = temp->_cord._x;
		//	int y = temp->_cord._y;

		//	if(x > 0)
		//	{
		//		if(lines[y][x-1])
		//		{
		//			_nTemp = new struct nightb;
		//		
		//			if(temp->_nb->_next_nb == NULL)
		//			{
		//				temp->_nb->_next_nb = _nTemp;
		//			}
		//			else
		//			{
		//				_nTemp->_next_nb = temp->_nb->_next_nb	;
		//			}
		//		}
		//	}

		//}
		Bomb *new_bomb = new Bomb();
		new_bomb->_cord._x = 12*28;
		new_bomb->_cord._y = 9*28;

		_objects.push_back(new_bomb);
	_graf._objects.push_back(new_bomb);

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
	{
		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		//if( typeid(**it) == typeid(Bomb) && (*it)->getTimer() <0)
		//{
		//	
		//	_objects.erase(it);
		//}
			
		(*it)->Move(_objects) ;

	}

	glutPostRedisplay();	

}
