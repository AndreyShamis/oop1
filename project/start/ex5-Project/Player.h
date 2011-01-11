#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;
enum Way
{
	GO_UP,
	GO_DOWN,
	GO_LEFT,
	GO_RIGHT
};

#define STEP_SPEED 1

class Player:public Objects
{
public:
	Player();
	virtual void Draw();
	virtual void Press(unsigned char key, int x, int y);
	virtual void SpecPress(int key, int x, int y);
	Way _way;
	void changeCord(float x, float y);
	virtual void Move(std::vector<Objects *> &_objects);

};
