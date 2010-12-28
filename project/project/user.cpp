#include "user.h"

User::User(void)
{
}

// A function that get turn derection from user.
//=============================================================================
// Input: map, pointer to object of class bomb.
// Output: return turn derection.
int	User::getInput(const char map[][MAP_X],Bomb *bombs)
{
	return(GetTurn());
}
