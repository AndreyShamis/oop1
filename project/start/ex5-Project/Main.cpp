

#include "gameController.h"
#include <glut.h>

//=============================================================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


	glutInitWindowSize (1020,600); 
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Ko ko Jamba");
	
	glClearColor(0.0, 0.0, 0.0, 0.0);    // Устанавливается синий фон
	
	gameController *Game = gameController::getInstance();
	

	glutMainLoop();
	return(0);
}