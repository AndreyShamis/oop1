#include "gameController.h"

gameController*		gameController::_inst = NULL;
vector<Objects*>	gameController:: _objects;
Keyboard	gameController::_kboard ;
Computer	gameController::_comp;
User		gameController::_user;
Menu		gameController::_user_menu(false);
Menu		gameController::_comp_menu(true);
Level		gameController::_level_menu;
float		gameController::_WORLD_height;
float		gameController::_WORLD_width;
short int	gameController::_level;
bool		gameController::_GameStared=false;

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
	glutIdleFunc(gameController::getInstance()->idle);
	glutDisplayFunc(Grafic::Display);  
	glutSpecialFunc(Keyboard::SpecPress);	
	glutKeyboardFunc(Keyboard::Press);
	sndPlaySound(L"SOUND/BackGround_Sound.wav", SND_LOOP | SND_ASYNC );
}

//=============================================================================
void gameController::applyPresents()
{
	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		if((*it)->isTaked())
		{
			if((*it)->getPresentType() == PRESENT_BOMB)
			{
				Vertex _dneedit = (*it)->getCord();

				PutRandomBomb((int)(_dneedit._x*_dneedit._y));
			}
			else if((*it)->getPresentType() == PRESENT_TIME)
				IncreaseAllBombsTimers();
			else if((*it)->getPresentType() == PRESENT_LIGHT)
			{
				ExplodeAllBombsTimers();
			}
			(*it)->Disable();

		}
	}
}

//=============================================================================
void gameController::IncreaseAllBombsTimers()
{

	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled())	
			(*it)->IncereaseTimer();

}

//=============================================================================
Vertex gameController::GetEmptyCellCord(const int &i)
{
	srand ( time(NULL) );
	static Vertex _new_cord;
		_new_cord._x = 0;
		_new_cord._y = 0;
	int trys = 100;
	int x=i;
	int y=1;
	while(true)
	{
		x =	rand()%(int)(_WORLD_width-i%PIC_WIDTH)+1;
		y =	rand()%(int)(_WORLD_height-(i*x)%PIC_WIDTH)+1;

		for(int i =0;i <PIC_WIDTH && (int)x%PIC_WIDTH ==0;i++)
		{	
			x+=1;
		}
		for(int i =0;i<PIC_WIDTH && (int)y%PIC_WIDTH ==0;i++)
		{	
			y+=1;
		}
		_new_cord._x = x;
		_new_cord._y = y;
		vector<Objects*>::iterator it ;
		bool copm = false;
		for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		{
			Vertex it_cord = (*it)->getCord();
			if((*it)->isEnabled() && it_cord._x == _new_cord._x && it_cord._y == _new_cord._y)
			{
				copm = false;
				break;
				
			}
			if(copm)
				return(_new_cord);
		}
		trys--;
		if(trys < 0)
			return(_new_cord);
		
	}


	return(_new_cord);
}

//=============================================================================
void gameController::PutRandomBomb(const int &i)
{
	Vertex _new_cord = GetEmptyCellCord(i);
	if(_new_cord._x != 0 && _new_cord._y !=0)
	{
		Bomb *new_bomb = new Bomb();
		new_bomb->setCord(_new_cord);
		gameController::getInstance()->_objects.push_back(new_bomb);
		gameController::getInstance()->_graf.addObject(new_bomb);
	}
}

//=============================================================================
void gameController::ExplodeAllBombsTimers()
{

	vector<Objects*>::iterator it ;
	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled())
		{
			
			(*it)->Disable();
			explodeBomb((*it)->getCord());


		}
	}
	
}

//=============================================================================
void  gameController::explodeBomb(const Vertex &_cord)
{ 

	
	Fire *new_fire=NULL;

	new_fire = new Fire(EXP_START_USR,13);
	new_fire->setCord(_cord);
	Grafic::_objectsDrow.push_back(new_fire);
	_objects.push_back(new_fire);

	if( _user.checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
	{
		_user._alive = false;
	}
	else if(_comp.checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
	{
		
		_comp._alive = false;
	}

	for(int i=0;i<4;i++)
	{
		Vertex _fire_cord = _cord;
		char pic_fire[200];
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
		vector<Objects*>::const_iterator it ;
		for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		{
			if((*it)->isEnabled())
			{

				if( typeid(**it) == typeid(Wall) && (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{
					have_col= true;
					break;
				}
				if( typeid(**it) == typeid(User) && (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{
					_user._alive = false;
					have_col = false;
				}
				else if( typeid(**it) == typeid(Computer)&& (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{
					_comp._alive = false;
					have_col = false;
				}
				if(typeid(**it) == typeid(Bochka))
				{

					if((*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
					{	
						have_col= false;
						(*it)->Disable();
						Present *new_present;
						new_present = new Present();
						new_present->setCord((*it)->getCord());
						Grafic::_objectsDrow.push_back(new_present);
						_objects.push_back(new_present);
						
					}
				}

			}

		}
		if(!have_col)
		{
			new_fire = new Fire(pic_fire,15);
			new_fire->setCord(_fire_cord);
			Grafic::_objectsDrow.push_back(new_fire);
			_objects.push_back(new_fire);
		}
	}

}

//=============================================================================
void gameController::removeDisabledObjects()
{
	int _vec_size = (int)_objects.size();
	for(int i=0;i<_vec_size;i++)
	{
		if(!_objects[i]->isEnabled())
		{
			Objects *temp = _objects[i];
			gameController::getInstance()->_graf.clearObject(_objects[i]);
			_objects.erase(_objects.begin()+i);
			delete temp;
			break;
		}
	}


}

void gameController::decreaseTimer()
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		(*it)->decTimer();
	
}

//=============================================================================
void gameController::idle()
{
	if(!_GameStared)
	{
		Reload_Game_Stat();	
		_GameStared = true;
	}

	vector<Objects*>::iterator iter ;

	if(!_comp._alive || !_user._alive )
	{
		if(!_comp._alive)
			_comp.decLife();
		if(!_user._alive)
			_user.decLife();

		gameController::getInstance()->_graf._objectsDrow.clear();
		gameController::getInstance()->_kboard._objects.clear();

		for( iter =  _objects.begin() ; iter !=_objects.end() ; iter++ )
		{
			if(typeid(**iter) != typeid(User)  && typeid(**iter) != typeid(Computer) 
				&&  typeid(**iter) != typeid(Menu)  &&  typeid(**iter) != typeid(Level))
				delete *iter;
		}

		gameController::getInstance()->_objects.clear();

		if(_user.getLife() >0 && _comp.getLife() == 0)
		{
			_level++;
			_user.setLife(3);
			_comp.setLife(3);
			
		}
		else if(_user.getLife() == 0 && _comp.getLife()>=0)
		{
			exit(EXIT_SUCCESS);
			;//GAME END
		}

		if(_level > MAX_LEVEL)
			exit(EXIT_SUCCESS);

		_comp._alive = true;
		_user._alive = true;
		Reload_Game_Stat();	

	}

	removeDisabledObjects();			//	remove disabled objects from memory
	decreaseTimer();					//	decrease timer for bombs
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{

		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled() && (*it)->getTimer() <=0 )
		{
			(*it)->Disable();
			explodeBomb((*it)->getCord());			
		}
		else if(typeid(**it) == typeid(Fire) && (*it)->getTimer() <0 )
			(*it)->Disable();	 
		else if((*it)->isEnabled())// && !(*it)->intelect)

			(*it)->Move(_objects) ;

	}
	
	applyPresents();
	glutPostRedisplay();
	
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
	_menu_cord._y = 31;
	gameController::getInstance()->_level_menu.setCord(_menu_cord);
	gameController::getInstance()->_level_menu.setLevel(_level);
	gameController::getInstance()->_objects.push_back(&gameController::getInstance()->_level_menu);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_level_menu);

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


	//gameController::getInstance()->_level_menu.setLevel(_level);
	std::cout << "Game is loaded\n";
 }
