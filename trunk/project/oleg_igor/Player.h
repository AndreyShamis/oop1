#pragma once

#include "macros.h"
#include "Sprite.h"
#include "GameObject.h"

#define PLAYER_PIC "sprites/player_rgba.txt"

#define PUT_BOMB 98  //the command of put a bomb ('b' in ascii)
#define UP_D 72        //the command of go up
#define DOWN_D 80		 //the command of go down
#define LEFT_D 75		 //the command of go left
#define RIGHT_D 77	 //the command of go right

#define DEFAULT_SPEED 2

class Player: public GameObject {
public:
	Player( double xPos, double yPos );
	int getTransX();
	int getTransY();
	void addTransX(double x);
	void addTransY(double y);
	void setDirection(direction dir); 


	virtual void draw();
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void move( vector<GameObject*> &all_objs ) ;
private:
	

	double _steps ;
	direction _direction;

	bool is_intersection( vector<GameObject*> &all_objs ) ; 

};