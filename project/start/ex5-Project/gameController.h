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
#include "Player.h"
#include "Bochka.h"
#include "Space.h"
using namespace std;

class gameController
{
public:
	gameController(void);
	~gameController(void);
	Grafic _graf;
	Keyboard _kboard;
private:

	static std::vector <Objects *> _objects; 
};
