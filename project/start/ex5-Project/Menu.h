#pragma once
#include "Objects.h"
#include "Sprite.h"
#include <vector>
using namespace std ;
class Menu : public Objects
{
public:
	Menu(const bool &comp);
	virtual void Draw();
	void setLife(const short int &value);
private:
	short int _life;

};
