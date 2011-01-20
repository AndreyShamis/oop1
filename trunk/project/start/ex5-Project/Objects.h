/*

	This class provide main class for the game
	which controling the all game
	for more inforamtion about all function look to cpp file
	
*/

#pragma once

#include <vector>
#include "Sprite.h"
using namespace std ;

class Objects
{
public:
	Objects();
	virtual ~Objects();
	virtual void	Draw() {};
	virtual void	Move(vector<Objects *> &_objects) {};
	virtual void	Press(unsigned char key, int x, int y) {};
	virtual void	SpecPress(int key, int x, int y) {};
	virtual void	VirtualPress(vector <Objects*> &_objects) {};
	virtual void	decTimer() {};
	virtual short int	getTimer() {return 0;};
	virtual void		IncereaseTimer(){};
	virtual short int	getPresentType(){return 0;};

	void	setCord(const Vertex &newCoordinate);
	void	setCordByFloat(const float &x,const float &y);
	bool	checkCollision(const Vertex &topLeft
		,const float &_Objwidth,const float &_Objheight);
	Vertex	getCord()const;

	virtual void Disable();
	bool	isEnabled() const;
	bool	getMovable();
	bool	isTakeable();
	bool	isTaked();
	void	setTaked();
	void	setSize();
	virtual bool isIntilect(){return 0;};
protected:
	std::vector <Sprite> _sprite;
	bool	_enabled;		//	if object enabled
	Vertex	_cord;			//	coordinate of object
	int		_timer;			//	timer for object
	bool	_taked;			//	if the takeable object is taked
	bool	_takable;		//	if the object can be taked
	float	_height;		//	size
	float	_width;			//	size
	bool	_intelect;		//	if the object is intelectual 
	bool	_movable;		//	if another object can move over this object


};
