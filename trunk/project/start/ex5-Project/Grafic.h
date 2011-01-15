#pragma once

#include "Objects.h"
#include "Bomb.h"
#include <vector>
#include <glut.h>
#include <typeinfo>
using namespace std ;
class Grafic
{
public:
	Grafic(void);
	static void Display();
	static std::vector <Objects *> _objects; 
	static void removeObjects();
	static void addObject(Objects *newObject);
};
