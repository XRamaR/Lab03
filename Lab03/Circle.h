#pragma once
#include <GL/freeglut.h>
#include "Figure.h"
#include <math.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#define M_PI acos(-1.0)

class Circle : public Figure
{
public:
	Circle(double _radius, double _x, double _y, double _r, double _g, double _b)
	{
		radius = _radius;
		x = _x;
		y = _y;
		r = _r;
		g = _g;
		b = _b;
	}
	void draw() 
	{
		srand(time(NULL));
		int i;
		int triangleAmount = 30; //# of triangles used to draw circle
								 //GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * M_PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3d(0.1*(rand() % 10), 0.1*(rand() % 10), 0.1*(rand() % 10));
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
	}  
private:
	double radius;
};