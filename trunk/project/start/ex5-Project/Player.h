
#pragma once

#include "Objects.h"
#include "Sprite.h"
#include "Bomb.h"
#include "Present.h"
#include "Fire.h"
#include "Grafic.h"
#include <vector>
using namespace std ;

#define KEY_UP	1	//up
#define KEY_DOWN	2	//down
#define KEY_LEFT	3	//left
#define KEY_RIGHT 	4	//right
#define KEY_BOMB	5	//put bomb




#define STEP_SPEED 4

class Player:public Objects
{
public:
	void PlayerStart();
	virtual void Draw();
	virtual void Press(unsigned char key, int x, int y){};
	virtual void SpecPress(int key, int x, int y){};
	short int _way;
	short int _way_prev;
	

	void changeCord(float x, float y);
	virtual void Move(std::vector<Objects *> &_objects);
	short int MathMaxStepSpeed();
	short int getLife()const ;
	void setLife(const short int &new_Val);
	void decLife();
protected:
	short int _life;
	bool _alive;
};
