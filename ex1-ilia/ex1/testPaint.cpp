

//includes
#include <iostream>
#include <time.h>
#include <windows.h>
#include "macros.h" 
#include "Line.h"
//#include "Plus.h"
#include "Vertex.h"
//#include "Stairs.h"
//#include "Square.h"


//Name spaces 
using namespace std;

//Constants

const bool LINE = true;
const bool STAIRS = false;
const bool PLUS = false;
const bool SQUARE = false;

//Global variables declaration
bool paintBoard[MAX_X+1][MAX_Y+1]; 

//Methods declaration
void clearBoard();
void printBoard();
void sleep(unsigned int mseconds);
void gotoTop();


int main(){
	clearBoard();
	
	if(LINE){
		cout << "Please enter x and y coordinates for one end of the line separated by spaces:" << endl;
		float x0,y0,x1,y1;
		cin >> x0 >> y0; 
		cout << "Please enter x and y coordinates for the second end of the line:" << endl;
		cin >> x1 >> y1;
		Line inputLine = Line(x0,y0,x1,y1);

		clearBoard();
		inputLine.draw(paintBoard);
		printBoard();
	}
/*
	if (SQUARE){
		Vertex tl,shift;
		tl._x = 10.0;
		tl._y = 10.0;
		shift._x = 2.0;
		shift._y = 2.0;
		for (int i=0; i< 5; i++)
		{
			clearBoard();
			mySquare.draw(paintBoard);
			printBoard();
			mySquare.move(shift);
			gotoTop();
			sleep(1000);
		}	
	}

	if (PLUS){
		Vertex t2;
		t2._x = 15.0;
		t2._y = 15.0;
		Plus myPlus = Plus(t2,5);
		for (int i=0; i< 5; i++)
		{
			clearBoard();
			myPlus.draw(paintBoard);
			printBoard();
			myPlus.grow(1);
			gotoTop();
			sleep(1000);
		}	

	}

	if (STAIRS){
		Vertex t2;
		t2._x = 20.0;
		t2._y = 20.0;
		Stairs myStairs = Stairs(t2,3,3,2);
		for (int i=0; i< 12; i++)
		{
			clearBoard();
			myStairs.draw(paintBoard);
			printBoard();
			myStairs.rotate(90);
			gotoTop();
			sleep(1000);
		}

*/	

	//}

	int xx;
	cin >> xx;
	return 0;
}


/*
* Clears the board.
*/
void clearBoard(){
	for(int i=0;i<=MAX_X;i++){
		for(int j=0;j<=MAX_Y;j++){
			paintBoard[i][j]= false;
		}
	}
}

/*
* Prints the board to the standart output.
*/
void printBoard(){
	for(int j=0;j<=MAX_Y;j++){
		for(int i=0;i<=MAX_X;i++){				
			if(paintBoard[i][j])
				cout << '*';
			else{
				//Draw the axes 
				(i==0) ? cout << '|' : ((j==0) ? cout << '-' : cout << '#');
			}		
		}
		cout << endl;
	}
}

/*
* Delay method, Used for the animation
*/
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

/*
* Places the cursor in the top left corner of the console screen
*/
void gotoTop()
{
	HANDLE screen_buffer_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(screen_buffer_handle, coord);
}



