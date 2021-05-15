#include "ray.h"
ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
	else
		throw "������������ ���������� � ����";
}

ray::ray(const ray& r) {
	_begin = r.get_begin();
	_p = r.get_p();
}

ifstream& operator>>(ifstream& in, ray& r)
{
	cout << "������� ���������� ������ ����:" << endl;
	cin >> r._begin;
	cout << "������� ������������ ����� �� ����:" << endl;
	cin >> r._p;
	if (r._begin == r._p)
		throw "������������ ���������� � ����";
	return in;
}

ostream& operator<<(ostream& out, const ray& r)
{
	cout << "����� ������ ����: " << r._begin << endl;
	cout << "������������ ����� �� ����: " << r._p << endl;
	return out;
}

void ray::draw() {
	glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(_begin.get_x(), _begin.get_y());
	    glColor3ub(238, 130, 238);
	    glVertex2f(constants::width + _p.get_x(), constants::height + _p.get_y());
	glEnd();

	glFinish();
}