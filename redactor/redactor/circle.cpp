#include "circle.h"

circle::circle(double x, double y, double r) {
	point* p;
	p->set_x(x);
	p->set_y(y);
	set_center(p);
	set_r(r);
}
ostream& operator<<(ostream& out, const circle& c) {
	out << "Координаты центра (" << c._p.get_x << ", " << c._p.get_y << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}
istream& operator>>(istream& in, circle& c) {
	double x, y, r;
	in >> x >> y >> r;
	point* p;
	p->set_x(x);
	p->set_y(y);
	c.set_center(p);
	c.set_r(r);
	return in;
}
void circle::equation(double a, double b, double r) {
	point* p;
	p->set_x(a);
	p->set_y(b);
	set_center(p);
	set_r(r);
}

void circle::set_center(point* p) {
	_p = p;
}


double circle::get_r() const {
	return _r;
}

double circle::get_d() const {
	return _r * 2;
}
void circle::set_r(double r) {
	_r = r;
}

void circle::quarter() const {
	if ((_p.get_x() - _r) > 0 && (_p.get_y() - _r) > 0)cout << "1";
	if ((_p.get_x() + _r) < 0 && (_p.get_y() - _r) > 0)cout << "2";
	if ((_p.get_x() + _r) < 0 && (_p.get_y() + _r) < 0)cout << "3";
	if ((_p.get_x() - _r) > 0 && (_p.get_y() + _r) < 0)cout << "4";
}


void circle::intersection() const {
	if ((_r ^ 2 - _p.get_x ^ 2) > 0)cout << "(0, " << sqrt(_r ^ 2 - _p.get_x ^ 2) << ")  ";
	if ((_r ^ 2 - _p.get_y ^ 2) > 0)cout << "(" << sqrt(_r ^ 2 - _p.get_y ^ 2) << " ,0)  ";
}

double circle::length() const {
	return 2 * M_PI * _r;
}
