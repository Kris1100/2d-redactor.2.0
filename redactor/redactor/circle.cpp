#include "circle.h"



circle::circle(double, double, double) const {
	set_center(x, y);
	set_r(r);
}


friend circle::ostream& operator<<(ostream&, const rational&) {
	out << << "Координаты центра (" << c._x << ", " << c._y << ")" << endl << "Радиус: " << c._z << endl;
	return out;
}
friend circle::istream& operator>>(istream&, rational&)const {
	double x, y, r;
	in >> x >> y >> r;
	p.set_center(x, y);
	p.set_r(r);
	return in;
}
void circle::equation(double, double, double) {
	set_center(a, b);
	set_r(r);
}

void circle::set_center(double, double) {
	_p.set_x(x);
	_p.set_y(y);
}

double circle::get_r() const {
	return _r;
}

double circle::get_d() const {
	return _r * 2;
}
void circle::set_r(double) {
	_r = r;
}

void circle::quarter() const {
	if ((_p.get_x() - _r) > 0 && (_p.get_y() - _r) > 0)cout << "1";
	if ((_p.get_x() + _r) < 0 && (_p.get_y() - _r) > 0)cout << "2";
	if ((_p.get_x() + _r) < 0 && (_p.get_y() + _r) < 0)cout << "3";
	if ((_p.get_x() - _r) > 0 && (_p.get_y() + _r) < 0)cout << "4";
}

double length() const {
	return 2 * pi * _r;
}
