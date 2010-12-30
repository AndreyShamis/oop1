/*
 * EX2:: GAME: BOMBER MAN.
 *
 * 
 * 
 * ============================================================================
 * Writen by: Andrey Shamis,  id: 321470882, login: andreysh
 * and:       Ilia Gaisinsky, id: 309480051, login: iliaga
 *      =======================================================================
 *     
*/

//                               Include section
//=============================================================================
#include <stdlib.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>

#include <glut.h>
#include "gameController.h"

//=============================================================================
void init()
{
      glClearColor(0.2f, 0.5f, 0.75f, 1.0f);    // ��������������� ����� ���
      //glClearDepth(1.0f);                       // ��������������� �������� ���
						//						// ���������� ������ ������� �� ���������
      //glEnable(GL_DEPTH_TEST);                  // ���������� ���� �������
      //glDepthFunc(GL_LEQUAL);                   // ��������������� ��������, ������������
      //                                          // � ���������� ��� �������������
      //                                          // ������ �������
 
      //glShadeModel(GL_SMOOTH);                  // ���������� ������� ���������
      //glEnable(GL_LINE_SMOOTH);                 // ���������� ����������� �����
      //glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);   // ���������� ����� ������������
      //                                          // ����� ����������� ��� �����
      //glEnable(GL_BLEND);                       // ���������� �������� ������, �����������
      //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//��� ������ ����������� � ��������
      //                                          // ������ ��������	
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);		//	clear all pixels

  glColor3f(1.1, 1.1, 1.1);		//	
  glLineWidth(1);

  glBegin(GL_POLYGON);
  	glVertex3f(0.25,0.25,0.0);  
	glVertex3f(0.75,0.25,0.0);
	glVertex3f(0.75,0.75,0.0);
	glVertex3f(0.25,0.75,0.0);
  glEnd();

  glFlush();					

}
//                                 Main section
//=============================================================================
int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(950,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Was yp???");

	init();

	glutDisplayFunc(display);
	glutMainLoop();


	// Criate object of the class game controler (class of the game).
	GameController game = GameController();
	
	// Open game menu. 
	game.Menu();
	return(EXIT_SUCCESS);
}

//=============================================================================