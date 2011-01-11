

#include "gameController.h"
#include <glut.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutInitWindowSize (620,620); 
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Ko ko Jamba");
	
	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);    // Устанавливается синий фон
	
	gameController Game;
	

	glutMainLoop();
	return(0);
}