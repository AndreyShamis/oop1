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

#define eX 20
#define waY 30

#define GRAPH_LENGTH 10
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

// A function that update globals that will bueld the plot.
//=============================================================================
// Input: polynom obj.
void updateGlobals(const Poly &lPoly)
{
	// 
	for(int index = 0 ;index < GRAPH_LENGTH; index++)
	{
		graphX[index] = (index - (GRAPH_LENGTH/2));
		graphY[index] = lPoly(index - (GRAPH_LENGTH/2));

		minX = min(minX,graphX[index]);
		maxX = max(maxX,graphX[index]);

		minY = min(minY,graphY[index]);
		maxY = max(maxY,graphY[index]);

	}	

		//cout << minX <<"minX " << maxX <<"maxX " << minY <<"minY " << maxY << "maxY\n";

}
// 
bool checkDouble(const char &chr)
{
	if(chr == ' ')
	{
		char chr2;
		bool result;
		chr2 = cin.get(); 
		result = checkDouble(chr2);
		cin.putback(chr2);
		return result;
	}
	else if(chr!='-' && !isdigit(chr))

		return false;

	return true;
}

int fillArrOfPoints(int maxInput, int pointType)
{	
	char chr;
	int numOfPoints = 0;
	for(int index = 0; index < maxInput; index++)
	{
		chr = cin.get();

		if(!checkDouble(chr))
		{
			break;
		} 

		cin.putback(chr);

		if(pointType == eX)
		{
			cin >> X[index];
		}

		else
		{
			cin >> Y[index];
		}

		numOfPoints++; 
		
	}
	return(numOfPoints);
}

void readDataFromUser()
{
	numPoints = 0;

	do
	{
		cout << "Please enter X values for interpulation" << "\n"  
			 << "(Each value separated with space)" << "\n\n"
			 << "For example: x1 x2 x3 x4 'Enter'" << "\n\n";

		numPoints = fillArrOfPoints(MAX_INPUT, eX);

		cout << "Please enter Y values for interpulation" << "\n"  
			 << "(Each value separated with space)" << "\n\n"
			 << "For example: y1 y2 y3 y4 'Enter'" << "\n\n"
			 << "(REMEBER! Number of Y points must be equal to the number of X points)" << "\n\n";

		char chr = cin.get();
		if(checkDouble(chr))
		{
			cin.putback(chr);
		}


		if(numPoints == 0)
		{	
			cout << "!!!WRONG ENTER!!!" << "\n" 
				 << "U did not enter any values!" << "\n\n";
		}
		else if(fillArrOfPoints(numPoints, waY) != numPoints)
		{
			cout << "!!!WRONG ENTER!!!" << "\n"
				 << "(Number of Y points did not equal to the number of X points)"
				 << "\n\n";
		}

		else

			break;
	}
	while(true);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Graph");
    init ();

        
        double coeffs[2] = {2,3};
        Poly obj1= Poly(coeffs,2);

        double coeffs2[2] = {2,3};
        Poly obj2= Poly(coeffs2,2);



cout << "______MathResult_______" << endl;

cout << "obj1 = "  << obj1 << endl;
cout << "obj2 = "  << obj2 << endl << endl;

cout << "Plus + :risult=obj1+obj2 " << endl;
        Poly obj3 = obj1 + obj2;
        cout << "result= " << obj3 << endl << endl;

cout << "Plus += :obj1+=obj2" << endl;
        obj1 += obj2;
        cout << "obj1= " << obj1 << endl << endl;


cout << "obj1 = "  << obj1 << endl;
cout << "obj2 = "  << obj2 << endl << endl;

cout << "Mul * :risult=obj1*obj2" << endl;
        obj3 = obj1 * obj2;
        cout << "result= " << obj3 << endl << endl;

cout << "Mul *= :obj1*=obj2" << endl;
        obj1 *= obj2;
        cout << "obj1= " << obj1 << endl << endl;


cout << "__________Value Test__________"  << endl;
cout << "obj1 = "  << obj1 << endl;
cout << "obj2 = "  << obj2 << endl << endl;


cout << "value Test f(x)=obj2" << endl;
        cout << obj2(-5) << endl << endl;;

cout << "__________Comper Test__________"  << endl;
cout << "obj1 = "  << obj1 << endl;
cout << "obj2 = "  << obj2 << endl << endl;

cout << "Comper (obj1==obj2)" << endl;
        if(obj1 == obj2)
        
                cout << "true" << endl << endl;
        else
                cout << "false" << endl << endl;

cout << "Comper (obj1!=obj2)" << endl;
        if(obj1 != obj2)
        
                cout << "true" << endl << endl;
        else
                cout << "false" << endl << endl;




        //double X1[11] = {-2,-1,0,1,2,3,4,0,0,0,0};
        //double Y1[11] = {47,22,9,2,-5,-18,-43,0,0,0,0};

        //Poly lagrang = Poly(X1,Y1,11);


		//cout << "__________Lagrange Test__________"  << endl;
		//cout	<< "input: " << "[X]={2,3,4,5,6,7,8,9}, [Y]={3,2.75,5,9.75,17,6,8,3}" 
		//		<<endl << endl;
        //cout << "result= " << lagrang << endl << endl; 

		
		readDataFromUser();
		Poly lagrang2 = Poly(X,Y,numPoints);
		cout << lagrang2 << "\n";
		updateGlobals(lagrang2);

		cout << "for exit click right button on the left top corner of glut"
			 << "\n" << " window and choose close option" << "\n" 
			 << "or simply clik on RED X on the rigt corner of glut window" 
			 << "\n";
			    

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
        updateGlobals(lPoly); --update glut globals for the graph
        *******************************/
        

        glutDisplayFunc(display); 
		glutMainLoop();
		//glCloseFunc();
    
        return 0;  
}
