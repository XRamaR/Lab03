#pragma once
#define NDEBUG
#include <GL/freeglut.h>
#include "Figure.h"

class Rectangl : public Figure
{
public:
	Rectangl(double _w, double _h, double _x, double _y, double _k, double _r, double _g, double _b) {
		w = _w;
		h = _h;
		x = _x;
		y = _y;
		k = _k;
		r = _r;
		g = _g;
		b = _b;
	}

	void draw() {
		glPushMatrix();

		glTranslated(x, y, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(k, 0.0, 0.0, 1.0);

		glColor3d(r, g, b);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-w / 2, h / 2, 0);
			glVertex3d(w / 2, h / 2, 0);
			glVertex3d(w / 2, -h / 2, 0);
			glVertex3d(-w / 2, -h / 2, 0);
		}
		glEnd();
		glPopMatrix();
	}
private:
	double w, h;
};