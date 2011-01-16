#include "Grafic.h"
vector<Objects*> Grafic:: _objects;

//=============================================================================
Grafic::Grafic()
{
	glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(0, 1020, 0, 600);
}

//=============================================================================
void Grafic::Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT ); 
	vector<Objects*>::iterator it;
	
	for(it=_objects.begin();it <_objects.end();it++)
	{

		if(*it == NULL)
		{
			std::cout << "Have null object in memory\n";
		}
		else
		{
			if((*it)->_enabled)
				(*it)->Draw();
		}
	}
		

	glFlush() ; 
	glutSwapBuffers();
	//removeObjects();
}

//=============================================================================
void Grafic::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}
