/*

	This class provide a class for all drowable object which
	be drawed


	
*/

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
	static std::vector <Objects *> _objectsDrow; 
	static void addObject(Objects *newObject);
	static void clearObject(Objects *obj);
};
