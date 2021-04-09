#include "circle.h"

circle::circle(double x, double y, double r) 
{
	_centr =  point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const circle& c) 
{
	out << "Координаты центра (" << c._centr.get_x() << ", "
		<< c._centr.get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, circle& c) 
{
	double x, y, r;
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	c._centr =  point(x, y);
	c.set_r(r);
	return in;
}

int circle::quarter() const 
{
	if ((_centr.get_x() - _r) > 0 && (_centr.get_y() - _r) > 0)
		return 1;
	else if ((_centr.get_x() + _r) < 0 && (_centr.get_y() - _r) > 0)
		return 2;
	else if ((_centr.get_x() + _r) < 0 && (_centr.get_y() + _r) < 0)
		return 3;
	else if ((_centr.get_x() - _r) > 0 && (_centr.get_y() + _r) < 0)
		return 4;
	else return -1;
}


void circle::intersection() const 
{    //не читабельный код - испрваить, также как в предыдущей
	if (_r * _r - (_centr.get_x() * _centr.get_x()) > 0)
		cout << "Точка пересечения с осью x:(0, " << sqrt(_r * _r - (_centr.get_x() * _centr.get_x())) << ")  " << endl;
	else if (_r * _r - (_centr.get_y() * _centr.get_y()) > 0)
		cout << "Точка пересечения с осью y:(" << sqrt(_r * _r - (_centr.get_y() * _centr.get_y())) << " ,0) " << endl;
	else cout << "Нет пересечения с осями" << endl;
}

line circle::tangent(const point& p)const  //входные данные меняются? если нет, то конст
{
	double a = -2 * _centr.get_x()+p.get_x();
	double b = -2 * _centr.get_y()+p.get_y();
	double c = pow(_centr.get_x(), 2) + pow(_centr.get_y(), 2) - pow(_r, 2);
	return line(a, b, c);
}