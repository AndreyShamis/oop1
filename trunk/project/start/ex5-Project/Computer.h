#pragma once
#include "Player.h"

#define KEY_UP	1	//up
#define KEY_DOWN	2	//down
#define KEY_LEFT	3	//left
#define KEY_RIGHT 	4	//right
#define KEY_BOMB	5	//put bomb

class Computer:public Player
{
public:
	Computer();
	void VirtualPress(std::vector <Objects*> &_objects);
	int _computerTryDetectEnemy ;
	const Vertex *_user_enemy_cord;
	void setUserEnemyCord(const Vertex *_cord);
private:
	Vertex _newCoordinate;
	void turnLogic(const int &turnCode);
	//=============================================================================
	// Output: if yes return true
	// else return false.
	// ****  the parameter can be changed.
	// #### By chenging this parameter, we candifine the game Difficulty.
	bool checkEnemyinBombRaound();

	// A function that try to detect derection to enemy.
	//=============================================================================
	// Output: if success to detect - return derection, otherwise - retur false.
	short getTurnCodeByDetectEnemy();

	// A function that check if new coordinates is correct 
	//=============================================================================
	// Input: map, new coordinate.
	// Output: if yes return true, otherwise return false.
	bool CheckCorrect(const Vertex &newcoordinate,std::vector <Objects*> &_objects);
};
