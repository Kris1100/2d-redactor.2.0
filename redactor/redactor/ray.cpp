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
	/*line l(_begin, _p);
	line t = l.extend();
	point p2;
	double t1x = t.get_first().get_x();
	double t1y = t.get_first().get_y();
	double t2x = t.get_second().get_x();
	if (t1x == t2x)
	{
		if (t1y > _begin.get_y() && t1y > _p.get_y() ||
			t1y < _begin.get_y() && t1y < _p.get_y())
			p2 = t.get_first();
		else
			p2 = t.get_second();
	}
	else
	{
		if (t1x > _begin.get_x() && t1x > _p.get_x() ||
			t1x < _begin.get_x() && t1x < _p.get_x())
			p2 = t.get_first();
		else
			p2 = t.get_second();
	}*/
	glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(_begin.centerize().get_x(), _begin.centerize().get_y());
	    glColor3ub(238, 130, 238);
	    glVertex2f(_p.centerize().get_x()*100, _p.centerize().get_y()*100);
	glEnd();
}