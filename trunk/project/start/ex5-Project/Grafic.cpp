#include "Grafic.h"
vector<Objects*> Grafic:: _objectsDrow;

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
	vector<Objects*>::const_iterator it;
	
	for(it=_objectsDrow.begin();it <_objectsDrow.end();it++)
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
	_objectsDrow.push_back(newObject);
}


void Grafic::clearObject(Objects *obj)
{

	const int _vec_size = (int)_objectsDrow.size();
	for(int i=0;i<_vec_size;i++)
	{
		if(_objectsDrow[i] == obj )
		{
			_objectsDrow.erase(_objectsDrow.begin()+i);
			break;

		}
	}

}