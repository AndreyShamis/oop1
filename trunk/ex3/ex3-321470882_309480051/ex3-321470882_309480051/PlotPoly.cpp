#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include <cmath>
#include "Poly.h"
#include "Vertex.h"
#include "macros.h"



using namespace std;



#define GRAPH_LENGTH 500
#define MAX_INPUT 100

double graphX[GRAPH_LENGTH],graphY[GRAPH_LENGTH];
double X[MAX_INPUT],Y[MAX_INPUT];
int numPoints;
double maxX,maxY,minX,minY;





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
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Graph");
    init ();

	
	/***************************
	//here comes your code!!!!
	//you should fill X and Y with the interpolation points(from the user)
	//and numPoints should be the number of points you got from the user
	//there will be no more than MAX_INPUT points.
	//graphX and graphY should be filled with the 
	//x and y of the exactly GRAPH_LENGTH points you want the 
	//graph to go through. These points should be ordered according to the 
	//x coordinate ascending.
	//
	//Something like: (parameters not included...)
	//readDataFromUser(); --get the data from the user
	//Poly lPoly = Poly(); --create the polynom using lagrange ctor
	//updateGlobals(lPoly); --update glut globals for the graph
	*******************************/
	

	glutDisplayFunc(display); 
    glutMainLoop();
    
	return 0;  
}

