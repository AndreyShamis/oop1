//includes
#include <iostream>
#include <time.h>
#include <iomanip>	//	for setw
#include <stdlib.h>	// for rand

#include <windows.h>
#include "macros.h" 
#include "Line.h"
#include "Plus.h"
#include "Vertex.h"
#include "Stairs.h"
#include "Square.h"


//Name spaces 
using namespace std;

//Constants

const bool LINE = false;
const bool STAIRS = false;
const bool PLUS = true;
const bool SQUARE = false;

//Global variables declaration
bool paintBoard[MAX_X+1][MAX_Y+1]; 

//Methods declaration
void clearBoard();
void printBoard();
void sleep(unsigned int mseconds);
void gotoTop();



void print_data(Vertex x)
{
	float x1 = x._x;
	float x2 = x._y;
		cout << "------------------------------------------\n" 
			<<"cord 1: " << x1 << "\n"
			<<"cord 2: " << x2 << "\n"
			<< "\n";
}

int main(){
	clearBoard();
	
	if(LINE){
		srand ((int)(time(0)));
		cout << time(0) << "\n";
		
		cout << "Please enter x and y coordinates for one end of the line separated by spaces:" << endl;
		float x0,y0,x1,y1;
		cin >> x0 >> y0; 
		cout << "Please enter x and y coordinates for the second end of the line:" << endl;
		cin >> x1 >> y1;
		Line inputLine = Line(x0,y0,x1,y1);
		clearBoard();
		inputLine.draw(paintBoard);
		printBoard();
		
		Vertex a1;
		a1._x= x0;
		a1._y = y0;

		while(x1 != 99 && y1 != 99)
		{
		cout << "Please enter Lentgh and Zavit" << endl;
		cout << "Cancel : Enter : 99 99" << endl;

		cin >> x1 >> y1;		
		inputLine = Line(a1,x1,y1);
		clearBoard();
		inputLine.draw(paintBoard);
		printBoard();
		print_data(inputLine.getEnd1());
		print_data(inputLine.getEnd2());
		}



		Vertex v1;
		Vertex v2;
		
		v1._x = (float)(rand()% 70);
		v2._x = (float)(rand()% 70);
		v1._y = (float)(rand()% 50);
		v2._y = (float)(rand()% 50);	

		Line inputLine1 = Line(v1,v2);

		print_data(inputLine1.getEnd1());
		print_data(inputLine1.getEnd2());

		inputLine1.draw(paintBoard);
		printBoard();
		clearBoard();

	/*
		Vertex v_arr[1];
	
		v_arr[0]._x = (float)(rand()% 70);
		v_arr[1]._x = (float)(rand()% 70);
		v_arr[0]._y = (float)(rand()% 50);
		v_arr[1]._y = (float)(rand()% 50);

		Line inputLine2 = Line(v_arr);

		print_data(inputLine2.getEnd1());
		print_data(inputLine2.getEnd2());


		inputLine2.draw(paintBoard);
		printBoard();
		clearBoard();
		*/
		Vertex v3;

		for(int op=0;op<20;op++)
		{
			float ll = (float)(rand()%20) + 1;
		v3._x = (float)(rand()% 70);
		v3._y = (float)(rand()% 50);
			float grad =(float)(rand()% 359)+1;

		Line inputLine4 = Line(v3,ll,grad);

		print_data(inputLine4.getEnd1());
		print_data(inputLine4.getEnd2());

		inputLine4.draw(paintBoard);
		printBoard();
		clearBoard();

		}


	
	}


	if (SQUARE){
		Vertex tl,shift;
		tl._x = 10.0;
		tl._y = 10.0;
		shift._x = 2.0;
		shift._y = 2.0;
		//for (int i=0; i< 5; i++)
		//{
			clearBoard();
			Square mySquare = Square(tl,5);
			mySquare.draw(paintBoard);
			printBoard();
			//mySquare.move(shift);
			gotoTop();
			sleep(10000);
		//}	

	}
	
	if (PLUS){
		Vertex t2;
		Vertex shift;

		shift._x = 2;
		shift._y = 1;

		float delta = 1;



		t2._x = 2.0;
		t2._y = 0.0;
		Plus myPlus = Plus(t2,2);
		
		clearBoard();
		myPlus.draw(paintBoard);
		printBoard();
		clearBoard();
		myPlus.grow(delta);
		gotoTop();
		sleep(1000);
		gotoTop();
		

		for (int i=0; i< 100; i++)
		{
			
			myPlus.move(shift);
			clearBoard();
			//myPlus.draw(paintBoard);
			//printBoard();                    ////todo
			//sleep(1);
			gotoTop();


			myPlus.grow(delta);
			clearBoard();
			myPlus.draw(paintBoard);
			printBoard();
			sleep(1);
			gotoTop();

			

			
		}	

	}

	if (STAIRS){
		Vertex t2;
		t2._x = 20.0;
		t2._y = 20.0;
		Stairs myStairs = Stairs(t2,3,3,2);

		myStairs.draw(paintBoard);
		printBoard();
		clearBoard();

		float hh,ww;
		int st;
		srand ((int)(time(0)));

		for (int i=0; i< 0; i++)
		{
			clearBoard();
			t2._x = (float)(rand()% MAX_X);
			t2._y = (float)(rand()% MAX_Y);

			hh = (float)((rand()% 7)+1);
			ww = (float)((rand()% 7)+1);
			st = (int)(rand()%5 )+ 1;
			{

			Stairs myStairs1 = Stairs(t2,hh,ww,st);

			print_data(myStairs1.getBotLeft());

			cout	<< "\nHeight | :	" << hh
					<< "\nWidth  - :	" << ww
					<< "\nStep::		" << st
					<< "\n";
			
			myStairs1.draw(paintBoard);
			}
			printBoard();
			//myStairs.rotate(90);
			//gotoTop();
			//sleep(20);

			cout << "\n\n";
		}
	}
	
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
				(i==0) ? cout << setw(3) << j << '|' : ((j==0) ? cout << '-' : cout << '#');
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
	clock_t goal = mseconds + (clock());
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



