#pragma once

#include "Objects.h"
#include "Bomb.h"
#include <vector>
#include <glut.h>
using namespace std ;
class Grafic
{
public:
	Grafic(void);
	static void Display();
	static std::vector <Objects *> _objects; 
	void removeObject(Objects &object);
	static void addObject(Objects *newObject);
};
