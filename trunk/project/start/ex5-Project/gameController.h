#pragma once
#include <vector>
#include <fstream>
#include <iostream>
//#include "Config.h"
//#include "Objects.h"
#include "Grafic.h"
#include <glut.h>
#include "Wall.h"

using namespace std;

class gameController
{
public:
	gameController(void);
	~gameController(void);
private:

	static std::vector <Objects *> _objects; 
};
