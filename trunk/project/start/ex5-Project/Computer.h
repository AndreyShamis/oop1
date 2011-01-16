#pragma once
#include "Player.h"
#include "Bochka.h"
#include "Fire.h"
#include <time.h>
#include <typeinfo>
using namespace std;
class Computer:public Player
{
public:
	Computer();
	virtual void VirtualPress(std::vector <Objects*> &_objects);
	int _computerTryDetectEnemy ;
	const Vertex *_user_enemy_cord;
	void setUserEnemyCord(const Vertex *_cord);
private:
	Vertex _newCoordinate;
	bool checkIfCellHaveBomb(std::vector <Objects*> &_objects,const Vertex &_coordinate);
	void turnLogic(const short int &turnCode);
	bool checkForBarrel(std::vector <Objects*> &_objects);
	bool checkExplodeBomb(std::vector <Objects*> &_objects,const Vertex &newCord);

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
