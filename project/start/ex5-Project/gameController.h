#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <typeinfo>
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
#include "Menu.h"
#include <windows.h> // for PlaySound()
using namespace std;

class gameController
{
public:
	
	static gameController* getInstance();

protected:
	//static 
	Grafic	_graf;
	static Keyboard	_kboard;
	static void idle();
	static void clearAll();
	static void  explodeBomb(const Vertex &_cord);
	static void reshape(int w, int h);
	void LoadGame();
	static Computer	_comp;
	static User		_user;
	static Menu		_comp_menu;
	static Menu		_user_menu;
	gameController();
	static gameController *_inst;
	static short int _level;
	static std::vector <Objects *> _objects; 
	static void Reload_Game_Stat();
	static void decreaseTimer();
	static void removeDisabledObjects();
	static void applyPresents();
	static void IncreaseAllBombsTimers();
	static void ExplodeAllBombsTimers();
};
