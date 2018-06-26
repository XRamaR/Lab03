#pragma once
#include <GL/freeglut.h>
#include "Figure.h"
#include <math.h>

#define M_PI acos(-1.0)

class Circle : protected Figure
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
	void draw() {
		int i;
		int triangleAmount = 30; //# of triangles used to draw circle
								 //GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * M_PI;

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
	}
	void move(double dx, double dy) 
	{
		x = x + dx;
		y = y + dy;
	}
private:
	double radius;
};