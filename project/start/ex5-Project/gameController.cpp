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
	myReadFile.open("MAPS/map2.txt");
	
	int countX=0,
		countY=0;

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		//
		while (!myReadFile.eof())
		{
			// Load line to array.
			
			char ch = myReadFile.get();

			if(ch == FENCE)			//	zabor
			{
				Wall *wall = new Wall();
				wall->_cord._x = countX*PIC_WIDTH;
				wall->_cord._y = countY*PIC_WIDTH;
				_objects.push_back(wall);
				_graf.addObject(wall);
			}
			else if(ch == LANE)		//	space
			{
				Space *lane = new Space();
				lane->_cord._x = countX*PIC_WIDTH;
				lane->_cord._y = countY*PIC_WIDTH;
				_objects.push_back(lane);
				_graf.addObject(lane);
			}
			else if(ch == BARREL)	// bochka
			{
				Bochka *bochka = new Bochka();
				bochka->_cord._x = countX*PIC_WIDTH;
				bochka->_cord._y = countY*PIC_WIDTH;
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
	_user->_cord._x = 1*PIC_WIDTH;
	_user->_cord._y = 1*PIC_WIDTH;
	_comp = new Computer();
	_comp->_cord._x = 18*PIC_WIDTH;
	_comp->_cord._y = 18*PIC_WIDTH;

	_objects.push_back(_user);
	_graf.addObject(_user);
	_kboard.addObject(_user);

	_comp->setUserEnemyCord(&_user->_cord);
	_objects.push_back(_comp);
	_graf.addObject(_comp);
	_kboard.addObject(_comp);	
	
PlaySound(L"SOUND/Windows_Notify.wav",NULL,SND_ALIAS | SND_APPLICATION);

	
	glutIdleFunc(gameController::idle);
	glutDisplayFunc(Grafic::Display);  
	glutSpecialFunc(Keyboard::SpecPress);	

	glutKeyboardFunc(Keyboard::Press);

	myReadFile.close();

}

void gameController::idle()
{
	vector<Objects*>::iterator it ;
	int i=0;
	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		i++;
		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		if( typeid(**it) == typeid(Bomb) && (*it)->getTimer() <0)
		{
		//	delete *it;
		//	_graf(**it);
		//	_objects.erase(it);
		//	break;
			Fire *new_fire;
			new_fire = new Fire(EXP_START_USR);
			new_fire->_cord = (*it)->_cord;
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);

			new_fire = new Fire(EXP_RIGHT_USR);
			new_fire->_cord = (*it)->_cord;
			new_fire->_cord._x+=PIC_WIDTH;
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);

			new_fire = new Fire(EXP_LEFT_USR);
			new_fire->_cord = (*it)->_cord;
			new_fire->_cord._x-=PIC_WIDTH;
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);


			new_fire = new Fire(EXP_DOWN_USR);
			new_fire->_cord = (*it)->_cord;
			new_fire->_cord._y+=PIC_WIDTH;
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);

			new_fire = new Fire(EXP_UP_USR);
			new_fire->_cord = (*it)->_cord;
			new_fire->_cord._y-=PIC_WIDTH;
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);

			(*it)->_enabled = false;
			Grafic::removeObjects();
			_objects.erase(_objects.begin()+i);
			
		//	break;

			continue;
		}
		else
		{
			(*it)->Move(_objects) ;
		}
			
		

	}

	glutPostRedisplay();	

	//clearDisabled();

}

 void gameController::clearDisabled()
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if((*it)->_enabled == false)
		{
			//;_objects.erase(it);
			//_graf.removeObject(**it);
		}

		

	}
}
