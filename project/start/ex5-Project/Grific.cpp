#include "Grific.h"

Grific::Grific(void)
{
}

static void Grific::Display()
{

	glClear(GL_COLOR_BUFFER_BIT) ;

	vector<Objects*>::iterator it ;

	for( it = _objects.begin() ; it < _vec_objs.end() ; it++ ) {	
		(*it)->draw();
	}

	// The buffer is ready for drawing
	glFlush() ;

	// Swap the buffers  
	glutSwapBuffers();
}
