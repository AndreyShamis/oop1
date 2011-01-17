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
		if((*it)->isEnabled())
			(*it)->Draw();


	}

	glFlush() ; 
	glutSwapBuffers();

}

//=============================================================================
void Grafic::addObject(Objects *newObject)
{
	_objects.push_back(newObject);
}


void Grafic::clearObject(Objects *obj)
{
	vector<Objects*>::iterator it ;

	for( it =  _objects.begin() ; it < _objects.end() ; it++) 
	{
		if( (*it) == obj )
		{
			it = _objects.erase( it ) ;
			break ;
		}
	}

}