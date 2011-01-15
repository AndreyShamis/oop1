#include "Grafic.h"
vector<Objects*> Grafic:: _objects;

Grafic::Grafic(void)
{
	//glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1020, 0, 600);
}

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
}

void Grafic::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}

void Grafic::removeObject(Objects &object)
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++ )
	{
		if((*it)->intelect)
			(*it)->VirtualPress(_objects);
		if( typeid(**it) == typeid(Bomb) )
		{
			delete *it;
			_objects.erase(it);
		}
	}
}