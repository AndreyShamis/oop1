#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <cmath>
#include "Poly.h"
#include "Vertex.h"
#include "macros.h"



using namespace std;

#define GRAPH_LENGTH 500
#define MAX_INPUT 100

#define	BORDER_AX 0.02	//	border proportion
#define GRAPH_EDGE 1.1  //	edge of the graph line

double graphX[GRAPH_LENGTH],graphY[GRAPH_LENGTH];
double X[MAX_INPUT],Y[MAX_INPUT];
int numPoints;
double maxX,maxY,minX,minY;
//==============================	functions =================================
double findMinX();
double findMaxX();
void updateGlobals(const Poly &lPoly);
bool checkDouble(const char &chr);
int fillArrOfPoints(const int &maxInput,const bool &pointType);
void readDataFromUser();


void display(void)
{
        //  clear all pixels  
    glClear (GL_COLOR_BUFFER_BIT);
        
        glColor3f (0.0, 0.0, 0.0);
        //drawing the x axis
        double axisX = -minX/(maxX-minX);
        glBegin(GL_LINES);
        glVertex3f (axisX,1.0, 0.0);
        glVertex3f (axisX,0.0, 0.0);
        glEnd();
        //drawing the y axis
        double axisY = -minY/(maxY-minY);               
        glBegin(GL_LINES);
        glVertex3f (1.0,axisY, 0.0);
        glVertex3f (0.0,axisY, 0.0);
        glEnd();
        
        //drawing the graph itself
        double Yrange  = maxY-minY;
        double Xrange  = maxX-minX;
        glColor3f (1.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP); 
        for(int i=0;i<GRAPH_LENGTH;i++){
                double x=(graphX[i]-minX)/Xrange;
                double y = (graphY[i]-minY)/Yrange;
                glVertex3f (x,y, 0.0);
        }
        glEnd();
        
        //drawing the interpolation points
        glColor3f (0.0, 0.0, 0.0);
        glPointSize(5.0);
        glBegin(GL_POINTS);
        for(int i=0;i<numPoints;i++){
                double x=(X[i]-minX)/Xrange;
                double y = (Y[i]-minY)/Yrange;
                glVertex3f (x,y, 0.0);
        }
        glEnd();

        //drawing the interpolation points coordinates
        std::ostringstream strs;
        std::string str;
        for(int i=0;i<numPoints;i++){           
                strs << "(" <<setprecision(5) 
                        << X[i]  << "," << setprecision(5) 
                        << Y[i]  << ")";
                str = strs.str();
                glRasterPos2f((X[i]-minX)/Xrange,(Y[i]-minY)/Yrange);
                int len = (int)str.length();
                for(int j=0;j<len;j++){
                        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10 , str[j]);
                }
                strs.str("");
        }

    //start processing buffered OpenGL routines now 
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 0.0);
        
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "graph"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */

// A function that update globals that will bueld the plot.
//=============================================================================
// Input: polynom obj.
void updateGlobals(const Poly &lPoly)
{

	double start_maxX, start_minX;	//	absolute input nim max
	double start = 0;			//	start position of graph
	double center = 0;			//	center of the graph
	double step = 0;				//	step proportion

	start_maxX = findMaxX();		//	get max X[]
	start_minX = findMinX();		//	get min X[]
									//	math center of the polynom graph
	center	= start_minX + (start_maxX - start_minX) * GRAPH_EDGE / 2;
									//	math step proportion
	step	= abs(start_maxX - start_minX) * GRAPH_EDGE;
	step = step  / GRAPH_LENGTH;
									//	math start position
	start = (center - step * ((GRAPH_LENGTH) * GRAPH_EDGE / 2)); 

	for(int index =0; index < GRAPH_LENGTH; index++)	// Loop though x points.
	{
		// Difine curent graph point, includ right proportion to 500 points.
		graphX[index] = step * (index) + start;	
		graphY[index] = lPoly(graphX[index]);

		// Difine grahp limits.
		if(index == 0)
		{
			minX = maxX = graphX[index];
			minY = maxY = graphY[index];
		}

		minX = min(minX, graphX[index]);
		maxX = max(maxX, graphX[index]);

		minY = min(minY, graphY[index]);
		maxY = max(maxY, graphY[index]);

	}	
	//	set spcae on the graph use border proportion for x
	double border_x = abs(maxX - minX) * BORDER_AX;
	minX -= border_x;
	maxX += border_x;

	//	set spcae on the graph use border proportion for y
	double border_y = abs(maxY - minY) * BORDER_AX;
	minY -= border_y;
	maxY += border_y;

}

// A function that chek char if it cintein number - double type. 
//=============================================================================
// Input: char from STDIN.
bool checkDouble(const char &chr)
{
	if(chr == ' ')	// If charecter is spase - chek recursive next charecter.
	{
		char chr2;
		bool result;
		chr2 = cin.get(); 
		result = checkDouble(chr2);
		cin.putback(chr2);
		return result;
	}
	// If charecter is not riprisent nomber Double type - return false.
	else if(chr!='-' && !isdigit(chr))

		return false;

	return true;		// Otherwise.
}

// A function that find max x point that user guive.
//=============================================================================
// Return max X point.
double findMaxX()
{
	double max_value;					// Difine max x value..
	for(int i =0; i < numPoints; i++)	// Loop thrigh all points x of user.
	{
		if(i == 0)
			max_value = X[i];

		// Max value x wqual to maximum of present max value and curent max v.
		max_value = max(max_value,X[i]);
	}
	return(max_value);
}

// A function that find min x point that user guive.
//=============================================================================
double findMinX()
{
	double min_value;			//	value be returned

	for(int i =0;i<numPoints;i++)
	{
		if(i == 0)				//	if min_value empty
			min_value = X[i];
								//	set minimal
		min_value = min(min_value,X[i]);
	}
	return(min_value);			//	return
}

// A function that fill arr (global) of points from user. 
//=============================================================================
int fillArrOfPoints(const int &maxInput,const bool &pointType)
{	
	char	chr;	// Difine charecter.
	int		numOfPoints		=	0;	// Difine nimber of points.

	// Get input till the max input of points.
	for(int index = 0; index < maxInput; index++)
	{
		chr = cin.get();

		if(!checkDouble(chr)) // If not double number - leav the loop.
			break;

		cin.putback(chr);

		// Get point : x and y
		if(pointType)
			cin >> X[index];
		else
			cin >> Y[index];
		
		numOfPoints++; 

	}
	return(numOfPoints);	//	return how many points was geted
}

// A function that read data from user.
//=============================================================================
void readDataFromUser()
{
	numPoints = 0; //reset number of points from user.

	// Get input untill the input is corect.
	while(true)
	{
		cout << "\t### Please enter X values for interpulation\n"  
			 << "\t### (Each value separated with space)\n\n"
			 << "\t### For example: x1 x2 x3 x4 'Enter'\n\n";

		// get  x point from user and difine number of points that user set.
		numPoints = fillArrOfPoints(MAX_INPUT, true);

		cout << "\t### Please enter Y values for interpulation\n"  
			 << "\t### (Each value separated with space)\n\n"
			 << "\t### For example: y1 y2 y3 y4 'Enter'\n\n"
			 << "\t### (REMEBER! Number of Y points must be equal\n" 
			 << "\t### to the number of X points)\n\n";

		// Chek if there back=slash in the STDIN - if there is remove it.
		char chr = cin.get();
		if(checkDouble(chr))
		{
			cin.putback(chr);
		}

		// If num of point equal to zero notify the user!
		if(numPoints == 0)
		{	
			cout << "\t###	!!!WRONG ENTER!!! ###\n" 
				 << "\t###  U did not enter any values!\n\n";
			continue;
		}
		
		// get  y point from user.
		int numberOfY = fillArrOfPoints(numPoints, false);

		// Chek if number of points y equal to the number of point x.  
		if(numberOfY < numPoints) // if not equal notify user and loop again.
		{
			cout << "\t###	!!!WRONG ENTER!!! ###\n"
				 << "\t### (Number of Y points not equal to the number of X "
				 << "points)"
				 << "\n\n";
		}
		else		// If equal exit loop.
			break;
	}
	
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Graph");
    init ();



//                      Polynom graph activation.				
//=============================================================================

	// read interpulation points from user.	
	readDataFromUser();	

	// Create Polynom through lagrange constractor.
	Poly lagrang2 = Poly(X,Y,numPoints);	
	
	// Print Polynom.
	cout << "\n\t### Polynom: " << lagrang2 << "\n";
	updateGlobals(lagrang2);

	// Print instractions for Exit program.
	cout << "\t### for exit click right button on the left top corner of "
		 << "glut\n"
		 << "\t### window and choose close option\n" 
		 << "\t### or simply clik on RED X on the rigt corner of glut "
		 << "window\n";
	
//=============================================================================

	glutDisplayFunc(display); 
	glutMainLoop();

        return 0;  
}
