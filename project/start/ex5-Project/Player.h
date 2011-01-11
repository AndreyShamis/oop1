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
class Player:public Objects
{
public:
	Player();
	void Draw();
	void Press(unsigned char key, int x, int y);
	Way _way;
	void changeCord(float x, float y);
	void Move();

};
