
#include "Player.h"

Player::Player( double xPos, double yPos ) : GameObject(xPos,yPos) {

	_sprites.push_back(PLAYER_PIC) ;
	_steps = DEFAULT_SPEED ;
	_direction = RIGHT;
}

void Player::move( vector<GameObject*> &all_objs ){

	//check if there is an intersection in this direction
	if( is_intersection( all_objs ) )
		return ;

	//if there wasnt intersection move the player
	switch(_direction) {
		case LEFT: 
			addTransX(-_steps); 
			break ;
		case RIGHT:			
			addTransX(+_steps);			
			break ;
		case UP:
			addTransY(+_steps); 			
			break ;
		case DOWN:
			addTransY(-_steps); 			
			break ;
		default:
			break;
      }
}

bool Player::is_intersection( vector<GameObject*> &all_objs ) {
	vector<GameObject*>::iterator it ;

	

	for( it =  all_objs.begin() ; it < all_objs.end() ; it++ ) {

//		if( _xPos < (*it)->getxPos()  &&  _yPos < (*it)->getyPos() )
//			return (true) ;
	}


	return (false) ;
};

int Player::getTransX() {
	return _xPos;
}

int Player::getTransY() {
	return _yPos;
}

void Player::addTransX(double x) {
	_xPos+=x;
}

void Player::addTransY(double y) {
	_yPos+=y;
}

void Player::setDirection(direction dir){
	_direction = dir;
}

void Player::draw() {

	//  clear all pixels  
    glClear (GL_COLOR_BUFFER_BIT);

	vector<Sprite>::iterator it ;

	it = _sprites.begin() ;
	it->draw(_xPos, _yPos) ;
}

void Player::keyboard(unsigned char key, int x, int y) {
	switch(key) {
	case LEFT_D: case 'a':
		setDirection(LEFT); 
		break ;
	case RIGHT_D: case 'd':
		setDirection(RIGHT); 
		break ;
	case UP_D: case 'w':
		setDirection(UP); 
		break ;
	case DOWN_D: case 's':
		setDirection(DOWN); 
		break ;
	default:
		setDirection(NONE);
		break;
	}
}


// **************** draw by points ********************
	/*

	// Drawing the object
	glBegin(GL_POINTS);			// The object pixels
		for (int i=0;i<15;i++)
			for (int j=0;j<15;j++) {
				glColor3f( getPixel(i,j)._r ,getPixel(i,j)._g , getPixel(i,j)._b );
				glVertex2i(i+getTransX(),j+getTransY());
			}
	glEnd();	
	*/

// **************** draw by polygon ********************
	/*
	//  draw white polygon (rectangle) with corners at
//  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f (0, 0, 0.0);
        glVertex3f (50, 0, 0.0);
		glVertex3f (50, 50, 0.0);
        glVertex3f (0, 50, 0.0);
        
    glEnd();

//	glFlush ();

	*/