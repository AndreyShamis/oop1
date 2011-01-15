#include "Grafic.h"
vector<Objects*> Grafic:: _objects;

//=============================================================================
Grafic::Grafic(void)
{
	//glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1020, 0, 600);
}

//=============================================================================
void Grafic::Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	vector<Objects*>::iterator it;
	
	for(it=_objects.begin();it<_objects.end();it++)
	{
		if((*it)->_enabled)
			(*it)->Draw();

	}
		

	glFlush() ;
	glutSwapBuffers();
	removeObjects();
}

//=============================================================================
void Grafic::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}

//=============================================================================
void Grafic::removeObjects()
{
	vector<Objects*>::iterator it ;

	int i=0;

	for( it =  _objects.begin() ; it != _objects.end() ; it++ )
	{
		i++;
		if((typeid(**it) == typeid(Bomb)||typeid(**it) == typeid(Fire)) && (*it)->getTimer() <0 && !(*it)->_enabled)
		{
			//_objects.erase(_objects.begin()+i);
			i--;
			
		}
	}
}
