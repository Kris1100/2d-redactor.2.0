#include "point.h"

point::point(double x, double y)
{
	set_x(x);
	set_y(y);
}

double point::get_x() const
{
	return _x;
}

void point::set_x(double x)
{
	_x = x;
}

double point::get_y() const
{
	return _y;
}

void point::set_y(double y)
{
	_y = y;
}

double point::quarter()
{
	int res;
	if (_x >= 0 && _y >= 0)
		res=1;
	if (_x <= 0 && _y >= 0)
		res=2;
	if (_x <= 0 && _y <= 0)
		res=3;
	if (_x >= 0 && _y <= 0)
		res=4;
	if (_x == 0 && _y == 0)
		res = 0;
	return res;
}

double point::dist()
{
	double res;
	res = _x * _x + _y * _y;
	return sqrt(res);
}

bool point::bisector()
{
	bool f;
	if (abs(_x) == abs(_y)) 
		f = true;
	else
		f=false;
	return f;
}
