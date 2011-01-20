#include "gameController.h"
#include <glut.h>

//=============================================================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


	glutInitWindowSize (850,600); 
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Bomber Man- Andrey Shamis AND Ilia Gaysinsky");
	
	glClearColor(0.0, 0.0, 0.0, 0.0);    // Устанавливается синий фон
	
	gameController *Game = gameController::getInstance();
	

	glutMainLoop();
	return(0);
}