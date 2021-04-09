#include "round.h"

my_round::my_round(double x, double y, double r)
{
	_centr = point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const my_round& c)
{
	out << "Координаты центра (" << c._centr.get_x() << ", "
		<< c._centr.get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, my_round& c)
{
	double x, y, r;
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	c._centr =  point(x, y);
	c.set_r(r);
	return in;
}

double my_round::get_square_of_segment(double a) const 
{
	return ((a / 2) * get_r() * get_r());
}

bool my_round::is_inside(const point& p)const{ 
	double x_cntr = _centr.get_x();
	double y_cntr = _centr.get_y();
	double x = p.get_x();
	double y = p.get_y();
	
	//
	circle w(x_cntr, y_cntr, _r);
	if (p.is_elem_circle(w))
		return false;
	if ((x_cntr - x) * (x_cntr - x) + (y_cntr - y) * (y_cntr - y) < _r * _r)
		return true;
	return false;
}