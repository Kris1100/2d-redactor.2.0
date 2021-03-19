#include "round.h"
const double PI = 3.141592653589793238463;

my_round::my_round(double x, double y, double r)
{
	_p = new point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const my_round& c)
{
	out << "Координаты центра (" << c._p->get_x() << ", "
		<< c._p->get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, my_round& c)
{
	double x, y, r;
	in >> x >> y >> r;
	my_round(x, y, r);
	return in;
}

void my_round::equation(double a, double b, double r)
{
	my_round(a, b, r);
}

double my_round::get_square() const
{
	return (2 * PI * get_r());
}

double my_round::get_r() const
{
	return _r;
}

double my_round::get_square_of_segment(double a) const
{
	return ((a / 2) * get_r() * get_r());
}

double my_round::get_d() const
{
	return _r * 2;
}

void my_round::set_r(double r)
{
	_r = r;
}

point my_round::get_p()
{
	return *_p;
}

void my_round::quarter() const
{
	if ((_p->get_x() - _r) > 0 && (_p->get_y() - _r) > 0)
		cout << "1";
	if ((_p->get_x() + _r) < 0 && (_p->get_y() - _r) > 0)
		cout << "2";
	if ((_p->get_x() + _r) < 0 && (_p->get_y() + _r) < 0)
		cout << "3";
	if ((_p->get_x() - _r) > 0 && (_p->get_y() + _r) < 0)
		cout << "4";
}

void my_round::intersection() const
{
	if (_r * _r - (_p->get_x() * _p->get_x()) > 0)
		cout << "(0, " << sqrt(_r * _r - (_p->get_x() * _p->get_x())) << ")  ";
	if (_r * _r - (_p->get_y() * _p->get_y()) > 0)
		cout << "(" << sqrt(_r * _r - (_p->get_y() * _p->get_y())) << " ,0)  ";
}

double my_round::length() const
{
	return (get_r() * PI * 2);
}
