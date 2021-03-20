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
		cout << "в 1 четверти"<<endl;
	if (_x < 0 && _y > 0)
		cout << "в 2 четверти"<<endl;
	if (_x < 0 && _y < 0)
		cout << "в 3 четверти"<<endl;
	if (_x > 0 && _y < 0)
		cout << "в 4 четверти"<<endl;
	if (_x == 0 && _y!=0)
		cout << "на оси Oy"<<endl;
	if (_y == 0 && _x != 0)
		cout << "на оси Ox"<<endl;
	if (_y == 0 && _x == 0)
		cout << "в начале координат"<<endl;
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
		cout << "Данная точка принадлежит биссектрисе координатной плоскости";
	else
		cout << "Данная точка не принадлежит биссектрисе координатной плоскости";
}
