// A modul that manage input and output.


//                               Include section
//=============================================================================
#include "io.h"


//                               Function section
//=============================================================================


//================== Get turn function ========================================
//	return
//===============Input Code ===================================================
//	10	-	exit -game
//	20	-	save
//	30	-	new game
//	1	up
//	2	down
//	3	left
//	4	right
//	5	put bomb
//=============================================================================
int GetTurn()
{
    char key = '0';	// Difine presed key from keyboord.

	int result = 0;	// Difine result of presed key from keyboord.

	while(!result)
	{
		// Get key from keyboord.
		key = _getch();

		switch(key)
		{
		case 'q':				//	q key
			result	=	10;
			break;
		case 's':				//	S key
			result	=	20;
			break;
		case 'n':				//	N key
			result	=	30;
			break;

		case ' ':				//	Space key
			result	=	5;
			break;
		case 'b':				//	b key
			result	=	5;
			break;

		case 0x48:				//	Up key
			result	=	1;
			break;
		case '8':					//	Up key
			result	=	1;
			break;

		case 0x4d:				//	Right key
			result	=	4;
			break;
		case '6':				//	Right key
			result	=	4;
			break;

		case 0x4b:				//	Left key
			result	=	3;
			break;
		case '4':				//	Left key
			result	=	3;
			break;

		case 0x50:				//	Down key
			result	=	2;
			break;
		case '2':				//	Down key
			result	=	2;
			break;
		}
	}
	return (result);
}

// A function that get chrecter from //TODO
//=============================================================================
char getChar()
{
	char key = '0';
	key =_getch();
	return(key);
}

// Afunction that ask user if he want to exit the game.
//=============================================================================
// Output: If the user want to exit - return true.
//	THIS FUNCTION NOT USED IN THIS VERSION
//	NEEDED TO FUTURE
bool questionMess()
{
	char answer = '0';	// Difine user answer.
	std::cout << "Are you sure?\n y(Yes)/n(No):";
	std::cin >> answer;		// get the answer from user.
	
	
	// If the user answer yes - return true.
	if(answer == 'y')
		return true;
	
	return false;
}