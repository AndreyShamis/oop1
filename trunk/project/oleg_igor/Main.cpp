
#include "macros.h"
#include "Game.h"

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


//	glutInitWindowSize (250,250); 
//	glutInitWindowPosition (100,100);
//	glutCreateWindow (argv[0]);

	Game game;
	game.play();

	glutMainLoop();

	return 0;
}
