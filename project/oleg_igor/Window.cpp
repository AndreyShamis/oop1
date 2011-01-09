

#include "Window.h"

vector<GameObject*> Window:: _vec_objs;
int Window::_height ;
int Window::_width ;

Window::Window(int height, int width, char* prog_name ) {

	_height = height ;
	_width = width ;

	glutInitWindowSize( _width, _height  ); 
	glutInitWindowPosition( DEFAULT_POS_X, DEFAULT_POS_Y );
	glutCreateWindow(prog_name);      //

	init() ;
};

void Window::addObj( GameObject *obj ) {
	_vec_objs.push_back( obj ) ;
};

// The display into the window
void Window::display() {

	// Clearing the buffer
	glClear(GL_COLOR_BUFFER_BIT) ;

	vector<GameObject*>::iterator it ;

	for( it = _vec_objs.begin() ; it < _vec_objs.end() ; it++ ) {	
		(*it)->draw();
	}

	// The buffer is ready for drawing
	glFlush() ;

	// Swap the buffers  
	glutSwapBuffers();
}

// OpenGL initializing values
void Window::init(void) {
	// Select a clear color
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, _width, 0, _height);
}