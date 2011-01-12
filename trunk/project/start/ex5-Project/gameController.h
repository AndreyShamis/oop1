#pragma once
#include <vector>
#include <fstream>
#include <iostream>
//#include "Config.h"
//#include "Objects.h"
#include "Grafic.h"
#include "Keyboard.h"
#include <glut.h>
#include "Wall.h"
#include "User.h"
#include "Computer.h"
#include "Bochka.h"
#include "Space.h"
using namespace std;

class gameController
{
public:
	gameController();
	Grafic		_graf;
	static Keyboard	_kboard;
	static void idle();
private:
	Computer *comp;
	static std::vector <Objects *> _objects; 
};
