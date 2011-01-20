/*

	This class provide  Player class
	This is main class for User class and Computer class
	
*/

#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Bomb.h"
#include "Present.h"
#include "Fire.h"
#include "Grafic.h"
#include <vector>
using namespace std ;

#define KEY_UP		1	//up
#define KEY_DOWN	2	//down
#define KEY_LEFT	3	//left
#define KEY_RIGHT 	4	//right
#define KEY_BOMB	5	//put bomb


class Player:public Objects
{
public:
	void PlayerStart();
	virtual void Draw();
	virtual void Press(unsigned char key, int x, int y){};
	virtual void SpecPress(int key, int x, int y){};
	virtual void Move(vector<Objects *> &_objects);

	short int	getLife()const ;
	void		setLife(const short int &new_Val);
	void		decLife();
	
	void		setDead();
	void		setAlive();
	bool		getAlive()const;
protected:
	short int	_life;
	void		mathNewCord();
	void		changeCord(const float &x,const float &y);
	void		changeNewCord(const float &x,const float &y);
	Vertex		_new_cord;
	short int	_way_prev;
	short int	_way;
	bool		_alive;
	
};
