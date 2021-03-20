#include "point.h"

point::point(double x, double y)
{
	set_x(x);
	set_y(y);
}

double point::get_x()
{
	return _x;
}

void point::set_x(double x)
{
	_x = x;
}

double point::get_y()
{
	return _y;
}

void point::set_y(double y)
{
	_y = y;
}

void point::quarter()
{
	if (_x > 0 && _y > 0)
		cout << "� 1 ��������"<<endl;
	if (_x < 0 && _y > 0)
		cout << "� 2 ��������"<<endl;
	if (_x < 0 && _y < 0)
		cout << "� 3 ��������"<<endl;
	if (_x > 0 && _y < 0)
		cout << "� 4 ��������"<<endl;
	if (_x == 0 && _y!=0)
		cout << "�� ��� Oy"<<endl;
	if (_y == 0 && _x != 0)
		cout << "�� ��� Ox"<<endl;
	if (_y == 0 && _x == 0)
		cout << "� ������ ���������"<<endl;
}

double point::dist()
{
	double res;
	res = _x * _x + _y * _y;
	return sqrt(res);
}

void point::bisector()
{
	if (abs(_x) == abs(_y))
		cout << "������ ����� ����������� ����������� ������������ ���������";
	else
		cout << "������ ����� �� ����������� ����������� ������������ ���������";
}
