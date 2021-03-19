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
	if (_x > 0 && _y > 0)cout << "1";
	if (_x < 0 && _y > 0)cout << "2";
	if (_x < 0 && _y < 0)cout << "3";
	if (_x > 0 && _y < 0)cout << "4";//ƒобавить ситуацию с осью
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
		cout << "ƒанна€ точка принадлежит биссектрисе координатной плоскости";
	else 
		cout << "ƒанна€ точка не принадлежит биссектрисе координатной плоскости";
}
