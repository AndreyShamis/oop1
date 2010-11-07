ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	ex1*	
****************************************************************************************************
****************************************************************************************************

Students Info:
**************

Andrey Shamis 321470882
Ilia Gaysinsky 309480051


General explanation of the exercise:
************************************

A Program that Implement a primitive animation tool that allows to draw several geometric shapes and 
make them a number of transformations!

List of files that been created:


file name:  | Explonation:
****************************************************************************************************
	    |
Line.cpp    | A class that reprisent line at drow board. The user can: set coordinate of the line,
	    | to drow the line , can set lenth of line, and mach more the line implemented by 
	    | Bresenham Algorithem.
----------------------------------------------------------------------------------------------------
	    |
Line.h	    | Is a heder file of line.cpp
	    |
****************************************************************************************************
	    |
Square.cpp  | A class that reprisent square at drow board. the user can: drow the squere, set it 
	    | coordinate, change his size of side and mach more.
	    |
----------------------------------------------------------------------------------------------------
	    |
Square.h    | Is a heder file of Square.cpp
	    |
****************************************************************************************************
	    |
Plus.cpp    | A class that reprisent plus at drow board. the user can: drow the plus, set it 
	    | coordinate, change his size of side, move him at the board and mach more.
	    |
----------------------------------------------------------------------------------------------------
	    |
Plus.h      | Is a heder file of Plus.cpp
	    |
****************************************************************************************************
	    |
Stairs.cpp  | A class that reprisent Stairs at drow board. the user can: drow the Stairs, set it 
	    | coordinate, change stairs lenth, change stais width, rotate the stairs and mach more.
	    |
----------------------------------------------------------------------------------------------------
	    |
Stairs.h    | Is a heder file of Stairs.cpp
	    |
****************************************************************************************************
	    |
Vertex.h    | Not created by student: A struct that repsresents a point in a cartesian coorsinates 
	    | system.
	    |
----------------------------------------------------------------------------------------------------
	    |
macros.h    | Not created by student: The "Math Constants" are not defined in Standard C/C++. 
	    |                  	      Therefore, in order to use them, you have to first define 
	    |			      _USE_MATH_DEFINES and then include cmath or math.h as below.
	    |
****************************************************************************************************


Main data structures and their functionality:
*********************************************


Notable algorithms: Bresenham's line algorithm
**********************************************

The Bresenham line algorithm is an algorithm which determines which points in an n-dimensional 
rastershould be plotted in order to form a close approximation to a straight line between two given 
points. It is commonly used to draw lines on a computer screen, as it uses only integer addition, 
subtraction and bit shifting, all of which are very cheap operations in standard computer 
architectures. It is one of the earliest algorithms developed in the field of computer graphics. 
A minor extension to the original algorithm also deals with drawing circles.


Interesting points:
*******************

The function that drow line is based on the Bresenham's line algorithm and is highly 
optimized to be able to draw lines very quickly. There is no floating point 
arithmetic nor multiplications and divisions involved. Only addition, 
subtraction and bit shifting are used.

sourse of code: 

http://www.codekeep.net/snippets/e39b2d9e-0843-4405-8e31-44e212ca1c45.aspx


Known bugs:
***********












	