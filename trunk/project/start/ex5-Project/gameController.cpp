#include "gameController.h"

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

gameController* gameController::_inst = NULL;
vector<Objects*> gameController:: _objects;
Keyboard gameController::_kboard ;
Computer gameController::_comp;
User gameController::_user;
Menu gameController::_user_menu(false);
Menu gameController::_comp_menu(true);
short int gameController::_level;


//=============================================================================
//	singleton :: getInsatnce of sigleton
//	if object not created create him
gameController* gameController::getInstance()
{
	if(_inst == NULL)
		_inst = new gameController;

	return _inst;

}

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
				wall->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
				_objects.push_back(wall);
				_graf.addObject(wall);
			}
			//else if(ch == LANE)		//	space
			//{
			//	Space *lane = new Space();
			//	lane->_cord._x = countX*PIC_WIDTH;
			//	lane->_cord._y = countY*PIC_WIDTH;
			//	_objects.push_back(lane);
			//	_graf.addObject(lane);
			//}
			else if(ch == BARREL)	// bochka
			{
				Bochka *bochka = new Bochka();
				bochka->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
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
	_user.setCordByFloat(1*PIC_WIDTH,1*PIC_WIDTH);
	//_comp = new Computer();
	_comp.setCordByFloat(18*PIC_WIDTH,18*PIC_WIDTH);

	_objects.push_back(&_user);
	_graf.addObject(&_user);
	_kboard.addObject(&_user);

	_comp.setUserEnemyCord(_user.getPointerCoordinate());
	_objects.push_back(&_comp);
	_graf.addObject(&_comp);
	_kboard.addObject(&_comp);	

	Vertex _menu_cord;
	_menu_cord._x = 580;
	_menu_cord._y = 50;

	_user_menu.setCord(_menu_cord);
	_objects.push_back(&_user_menu);
	_graf.addObject(&_user_menu);
	
	_menu_cord._y = 120;
	_comp_menu.setCord(_menu_cord);
	_objects.push_back(&_comp_menu);
	_graf.addObject(&_comp_menu);
	
	_user_menu.setLife(_user.getLife());
	_comp_menu.setLife(_comp.getLife());
	//glutReshapeFunc(gameController::reshape);
	glutIdleFunc(gameController::getInstance()->idle);
	glutDisplayFunc(Grafic::Display);  
	glutSpecialFunc(Keyboard::SpecPress);	
	glutKeyboardFunc(Keyboard::Press);



	//sndPlaySound(L"SOUND/BackGround_Sound.wav", SND_LOOP | SND_ASYNC );
}

//=============================================================================
void gameController::idle()
{

	vector<Objects*>::iterator it ;

	
	int _it_size = (int)_objects.size(); 
	for( int i = 0 ; i < _it_size;i++ )
	{
		it =  _objects.begin() +i;
			if((*it) == NULL)
			{
				std::cout << "Some error in IDLE 22222\n";
				exit(EXIT_FAILURE);
			}

		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		if(typeid(**it) == typeid(Bomb) && (*it)->getTimer() <0 && (*it)->_enabled)
		{
			//sndPlaySound(L"SOUND/Boom.wav",SND_ASYNC | SND_NOSTOP);
			explodeBomb((*it)->getCord());
			(*it)->_enabled = false;	
		}
		else
			if(typeid(**it) == typeid(Fire) && (*it)->getTimer() <0 )
		{
			(*it)->_enabled = false;	
		}
		 
			if((*it)->_enabled )
		{
			(*it)->Move(_objects) ;
		}
			
	
	}
	


	glutPostRedisplay();
	if(!_comp._alive || !_user._alive )
	{
		gameController::getInstance()->_graf._objects.clear();
		gameController::getInstance()->_kboard._objects.clear();

		for( it =  _objects.begin() ; it !=_objects.end() ; it++ )
		{
			if((*it) == NULL)
			{
				std::cout << "Some error in IDLE 22222\n";
				exit(EXIT_FAILURE);
			}
				if(typeid(**it) != typeid(User)  && typeid(**it) != typeid(Computer) &&  typeid(**it) != typeid(Menu)  )
				delete *it;
		}
		//clearAll();
		gameController::getInstance()->_objects.clear();


		if(_user.getLife() >0 && _comp.getLife() == 0)
		{
			_level++;
			_user.setLife(3);
			_comp.setLife(3);
			
		}
		
		_comp._alive = true;
		_user._alive = true;
		Reload_Game_Stat();	

	}
	//Grafic::removeObjects();
	//clearDisabled();

}


//=============================================================================
 void gameController::clearAll()
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		delete &(*it);
	}
	//_objects.clear();
}


//=============================================================================
void  gameController::explodeBomb(const Vertex &_cord)
{ 

	
	Fire *new_fire=NULL;

	new_fire = new Fire(EXP_START_USR,13);
	new_fire->setCord(_cord);
	Grafic::_objects.push_back(new_fire);
	_objects.push_back(new_fire);

	for(int i=0;i<4;i++)
	{
		Vertex _fire_cord = _cord;
		char pic_fire[100];
		switch(i)
		{
		case 0:
				strcpy_s(pic_fire,EXP_RIGHT_USR);
				_fire_cord._x+=PIC_WIDTH;
				break;
		case 1:
				_fire_cord._x-=PIC_WIDTH;
				strcpy_s(pic_fire,EXP_LEFT_USR);
				break;
		case 2:
				_fire_cord._y+=PIC_WIDTH;
				strcpy_s(pic_fire,EXP_DOWN_USR);
				break;
		case 3:
				_fire_cord._y-=PIC_WIDTH;
				strcpy_s(pic_fire,EXP_UP_USR);
				break;
		}
	
		bool have_col = false;
		vector<Objects*>::iterator it ;
		for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		{
			if((*it) == NULL)
			{
				std::cout << "Error in Explode Bomb\n";
				exit(EXIT_FAILURE);
			}
			else
			{

				if((*it)->_enabled && typeid(**it) == typeid(Wall))
				{

					if((*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
					{
						have_col= true;
						break;
					}
				}
				if((*it)->_enabled && typeid(**it) == typeid(Bochka))
				{

					if((*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
					{
						//have_col= false;
						(*it)->_enabled = false;
						Present *new_present;
						new_present = new Present();
						new_present->setCord((*it)->getCord());
						Grafic::_objects.push_back(new_present);
						_objects.push_back(new_present);
						
					}
				}

			}

		}
		if(!have_col)
		{
			new_fire = new Fire(pic_fire,15);
			new_fire->setCord(_fire_cord);
			Grafic::_objects.push_back(new_fire);
			_objects.push_back(new_fire);
		}
	}

}

 //=============================================================================
 void gameController::Reload_Game_Stat()
 {
	int countX=0,
		countY=0;

	ifstream myReadFile;
	char path[200];
	memset(path,'\0',200);
	strcpy_s(path,MAPS_FOLDER);

	if(_level == 1)
		strcat_s(path,"/map1.txt");
	else if(_level == 2)
		strcat_s(path,"/map2.txt");
	else if(_level == 3)
		strcat_s(path,"/map3.txt");


	myReadFile.open(path);
	

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		//
		std::cout << "Start loading textures\n";
		while (!myReadFile.eof())
		{
			// Load line to array.
			
			char ch = myReadFile.get();

			if(ch == FENCE)			//	zabor
			{
				Wall *wall = new Wall();
				wall->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
				gameController::getInstance()->_objects.push_back(wall);
				gameController::getInstance()->_graf.addObject(wall);
			}
			//else if(ch == LANE)		//	space
			//{
			//	Space *lane = new Space();
			//	lane->_cord._x = countX*PIC_WIDTH;
			//	lane->_cord._y = countY*PIC_WIDTH;
			//	gameController::getInstance()->_objects.push_back(lane);
			//	gameController::getInstance()->_graf.addObject(lane);
			//}
			else if(ch == BARREL)	// bochka
			{
				Bochka *bochka = new Bochka();
				bochka->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
				gameController::getInstance()->_objects.push_back(bochka);
				gameController::getInstance()->_graf.addObject(bochka);
			}
			else if(ch == '\n')
			{
				countY+=1;
				countX=-1;
			}

			
			countX++; // Increase num of line.
		}
		std::cout << "Textures loaded\n";
	}
	else
	{
		std::cout << "Can not open file " << path << "\n";
	}

	myReadFile.close();

	//_user = new User();
	std::cout << "Creating User\n";
	gameController::getInstance()->_user.setCordByFloat(1*PIC_WIDTH, 1*PIC_WIDTH);
	//_comp = new Computer();
	std::cout << "Creating Computer Enemy\n";
	gameController::getInstance()->_comp.setCordByFloat(18*PIC_WIDTH, 18*PIC_WIDTH);



	_objects.push_back(&gameController::getInstance()->_user);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_user);
	_kboard.addObject(&gameController::getInstance()->_user);

	gameController::getInstance()->_comp.setUserEnemyCord(gameController::getInstance()->_user.getPointerCoordinate());
	_objects.push_back(&gameController::getInstance()->_comp);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_comp);
	_kboard.addObject(&gameController::getInstance()->_comp);


	Vertex _menu_cord;
	_menu_cord._x = 580;
	_menu_cord._y = 50;

	_user_menu.setCord(_menu_cord);
	_objects.push_back(&gameController::getInstance()->_user_menu);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_user_menu);
	
	_menu_cord._y = 120;
	_comp_menu.setCord(_menu_cord);
	_objects.push_back(&gameController::getInstance()->_comp_menu);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_comp_menu);
	
	_user_menu.setLife(gameController::getInstance()->_user.getLife());
	_comp_menu.setLife(gameController::getInstance()->_comp.getLife());
	std::cout << "Game is loaded\n";
 }
