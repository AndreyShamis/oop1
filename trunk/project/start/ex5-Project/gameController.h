#pragma once
#include <vector>
#include <fstream>
#include <iostream>

#include "Grafic.h"
#include "Keyboard.h"
#include <glut.h>
#include "Wall.h"
#include "User.h"
#include "Computer.h"
#include "Bochka.h"
#include "Space.h"
#include "Bomb.h"
#include "Present.h"
#include "Fire.h"
#include <windows.h> // for PlaySound()
using namespace std;

class gameController
{
public:
	gameController();
	//static 
	Grafic	_graf;
	static Keyboard	_kboard;
	static void idle();
	static void clearAll();
	static void  explodeBomb(const Vertex &_cord);
	void LoadGame();
protected:
	Computer	*_comp;
	User		*_user;
	short int _level;
	static std::vector <Objects *> _objects; 
};
