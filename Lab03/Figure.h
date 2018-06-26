#pragma once
class Figure
{
public:
	void move(double dx, double dy)
	{
		x = x + dx;
		y = y + dy;
	}
protected:
	double x, y, k;
	double r, g, b;
};