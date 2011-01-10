#pragma once

#include "Objects.h"
#include <vector>
#include <glut.h>
using namespace std ;
class Grafic
{
public:
	Grafic(void);
	void Display();
	static std::vector <Objects *> _objects; 
};
