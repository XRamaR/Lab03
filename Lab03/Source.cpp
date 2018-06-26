#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "Circle.h"
#include "Prostokat.h"
#include "Rectangl.h"

std::vector<Rectangl> rectangles;
std::vector<Circle> circles;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		for (auto &p : rectangles)
			p.draw();
		for (auto &c : circles)
			c.draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void FunkcjaDoObslugiKlawiatury(unsigned char key, int mouse_x, int mouse_y)
{
	//std::cout << "Nacisnieto klawisz: " << key << ", a myszka znajduje sie w pozycji: " << mouse_x << ", " << mouse_y << "(w pikselach)" << std::endl;
	if (key == 'w')
	{
		rectangles[0].move(0, 0.1);
		circles[0].move(0, 0.1);
	}
	if (key == 's')
	{
		rectangles[0].move(0, -0.1);
		circles[0].move(0, -0.1);
	}
	if (key == 'a')
	{
		rectangles[0].move(-0.1, 0);
		circles[0].move(-0.1, 0);
	}
	if (key == 'd')
	{
		rectangles[0].move(0.1, 0);
		circles[0].move(0.1, 0);
	}
}


void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(FunkcjaDoObslugiKlawiatury);
}

int main(int argc, char *argv[])
{

	Rectangl p(0, 0, 0, 0, 0, 0, 0.5, 0);
	rectangles.push_back(p);
	/*Rectangl p(4, 0.5, 0, -1, 0, 1, 0.4, 0);
	rectangles.push_back(p);*/
	/*Rectangl p2(1.0, 1.0, 1.5, 1, 45, 0, 1, 0);
	rectangles.push_back(p2);
	Rectangl p3(1.0, 1.0, -1.5, 1, 45, 0, 1, 0);
	rectangles.push_back(p3);*/
	Circle c(1.0, 0.0, 1.0, 1, 0.6, 0.0);
	circles.push_back(c);
	
	// it's still possible to use console to print messages
	std::cout << "Hello openGL world!" << std::endl;

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}