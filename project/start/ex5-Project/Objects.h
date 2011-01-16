#pragma once
//#include "Config.h"
#include <vector>
#include "Sprite.h"

class Objects
{
public:
	Objects(void);
	virtual void Draw() = 0;
	virtual void Move(std::vector<Objects *> &_objects) {};
	virtual void Press(unsigned char key, int x, int y) {};
	virtual void SpecPress(int key, int x, int y) {};
	virtual void VirtualPress(std::vector <Objects*> &_objects) {};
	Vertex _cord;
	std::vector <Sprite> _sprite;
	int movable;
	int intelect;
	bool _enabled;
	virtual short int getTimer() {return 0;};

	Vertex getCord();
	bool checkCollision(const Vertex &topLeft,const float &_Objwidth,const float &_Objheight);
protected:
	int _timer;


};
