#include "Triangle.h"

const double M_EPS = 0.000000001;

triangle::triangle()
{
	point* vert = new point[3];
	vertex = vert;
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
	if (ab.len() - bc.len() <= M_EPS && ab.len() - ac.len() <= M_EPS)
		/*почему не работает объ€вленна€ в общем заголовочнике через define константа?*/
		return true;
	return false;
}

bool triangle::is_isosceles() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() == bc.len() || ab.len() == ac.len() || ac.len() == bc.len())
		return true;
	return false;
}

bool triangle::is_right() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() * ab.len() + ac.len() * ac.len() - bc.len() * bc.len() <= M_EPS ||
		ab.len() * ab.len() + bc.len() * bc.len() - ac.len() * ac.len() <= M_EPS ||
		bc.len() * bc.len() + ac.len() * ac.len() - ab.len() * ab.len() <= M_EPS)
		return true;
	return false;
}

double triangle::radius_inside() const
{
	if (exists())
		return 2 * area() / perimetr();
	else
	{
		cout << "“реугольник с такими координатами не существует" << endl;
		return -1;
	}
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
	{
		cout << "“реугольник с такими координатами не существует" << endl;
		return -1;
	}
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

ifstream& operator>>(ifstream& in, triangle& abc)
{
	for (int i = 0; i < 3; i++)
		cin >> abc.vertex[i];
	return in;
}

segment triangle::middle_line(const segment& ab, const segment& bc)
{
	segment l(ab.middle(), bc.middle());
	return l;
}