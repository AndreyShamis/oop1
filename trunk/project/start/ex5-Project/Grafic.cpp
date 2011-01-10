#include "Grafic.h"
vector<Objects*> Grafic:: _objects;

Grafic::Grafic(void)
{
}

void Grafic::Display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	vector<Objects*>::iterator it;

	for(it=_objects.begin();it<_objects.end();it++)
		(*it)->Draw();

	glFlush() ;
	glutSwapBuffers();
}
