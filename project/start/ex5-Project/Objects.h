#pragma once
//#include "Config.h"
#include <vector>
#include "Sprite.h"
class Objects
{
public:
	Objects(void);
	virtual void Draw() {};
	virtual void Press(unsigned char key, int x, int y) {};
	Vertex _cord;
	std::vector <Sprite> _sprite;
private:


};
