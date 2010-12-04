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

double graphX[GRAPH_LENGTH],graphY[GRAPH_LENGTH];
double X[MAX_INPUT],Y[MAX_INPUT];
int numPoints;
double maxX,maxY,minX,minY;



//std::ostream& operator<<(std::ostream& pout, const Poly &otherPoly);

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
void updateGlobals(const Poly &lPoly)
{
	for(int index = 0 ;index < GRAPH_LENGTH; index++)
	{
		graphX[index] = (index-249);
		graphY[index] = lPoly(index - 249);

		//cout << graphX[i] << "       "  << graphY[i] << endl; 

		minX = min(minX,graphX[index]);
		maxX = max(maxX,graphX[index]);

		minY = min(minY,graphY[index]);
		maxY = max(maxY,graphY[index]);

	}	
}

//bool readDataFromUser()
//{
//        double input;
//        int counter = 0;
//        bool FLAG = false;
//
//        maxX = counter;
//        maxY = counter*counter;
//        
//        for(counter =0;counter<MAX_INPUT;counter++);
//        {
//                //X[counter] = counter;
//                graphX[counter] = counter;
//                graphY[counter] = (counter*counter/2);
//                //Y[counter] = counter * counter;
//        }
//        
//        maxX = counter;
//        maxY = counter*counter;
//        
//        while(FLAG)
//        {
//                cin >> input;
//                X[counter] = input;
//                counter++;
//        }
//
//        numPoints = counter;
//        return 0;
//}
bool checkDouble(const char &chr)
{
	if(chr!='-' && !isdigit(chr) && chr!= ' ')
		return false;

	return true;
}
bool readDataFromUser()
{
	int index;
	char chr;

	numPoints = 0;
	for(index = 0; index < MAX_INPUT; index++)
	{
		chr = cin.get();

		if(!checkDouble(chr))
			break;

		cin.putback(chr);
		cin >> X[index];
		numPoints++; 
	}

	 for(index = 0; index < numPoints; index++)
	 {
		chr = cin.get();

		if(!checkDouble(chr))
			break;

		cin.putback(chr);
		cin >> Y[index];
	}

 for(index = 0; index < numPoints; index++)
 {
  cout << X[index] << " ";
 }
 cout << "\n";
 for(index = 0; index < numPoints; index++)
 {
  cout << Y[index] << " " ;
 }

	return 1;
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

        if(readDataFromUser())
		{
			Poly lagrang2 = Poly(X,Y,numPoints);
			updateGlobals(lagrang2);
		}
		else
			cout << "Can not get data\n";


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
    
        return 0;  
}
