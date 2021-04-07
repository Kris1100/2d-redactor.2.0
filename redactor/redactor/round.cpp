#include "round.h"
const double PI = 3.141592653589793238463;

my_round::my_round(double x, double y, double r)
{
	_p = point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const my_round& c)
{
	out << "Координаты центра (" << c._p.get_x() << ", "
		<< c._p.get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, my_round& c)
{
	double x, y, r;
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	c._p =  point(x, y);
	c.set_r(r);
	return in;
}

double my_round::get_square_of_segment(double a) const 
{
	return ((a / 2) * get_r() * get_r());
}

bool round::is_inside(const point& p) const // new func - check if works
{
	double x_cntr = _p.get_x();
	double y_cntr = _p.get_y();
	double x = p.get_x();
	double y = p.get_y();
	circle w(x_cntr, y_cntr, _r);
	if (p.is_element(w))
		return false;
	if ((x_cntr - x) * (x_cntr - x) + (y_cntr - y) * (y_cntr - y) < _r * _r)
		return true;
	return false;
}