

#include "Game.h"

vector<GameObject*> Game:: _vec_objs;
KeyBoard Game::_keyBoard ;

Game::Game(): _window(DEFAULT_WIN_HEIGHT, DEFAULT_WIN_WIDTH, PROG_NAME) {

	// Handling events
	glutIdleFunc(idle);
	glutDisplayFunc(Window::display);  
	glutKeyboardFunc(KeyBoard::keyboard);

};

//this function is called when no other event is hapenning
// this is where the actual program happens - in the project
// this is where the iteration should happen.
void Game::idle(){

	vector<GameObject*>::iterator it ;

	for( it =  _vec_objs.begin() ; it < _vec_objs.end() ; it++ ) {
		(*it)->move( _vec_objs ) ;
	}

	glutPostRedisplay();
}

void Game::play() {

	Player *player = new Player(50, 50);

	_vec_objs.push_back( player ) ;

	_window.addObj( player ) ;
	_keyBoard.addObj( player ) ;
	


	read_board( STAGE_1 ) ;

};

void Game::read_board( char *file_name ) {
	ifstream input_file ;     //file with the board
	char c ;				  // to skip the backspace in the file
	int x=0, y=0 ; // for cordinates on the grafic board

	// to initialize the proportion of the graph by wall size
	Wall *wall = new Wall(x,y);
	int width = wall->getSprite().getWidth() ;
	int hieght = wall->getSprite().getHeight() ;
	delete wall ;

	//open the file
	input_file.open( file_name ) ;

	if( !input_file.is_open() ) {
		cerr << "Error opening input file!" <<endl ;
		exit (EXIT_FAILURE) ;
	}

	//start read the file and create new objects
	for( int i = 0 ; i < MAX_BOARD_HEIGHT ; i++ ) {
		for( int j = 0 ; j < MAX_BOARD_WIDTH ; j++ ) {

			c = input_file.get() ; 

			switch(c) {

			case WALL: {
				Wall *wall = new Wall(x,y) ;
				_vec_objs.push_back( wall ) ;
				_window.addObj( wall ) ;			
				break ;
				}
			case BOX: {
				Box *box = new Box(x,y) ;
				_vec_objs.push_back( box ) ;
				_window.addObj( box ) ;			
				break ;
				}
			default:
				break;
			}
			//advance in the world by 1 to right
			x+=width ;		
		}
		//advance in the world by 1 up and to start of the line
		x = 0 ;
		y+=hieght;

		c = input_file.get() ; // to skip the backspace in the file
	}

	input_file.close() ;
};