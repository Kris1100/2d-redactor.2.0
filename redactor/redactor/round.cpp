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
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	c._	p = new point(x, y);
	c.set_r(r);
	return in;
}

void circle::quarter() const {
	if ((_p->get_x() - _r) > 0 && (_p->get_y() - _r) > 0) cout << "Круг лежит в первой четверти" << endl;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() - _r) > 0) cout << "Круг лежит во второй четверти" << endl;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() + _r) < 0) cout << "Круг лежит в третьей четверти" << endl;
	else if ((_p->get_x() - _r) > 0 && (_p->get_y() + _r) < 0) cout << "Круг лежит в четвертой четверти" << endl;
	else cout << "Круг не лежит полностью ни в какой четверти" << endl;
}

double my_round::get_square() const
{
	return (2 * PI * get_r());
}

double my_round::get_square_of_segment(double a) const
{
	return ((a / 2) * get_r() * get_r());
}
	