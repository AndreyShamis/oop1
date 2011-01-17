#pragma once

#include "Objects.h"
#include "Bomb.h"
#include "Bochka.h"
#include "Fire.h"
#include <vector>
#include <glut.h>
#include <typeinfo>
using namespace std ;
class Grafic
{
public:
	Grafic();
	static void Display();
	static std::vector <Objects *> _objects; 
	static void addObject(Objects *newObject);
	static void clearObject(Objects *obj);
};
