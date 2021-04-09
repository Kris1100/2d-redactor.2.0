#include "point.h"
//Откатились, девочки!!!!
point::point(double x, double y)
{
	set_x(x);
	set_y(y);
}

int point::quarter()
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
		f = false;
	return f;
}
bool operator==(const point& p1, const point& p2)
{
	if (p1._x == p2._x && p1._y == p2._y)
		return true;
	return false;
}

bool operator!=(const point& p1, const point& p2)
{
	if (p1._x != p2._x || p1._y != p2._y)
		return true;
	return false;
}

istream& operator>>(istream& in, point& p)
{
	cin >> p._x >> p._y;
	return in;
}

ostream& operator<<(ostream& out, const point& p)
{
	cout << p._x << " " << p._y;
	return out;
}