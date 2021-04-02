#include "circle.h"
const double PI = 3.141592653589793238463; //в общем взаголовочнике нужно определить

circle::circle(double x, double y, double r) 
{
	_p = new point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const circle& c) 
{
	out << "Координаты центра (" << c._p->get_x() << ", " 
		<< c._p->get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, circle& c) 
{
	double x, y, r;
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	c._p = new point(x, y);
	c.set_r(r);
	return in;
}


int circle::quarter() const //может, стоит переделать функцию так, чтобы она возвращала значение, а не печатала его
                             //тогда она будет полезнее
{
	if ((_p->get_x() - _r) > 0 && (_p->get_y() - _r) > 0) return 1;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() - _r) > 0) return 2;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() + _r) < 0) return 3;
	else if ((_p->get_x() - _r) > 0 && (_p->get_y() + _r) < 0) return 4;
	else return -1;
}


void circle::intersection() const 
{    //не читабельный код - испрваить, также как в предыдущей
	if (_r * _r - (_p->get_x() * _p->get_x()) > 0)
		cout << "Точка пересечения с осью x:(0, " << sqrt(_r * _r - (_p->get_x() * _p->get_x())) << ")  " << endl;
	else if (_r * _r - (_p->get_y() * _p->get_y()) > 0) 
		cout << "Точка пересечения с осью y:(" << sqrt(_r * _r - (_p->get_y() * _p->get_y())) << " ,0) " << endl;
	else cout << "Нет пересечения с осями" << endl;
}


line circle::tangent(point& p) //входные данные меняются? если нет, то конст
{
	double a = -2 * _p->get_x()+p.get_x();
	double b = -2 * _p->get_y()+p.get_y();
	double c = pow(_p->get_x(), 2) + pow(_p->get_y(), 2) - pow(_r, 2);
	return line(a, b, c);
}