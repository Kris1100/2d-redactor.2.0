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

ray::ray(const ray& r)
{
	_begin = r.get_begin();
	_p = r.get_p();
}

bool ray::is_element(const point& t)
{
	//���� ��������� � ������������ ������� ����
	if (t == _p || t == _begin)
		return true;
	//����������� �� ������, �� ������� ����� ���
	double x = t.get_x(), y = t.get_y();
	line l(_begin, _p);
	double a, b, c;
	l.coef(a, b, c);
	if (abs(a * x + b * y + c) >= constants::eps)
		return false;
	//����� �������� ���������, ��������� ����������, ��������������� ���������� �����
	double tmp_b = _begin.get_x();
	double tmp_p = _p.get_x();
	double  tmp_t = x;
	//������ � ������������ �����
	if (_begin.get_x() == _p.get_x())
	{
		tmp_b = _begin.get_y();
		tmp_p = _p.get_y();
		tmp_t = y;
	}
	//������� � ������ ������ � ������ ������/������
	//p������ ��������� ����� ����������, ����� �������� ���������
	int sign = 1;
	//���� ����� ��� ������
	if (tmp_b < tmp_p)
		sign = 1;
	//���� ���� ��� �����
	else
		sign = -1;
	if (tmp_t * sign > tmp_b)
		return true;
	return false;
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

void ray::draw()
{
	glLineWidth(2);
	line l(_begin, _p);
	point p1, p2;
	l.extend(p1, p2);
	ray r(_begin.centerize(), _p.centerize());
	if (r.is_element(p2))
		p1 = p2;
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(_begin.centerize().get_x(), _begin.centerize().get_y());
	glColor3ub(238, 130, 238);
	glVertex2f(p1.get_x(), p1.get_y());
	glEnd();
}