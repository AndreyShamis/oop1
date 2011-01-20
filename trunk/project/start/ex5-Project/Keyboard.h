/*

	This class provide Keyboard functions
	for more inforamtion about all function look to cpp file	
*/

#pragma once
#include "Objects.h"
#include <vector>
using namespace std ;

class Keyboard
{
public:

	static void Press(unsigned char key, int x, int y);
	static void SpecPress(int key, int x, int y);
	void addObject(Objects *newObject);
	static void Keyboard::ClearObjects();
private:
	static vector<Objects*> _objects ;
};
