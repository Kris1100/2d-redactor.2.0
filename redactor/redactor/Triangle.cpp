#include "Triangle.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"

triangle::triangle()
{
	point* vert = new point[3];
	vertex = vert;
}

triangle::triangle(const point* vert)
{
	point* tmp_vert = new point[3];
	vertex = tmp_vert;
	vertex[0] = vert[0];
	vertex[1] = vert[1];
	vertex[2] = vert[2];
}

void triangle::set_vertex(const point& a, const point& b, const point& c)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
}

bool triangle::exists() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() + bc.len() < ac.len() || ab.len() + ac.len() < bc.len() ||
		ac.len() + bc.len() < ab.len())
		return false;
	return true;
}

bool triangle::is_equilateral() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (abs(ab.len() - bc.len()) <= constants::eps && 
		abs(ab.len() - ac.len()) <= constants::eps)
		return true;
	return false;
}

bool triangle::is_isosceles() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (abs(ab.len() - bc.len()) <= constants::eps ||
		abs(ab.len() - ac.len()) <= constants::eps ||
		abs(ac.len() - bc.len()) <= constants::eps)
		return true;
	return false;
}

bool triangle::is_right() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (abs(ab.len() * ab.len() + ac.len() * ac.len() - bc.len() * bc.len()) <= constants::eps ||
		abs(ab.len() * ab.len() + bc.len() * bc.len() - ac.len() * ac.len()) <= constants::eps ||
		abs(bc.len() * bc.len() + ac.len() * ac.len() - ab.len() * ab.len()) <= constants::eps)
		return true;
	return false;
}

double triangle::radius_inside() const
{
	if (exists())
		return 2 * area() / perimetr();
	else
		throw "Вырожденный случай";
}

double triangle::radius_outside() const
{
	if (exists())
	{
		double abc_square = area();
		segment ab(vertex[0], vertex[1]);
		segment bc(vertex[1], vertex[2]);
		segment ac(vertex[0], vertex[2]);
		return ab.len() * bc.len() * ac.len() / (4 * abc_square);
	}
	else
		throw "Вырожденный случай";
}

bool triangle::is_inside(const point& p) const
{
	double a, b, c;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		line l(vertex[i], vertex[(i + 1) % 3]);
		l.coef(a, b, c);
		point tmp = vertex[(i + 2) % 3];
		if (a * p.get_x() + b * p.get_y() + c < 0 && a * tmp.get_x() + b * tmp.get_y() + c < 0 ||
			a * p.get_x() + b * p.get_y() + c > 0 && a * tmp.get_x() + b * tmp.get_y() + c > 0)
		{
			count++;
		}
	}
	if (count == 3)
		return true;
	return false;
}

segment triangle::middle_line(const segment& ab, const segment& bc) const
{
	segment l(ab.middle(), bc.middle());
	return l;
}

segment triangle::median(const point& a, const segment& bc) const
{
	segment l(a, bc.middle());
	return l;
}

point* triangle::get_vertex() const
{
	point* vert = new point[3];
	vert[0] = vertex[0];
	vert[1] = vertex[1];
	vert[2] = vertex[2];
	return vert;
}

void triangle::draw() 
{
	glBegin(GL_TRIANGLES);
	     point* vert = vertex;
	     glColor3ub(255, 0, 0);
	     glVertex2f(vert[0].get_x(), vert[0].get_y());
	     glColor3ub(0, 255, 0);
	     glVertex2f(vert[1].get_x(), vert[1].get_y());
	     glColor3ub(0, 0, 255);
	     glVertex2f(vert[2].get_x(), vert[2].get_y());
	glEnd();

	glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(vert[0].get_x(), vert[0].get_y());
		glVertex2f(vert[1].get_x(), vert[1].get_y());
	glEnd();

	glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(vert[1].get_x(), vert[1].get_y());
		glVertex2f(vert[2].get_x(), vert[2].get_y());
	glEnd();

	glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(vert[2].get_x(), vert[2].get_y());
		glVertex2f(vert[0].get_x(), vert[0].get_y());
	glEnd();
}