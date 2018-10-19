//Tactical_Hacker

#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
using namespace std;


float shift = 0; // a variable used to move the boat right and left

void init(void)
{ /* here I prepare the window for displaying on it */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 100, 0.0, 50);
}
void drawing_moving_boats() {
	// we want to draw moving boat

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 18);
	glVertex2f(150, 18);
	glVertex2f(150, 0);

	glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(45 + shift, 20);
	glVertex2f(5 + shift, 20);
	glVertex2f(15 + shift, 10);
	glVertex2f(35 + shift, 10);

	glEnd();



	glColor3f(0.160, 0.658, 0.203);
	glBegin(GL_POLYGON);
	glVertex2f(25 + shift, 30);
	glVertex2f(25 + shift, 25);
	glVertex2f(17.943 + shift, 25.019);

	glEnd();


	// fourth regular shape is octagon 
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(25 + shift, 25.0);
	glVertex2f(25 + shift, 20);
	glVertex2f(23 + shift, 20);
	glVertex2f(23 + shift, 25);

	glEnd();



	glutSwapBuffers();



} /* function to make the user able to deal with the system */
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		shift--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		shift++;
		glutPostRedisplay();
		break;


	}



}


void main(int argc, char** argv)
{
	cout << " please move the boat with left and right arrows" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 600); //sets the initial window size
	glutCreateWindow(" Moving Boat"); // creates the window with name line
	init();
	glutDisplayFunc(drawing_moving_boats);
	glutSpecialFunc(key);
	glutMainLoop(); // enters the GLUT event processing loop
}