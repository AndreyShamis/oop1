#pragma once
//#include "Config.h"
#include <vector>
#include "Sprite.h"

class Objects
{
public:
	Objects();
	virtual ~Objects();
	virtual void Draw() {};
	virtual void Move(std::vector<Objects *> &_objects) {};
	virtual void Press(unsigned char key, int x, int y) {};
	virtual void SpecPress(int key, int x, int y) {};
	virtual void VirtualPress(std::vector <Objects*> &_objects) {};
	virtual void decTimer() {};
	virtual short int getTimer() {return 0;};
	virtual void IncereaseTimer(){};
	virtual short int getPresentType(){return 0;};

	void setCord(const Vertex &newCoordinate);
	void setCordByFloat(const float &x,const float &y);
	bool checkCollision(const Vertex &topLeft,const float &_Objwidth,const float &_Objheight);
	Vertex getCord()const;

	virtual void Disable();
	bool isEnabled() const;
	
	int movable;
	int intelect;

	bool isTakeable();
	bool isTaked();
	void setTaked();
	void setSize();
protected:
	std::vector <Sprite> _sprite;
	bool _enabled;
	Vertex _cord;
	int _timer;
	bool _taked;
	bool _takable;
	float _height;
	float _width;


};
