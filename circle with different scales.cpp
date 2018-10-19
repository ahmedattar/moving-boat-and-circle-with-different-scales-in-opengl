#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <math.h>
#include <iostream>
using namespace std;
int factor = 50; // it is a factor ( variable ) to control the scale of the circle 
void init(void)
{ /* here I prepare the window for displaying on it */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500, 0.0, 500);
}
void display_circle() {
	float theta; // theta variable to contain the value of the angle 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 1);
	/* it is simple way to draw the circle by bassing on all of 360 points of the circle 
	and I know their coordinates by the next simple equations*/
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = (i*3.142) / 180;
		glVertex2f(250+2*factor * cos(theta), 250+2 *factor* sin(theta));

	}
	glEnd();
	glFlush();
}
/* function to make the user able to deal with the system */
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_DOWN:
		factor--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		factor++;
		glutPostRedisplay();
		break;
	}

	};

void main(int argc, char** argv)
{
	cout << " please rescale the circle with up and down arrows" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600); //sets the initial window size
	glutCreateWindow(" cicle"); // creates the window with name line
	init();
	glutDisplayFunc(display_circle);
	glutSpecialFunc(key);
	glutMainLoop(); // enters the GLUT event processing loop
}