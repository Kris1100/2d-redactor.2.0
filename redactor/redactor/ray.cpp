#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
	else
		throw "Недостаточно информации о луче";
}

ray::ray(const ray& r) 
{
	_begin = r.get_begin();
	_p = r.get_p();
}

ifstream& operator>>(ifstream& in, ray& r)
{
	cout << "Введите координаты начала луча:" << endl;
	cin >> r._begin;
	cout << "Введите произвольную точку на луче:" << endl;
	cin >> r._p;
	if (r._begin == r._p)
		throw "Недостаточно информации о луче";
	return in;
}

ostream& operator<<(ostream& out, const ray& r)
{
	cout << "Точка начала луча: " << r._begin << endl;
	cout << "Произвольная точка на луче: " << r._p << endl;
	return out;
}

void ray::draw() 
{
	glLineWidth(2);
	glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(_begin.centerize().get_x(), _begin.centerize().get_y());
	    glColor3ub(238, 130, 238);
	    glVertex2f(_p.centerize().get_x(), _p.centerize().get_y());
	glEnd();
}