#pragma once
//#include "Config.h"
#include <vector>
#include "Sprite.h"
class Objects
{
public:
	Objects(void);
	virtual void Draw() {};
	virtual void Move(std::vector<Objects *> &_objects) {};
	virtual void Press(unsigned char key, int x, int y) {};
	virtual void SpecPress(int key, int x, int y) {};
	virtual void VirtualPress(){};
	Vertex _cord;
	std::vector <Sprite> _sprite;
	int movable;
	int intelect;
private:


};
