#include "gameController.h"
//=============================================================================
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
bool		gameController::_GameStared		=	false;
bool		gameController::_exitGame		=	false;
bool		gameController::_reloadGame		=	false;

//=============================================================================
//=============================================================================
//	singleton :: getInsatnce of sigleton
//	if object not created create him
gameController* gameController::getInstance()
{
	if(_inst == NULL)
		_inst = new gameController;	//	create

	return _inst;					//	return what have

}

//=============================================================================
//	Constructor Of game COntroller
//	This constructor is PRIVATE becouse it is singleton
gameController::gameController()
{
	_level = 1;						//	Seting default level start
	LoadGame();						//	Call function which loading
	//	every think else
}

//=============================================================================
//	Glut reshape function NOT USED
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
//	Function to load all grafik thinks
void gameController::LoadGame()
{

	glutIdleFunc(idle);						//	set IDLE function
	glutDisplayFunc(Grafic::Display);		//	set DIsplay function
	glutSpecialFunc(Keyboard::SpecPress);	//	set Keyboard function
	glutKeyboardFunc(Keyboard::Press);		//	set Keyboard function
	//	Sound Play
	//sndPlaySound(L"SOUND/BackGround_Sound.wav", SND_LOOP | SND_ASYNC );
}

//=============================================================================
//	Function which working whith presents
void gameController::applyPresents()
{
	vector<Objects*>::iterator it;			//	vector iterator

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		if((*it)->isTaked())
		{
			if((*it)->getPresentType() == PRESENT_BOMB)
			{
				//	Puting randomly bomb on a map
				Vertex _dneedit = (*it)->getCord();	//	Get coordinate
				PutRandomBomb((int)_dneedit._x);	//	Call to function
			}
			else if((*it)->getPresentType() == PRESENT_TIME)
				//	Increasing all timer for all bombs
				IncreaseAllBombsTimers();
			else if((*it)->getPresentType() == PRESENT_LIGHT)
				//	Exploading all boms
				ExplodeAllBombsTimers();

			(*it)->Disable();

		}
}

//=============================================================================
//	Function For increasing timer counter
//	Used where some player get present TIMER
void gameController::IncreaseAllBombsTimers()
{

	vector<Objects*>::iterator it ;				//	vector iterator

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled())	
			(*it)->IncereaseTimer();			//	increasing

}

//=============================================================================
//	The function geting some integer for run random function and trying to 
//	dect emty cell for locating new onbject
//	Return topleft coordinate for new cell
Vertex gameController::GetEmptyCellCord(const int &i)
{
	srand ( i );
	static Vertex _new_cord;	//	coordinate be returned
	int trys = 100;				//	100 trys to dect emty cell
	//	need for situation when all cell busy
	//	//	help variables
	int x,y;
	vector<Objects*>::iterator it ;	//	vector iterator
	bool copm	=	false;		//	indiation for compleated math
	//	tring to find empty cell
	while(true)
	{
		//	get random value to X and Y
		x =	rand()%(int)(_WORLD_width-2*PIC_WIDTH)+1;
		y =	rand()%(int)(_WORLD_height-2*PIC_WIDTH)+1;
		
		//	Block to find correct coordiantes for X
		for(int i =0;i <PIC_WIDTH && (int)x%PIC_WIDTH !=0;i++)
			x+=1;
		//	Block to find correct coordiantes for Y
		for(int i =0;i<PIC_WIDTH && (int)y%PIC_WIDTH !=0;i++)
			y+=1;

		_new_cord._x = x;		//	seting the coordinates
		_new_cord._y = y;		//	seting the coordinates

		
		
		for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		{
			//	Cheking collisions	
			if((*it)->isEnabled() 
				&& (*it)->checkCollision(_new_cord,PIC_WIDTH,PIC_WIDTH))
			{	//	if have colision try another coordinates
				copm = false;
				break;
				
			}
			//	If not found any colision return coordinated
			if(copm)
				return(_new_cord);
		}
		trys--;					//	decriasing number of trys
		if(trys < 0)			//	if smaller than zero
			break;	
		
	}
	_new_cord._x = 0;			//	seting default by zero
	_new_cord._y = 0;			//	seting default by zero

	return(_new_cord);

}

//=============================================================================
//	Function which puting rundom bomb
//	Geting some value for ran ranf function
void gameController::PutRandomBomb(const int &i)
{
	Vertex _new_cord = GetEmptyCellCord(i);	//	try to find empty cell
	//	if the cell not null coordinates
	//	put bomb
	if(_new_cord._x != 0 && _new_cord._y !=0)
	{
		Bomb *new_bomb = new Bomb();
		new_bomb->setCord(_new_cord);
		gameController::getInstance()->_objects.push_back(new_bomb);
		gameController::getInstance()->_graf.addObject(new_bomb);
	}
}

//=============================================================================
//	Function which exploading all bombs in game which are runing in this time
void gameController::ExplodeAllBombsTimers()
{

	vector<Objects*>::iterator it ;	//	vectro iterator

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled())
		{
			
			(*it)->Disable();					//	disabling this bomb
			explodeBomb((*it)->getCord());		//	exploading this bomb

		}	
}

//=============================================================================
//	Exploading Bomb
void  gameController::explodeBomb(const Vertex &_cord)
{ 

	Fire *new_fire=NULL;						//	Fire variable

	new_fire = new Fire(EXP_START_USR,13);		//	Creating Fire on place 
	new_fire->setCord(_cord);					//	where was bomb
	Grafic::addObject(new_fire);				//	Drawing vector
	_objects.push_back(new_fire);				//	Objects Vector

	//	Check if the fire puting on player user
	if( _user.checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))
		_user.setDead();
	//	Check if the fire puting on player computer
	else if(_comp.checkCollision(_cord,PIC_WIDTH,PIC_WIDTH))		
		_comp.setDead();

	for(int i=0;i<FIRE_SIZE;i++)
	{
		Vertex _fire_cord = _cord;				//	Fire new coordinate
		char pic_fire[CHAR_MAX_STR_LEN];		//	path to picture

		//	creatin right path file name and coordinates
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
	
		bool have_col = false;					//	bool if find colision
		vector<Objects*>::const_iterator it ;	//	vector iterator

		for( it =  _objects.begin() ; it != _objects.end() ; it++ )
		{
			//	Check if object enabled
			if((*it)->isEnabled())
			{
				//	If this block thats mean no fire be drawed but if on 
				//	the side of wall we have box we need to open him
				if( typeid(**it) == typeid(Wall) 
					&& (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{
					have_col= true;
					break;
				}
				
				if( typeid(**it) == typeid(User) 
					&& (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{	//	Check if the fire puting on player user
					_user.setDead();
					have_col = false;
				}
				else if( typeid(**it) == typeid(Computer)
					&& (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{	//	Check if the fire puting on player Computer
					_comp.setDead();
					have_col = false;
				}
				//	If have box 
				if(typeid(**it) == typeid(Bochka) 
					&& (*it)->checkCollision(_fire_cord,PIC_WIDTH,PIC_WIDTH))
				{
					
					have_col= false;	//	set have bool to false to draw fire
					(*it)->Disable();	//	disable box
					
					//	rundom some number for put present
					//	Now LIMIT_PRESENT_CHASE it is like 75 % chanse to put present
					int chanse_put_suprise = (int)(rand()%MAX_PRESNT_CHANSE) +1;
					
					if(chanse_put_suprise < LIMIT_PRESENT_CHASE)
					{
						//	Puting present
						Present *new_present;
						new_present = new Present();
						new_present->setCord((*it)->getCord());
						Grafic::_objectsDrow.push_back(new_present);
						_objects.push_back(new_present);
					}

				}

			}

		}
		//	Check if need to draw fire
		if(!have_col)	//	if have colsision with wall
		{	
			//	Drawing fire
			new_fire = new Fire(pic_fire,13);
			new_fire->setCord(_fire_cord);
			Grafic::_objectsDrow.push_back(new_fire);
			_objects.push_back(new_fire);
		}
	}

}

//=============================================================================
//	garbage colector function
void gameController::removeDisabledObjects()
{
	int _vec_size = (int)_objects.size();		//	get vector size
	for(int i=0;i<_vec_size;i++)				//	for all objects in vector
	{
		if(!_objects[i]->isEnabled())			//	if object disabled
		{										//	delete him
			Objects *temp = _objects[i];
			gameController::getInstance()->_graf.clearObject(_objects[i]);
			_objects.erase(_objects.begin()+i);
			delete temp;
			_vec_size--;
			i--;
		}
	}


}

//=============================================================================
//	Decrease for all bombs timer
void gameController::decreaseTimer()
{
	vector<Objects*>::iterator it ;				//	vector iterator

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
		(*it)->decTimer();						//	call decriaser
	
}

//=============================================================================
//	Function which preparing game to play
//	Deleting objects from previuos game
void gameController::prepareGame()
{
	//	deliting Drawable objects and Keybord
	gameController::getInstance()->_graf._objectsDrow.clear();
	gameController::getInstance()->_kboard._objects.clear();

	vector<Objects*>::iterator iter ;			//	vector iterator
	for( iter =  _objects.begin() ; iter !=_objects.end() ; iter++ )
	{
		if(typeid(**iter) != typeid(User)  && typeid(**iter) != typeid(Computer) 
			&&  typeid(**iter) != typeid(Menu)  &&  typeid(**iter) != typeid(Level))
			delete *iter;						//	clear memory
	}

	gameController::getInstance()->_objects.clear();	//	clear main vector
}

//=============================================================================
//	Function for restart game
void gameController::RestartAllGame()
{
	prepareGame();				//	prepare game for play
	_level = 1;					//	set level to 1
	_GameStared = false;		//	bool to load objects from map
}

//=============================================================================
//	Game logic 
//	Levels ,Lifes , Clearing objects function calls
void gameController::GameLogic()
{
	if(!_comp.getAlive())		//	check if need decriase life for user
		_comp.decLife();
	if(!_user.getAlive())		//	check if need decriase life for computer
		_user.decLife();

	prepareGame();				//	prepare game
	
	//	Load next level logic
	if(_user.getLife() >0 && _comp.getLife() == 0)
	{
		_level++;
		_user.setLife(3);
		_comp.setLife(3);
		
	}
	//	Exit game logic if user game over
	else if(_user.getLife() == 0 && _comp.getLife()>=0)
		exit(EXIT_SUCCESS);
	//	If it is last level also exit end clear objects
	if(_level > MAX_LEVEL)
		exit(EXIT_SUCCESS);

	_comp.setAlive();			//	set user is alive
	_user.setAlive();			//	set computer is alive
	Reload_Game_Stat();			//	Load objects

}
//=============================================================================
//	Function to know if game not loaded and we need to load game
//	or exit from game or load new game
void gameController::PreGameOPtionsLogic()
{
	//	Load game 
	if(!_GameStared)
	{
		Reload_Game_Stat();	
		_GameStared = true;
	}
	//	Exit from game
	if(_exitGame)
	{
		prepareGame();
		exit(EXIT_SUCCESS);
	}
	//	Reload game
	if(_reloadGame)
	{
		RestartAllGame();
		_reloadGame = false;
		_user.setLife(3);
		_comp.setLife(3);
	}
}
//=============================================================================
void gameController::idle()
{
	vector<Objects*>::iterator it ;		//	vector iterator

	//	Function to know if game not loaded and we need to load game
	//	or exit from game or load new game
	PreGameOPtionsLogic();
	
	//	Run game logic if we need reload game
	if(!_comp.getAlive() || !_user.getAlive() )
		GameLogic();

	removeDisabledObjects();			//	remove disabled objects from memory
	decreaseTimer();					//	decrease timer for bombs

	

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		//	if this intelect computer do computer logic
		if((*it)->isIntilect())
			(*it)->VirtualPress(_objects);
		if(typeid(**it) == typeid(Bomb) && (*it)->isEnabled() 
			&& (*it)->getTimer() <=0 )
		{	//	logic for bombs
			(*it)->Disable();
			explodeBomb((*it)->getCord());			
		}
		//	logic for fire
		else if(typeid(**it) == typeid(Fire) && (*it)->getTimer() <0 )
			(*it)->Disable();	 
		else if((*it)->isEnabled())
			(*it)->Move(_objects) ;		//	all move objects

	}
	
	applyPresents();					//	do present logic
	glutPostRedisplay();				//	glut call
	
}

 //=============================================================================
 void gameController::Reload_Game_Stat()
 {
	int countX=0,						//	coordinate for objects
		countY=0;						//	coordinate for objects
	char path[CHAR_MAX_STR_LEN];		//	Path to map file
	ifstream myReadFile;				//	File stream
	
	memset(path,'\0',CHAR_MAX_STR_LEN);	//	Clear empty string

	//	Start string manipulation
	//	independ on level of game
	strcpy_s(path,MAPS_FOLDER);			
	if(_level == 1)
		strcat_s(path,"/map1.txt");
	else if(_level == 2)
		strcat_s(path,"/map2.txt");
	else if(_level == 3)
		strcat_s(path,"/map3.txt");
	else if(_level == 4)
		strcat_s(path,"/map4.txt");
	else if(_level == 5)
		strcat_s(path,"/map5.txt");
	
	//	Open file
	myReadFile.open(path);
	

	// If the file is opened - load the map.
	if (myReadFile.is_open()) 
	{
		//	Indication on console
		std::cout << "Start loading textures\n";
		//	while not end of line
		while (!myReadFile.eof())
		{
			// Load line to array.
			char ch = myReadFile.get();
			_WORLD_width	= max(_WORLD_width,countX*PIC_WIDTH);
			_WORLD_height	= max(_WORLD_height,countY*PIC_WIDTH);
			if(ch == FENCE)			//	Wall
			{
				//	Creating on map Wall
				Wall *wall = new Wall();
				wall->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
				gameController::getInstance()->_objects.push_back(wall);
				gameController::getInstance()->_graf.addObject(wall);
			}
			//	***	Block to load emty cell grafik for better speed in game
			//	***	was disabled
			//else if(ch == LANE)		//	space
			//{
			//	Space *lane = new Space();
			//	lane->_cord._x = countX*PIC_WIDTH;
			//	lane->_cord._y = countY*PIC_WIDTH;
			//	gameController::getInstance()->_objects.push_back(lane);
			//	gameController::getInstance()->_graf.addObject(lane);
			//}
			else if(ch == BARREL)	// box
			{	//	Creating on map Box
				Bochka *bochka = new Bochka();
				bochka->setCordByFloat(countX*PIC_WIDTH,countY*PIC_WIDTH);
				gameController::getInstance()->_objects.push_back(bochka);
				gameController::getInstance()->_graf.addObject(bochka);
			}
			else if(ch == '\n')
			{
				//	Cordinate manipulations
				countY+=1;
				countX=-1;
			}

			
			countX++; // Increase num of line.
		}
	}
	else
	{
		std::cout << "Can not open file " << path << "\n";
	}

	myReadFile.close();

	//	locate user and computer on map
	gameController::getInstance()->_user.setCordByFloat(1*PIC_WIDTH, 1*PIC_WIDTH);
	_user.setPointerExitGame(&gameController::getInstance()->_exitGame);
	_user.setPointerReloadGame(&gameController::getInstance()->_reloadGame);
	gameController::getInstance()->_comp.setCordByFloat(18*PIC_WIDTH, 18*PIC_WIDTH);


	//	load computer and user to vectors
	_objects.push_back(&gameController::getInstance()->_user);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_user);
	_kboard.addObject(&gameController::getInstance()->_user);
	gameController::getInstance()->_comp.setUserEnemyCord(gameController::getInstance()->_user.getPointerCoordinate());
	_objects.push_back(&gameController::getInstance()->_comp);
	gameController::getInstance()->_graf.addObject(&gameController::getInstance()->_comp);
	_kboard.addObject(&gameController::getInstance()->_comp);

	//	Menu level objects manipulations block
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

	std::cout << "Game is loaded\n";
 }
