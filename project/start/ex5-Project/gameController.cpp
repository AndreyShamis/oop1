#include "gameController.h"
#include <typeinfo>
#include "mmsystem.h"
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
Computer gameController::_comp;
User gameController::_user;
//Grafic gameController::_graf;
short int gameController::_level;

//=============================================================================
//=============================================================================
gameController::gameController()
{
	_level = 1;
	LoadGame();
}

//=============================================================================
void gameController::reshape(int w, int h)
{
glViewport(0,0,(GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 1200, 0, 700.0, -1.0,1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

//=============================================================================
void gameController::LoadGame()
{
		// Open file.
		bool **lines = NULL;
	int map_width = -1;
	int map_height= -1;
	ifstream myReadFile;
	char path[200];
	memset(path,'\0',200);
	strcpy_s(path,MAPS_FOLDER);
	if(_level == 1)
		strcat_s(path,"/map1.txt");
	else if(_level == 1)
		strcat_s(path,"/map2.txt");
	else if(_level == 1)
		strcat_s(path,"/map3.txt");


	myReadFile.open(path);
	
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
	myReadFile.close();

	//_user = new User();
	_user._cord._x = 1*PIC_WIDTH;
	_user._cord._y = 1*PIC_WIDTH;
	//_comp = new Computer();
	_comp._cord._x = 18*PIC_WIDTH;
	_comp._cord._y = 18*PIC_WIDTH;

	_objects.push_back(&_user);
	_graf.addObject(&_user);
	_kboard.addObject(&_user);

	_comp.setUserEnemyCord(&_user._cord);
	_objects.push_back(&_comp);
	_graf.addObject(&_comp);
	_kboard.addObject(&_comp);	
	
	//glutReshapeFunc(gameController::reshape);
	glutIdleFunc(gameController::idle);
	glutDisplayFunc(Grafic::Display);  
	glutSpecialFunc(Keyboard::SpecPress);	
	glutKeyboardFunc(Keyboard::Press);



	sndPlaySound(L"SOUND/BackGround_Sound.wav", SND_LOOP | SND_ASYNC );
}

//=============================================================================
void gameController::idle()
{

	vector<Objects*>::iterator it ;
	int i=0;
	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		
		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		if(typeid(**it) == typeid(Bomb) && (*it)->getTimer() <0 && (*it)->_enabled)
		{
			sndPlaySound(L"SOUND/Boom.wav",SND_ASYNC | SND_NOSTOP);
			explodeBomb((*it)->getCord());
			
			(*it)->_enabled = false;	
			//_objects.erase(_objects.begin()+i);

		}
		else if(typeid(**it) == typeid(Fire) && (*it)->getTimer() <0 )
		{
			(*it)->_enabled = false;	
			//_objects.erase(_objects.begin()+i);
		}
		else if((*it)->_enabled)
		{
			(*it)->Move(_objects) ;
		}
			
		i++;

	}

	glutPostRedisplay();
	if(!_comp._alive || !_user._alive )
	{
		if(_user.getLife() > 0 && _comp.getLife() == 0)
		{
			for( it =  _objects.begin() ; it < _objects.end() ; it++ )
			{
				delete *it;
			}
			//Reload_Game_Stat();
		}
	}
	//Grafic::removeObjects();
	//clearDisabled();

}

//=============================================================================
void  gameController::explodeBomb(const Vertex &_cord)
{ 
	Present *new_present;
	new_present = new Present();
	new_present->_cord = _cord;
	Grafic::_objects.push_back(new_present);
	_objects.push_back(new_present);

	Fire *new_fire=NULL;

	new_fire = new Fire(EXP_START_USR,13);
	new_fire->_cord = _cord;
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);

	new_fire = new Fire(EXP_RIGHT_USR,15);
	new_fire->_cord = _cord;
	new_fire->_cord._x+=PIC_WIDTH;
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);

	new_fire = new Fire(EXP_LEFT_USR,15);
	new_fire->_cord = _cord;
	new_fire->_cord._x-=PIC_WIDTH;
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);


	new_fire = new Fire(EXP_DOWN_USR,15);
	new_fire->_cord = _cord;
	new_fire->_cord._y+=PIC_WIDTH;
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);

	new_fire = new Fire(EXP_UP_USR,15);
	new_fire->_cord = _cord;
	new_fire->_cord._y-=PIC_WIDTH;
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);
}

//=============================================================================
 void gameController::clearAll()
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		delete *it;
	}
	_objects.clear();
}

 //=============================================================================
 void gameController::Reload_Game_Stat()
 {
	int map_width = -1;
	int map_height= -1;
	ifstream myReadFile;
	char path[200];
	memset(path,'\0',200);
	strcpy_s(path,MAPS_FOLDER);
	if(_level == 1)
		strcat_s(path,"/map1.txt");
	else if(_level == 1)
		strcat_s(path,"/map2.txt");
	else if(_level == 1)
		strcat_s(path,"/map3.txt");


	myReadFile.open(path);
	
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

			//if(ch == FENCE)			//	zabor
			//{
			//	Wall *wall = new Wall();
			//	wall->_cord._x = countX*PIC_WIDTH;
			//	wall->_cord._y = countY*PIC_WIDTH;
			//	_objects.push_back(wall);
			//	_graf.addObject(wall);
			//}
			//else if(ch == LANE)		//	space
			//{
			//	Space *lane = new Space();
			//	lane->_cord._x = countX*PIC_WIDTH;
			//	lane->_cord._y = countY*PIC_WIDTH;
			//	_objects.push_back(lane);
			//	_graf.addObject(lane);
			//}
			//else if(ch == BARREL)	// bochka
			//{
			//	Bochka *bochka = new Bochka();
			//	bochka->_cord._x = countX*PIC_WIDTH;
			//	bochka->_cord._y = countY*PIC_WIDTH;
			//	_objects.push_back(bochka);
			//	_graf.addObject(bochka);
			//}
			//else if(ch == '\n')
			//{
			//	countY+=1;
			//	countX=-1;
			//}

			
			countX++; // Increase num of line.
		}
	}
	myReadFile.close();

	////_user = new User();
	//_user._cord._x = 1*PIC_WIDTH;
	//_user._cord._y = 1*PIC_WIDTH;
	////_comp = new Computer();
	//_comp._cord._x = 18*PIC_WIDTH;
	//_comp._cord._y = 18*PIC_WIDTH;

	//_objects.push_back(&_user);
	//_graf.addObject(&_user);
	//_kboard.addObject(&_user);

	//_comp.setUserEnemyCord(&_user.getCord());
	//_objects.push_back(&_comp);
	//_graf.addObject(&_comp);
	//_kboard.addObject(&_comp);	
 }
