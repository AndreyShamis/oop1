

#include "gameController.h"
#include <glut.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutInitWindowSize (580,580); 
	glutInitWindowPosition (0,0);
	glutCreateWindow (argv[0]);

	gameController Game;
	

	glutMainLoop();
	return(0);
}