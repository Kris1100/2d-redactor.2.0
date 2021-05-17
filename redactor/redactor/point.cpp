#include "point.h"

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

point point::centerize()
{
	double x, y;
	x = round(_x + constants::width / 2);
	y = round(_y + constants::height / 2);
	point p(x, y);
	return p;
}

void point::draw()
{
	int R_ = 230, G_ = 168, B_ = 215;
	point p(_x, _y);
	glColor3ub(R_, G_, B_);
	int N = 360;
	int R = 3;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 1; i <= N; i++)
	{
		glVertex2f(p.centerize().get_x() + R * cos(2 * 3.14 / N * i), 
				   p.centerize().get_y() + R * sin(2 * 3.14 / N * i));
	}
	glEnd();
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

point& point::operator=(const point& p) 
{
	if (this == &p) 
		return *this;
	_x = p.get_x();
	_y = p.get_y();
	return *this;
}