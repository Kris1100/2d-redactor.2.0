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

/*void circle::equation(double a, double b, double r) 
{
	circle(a, b, r);
}
*/

double circle::get_r() const //можно перенести короткие функции в заголовочный файл
{
	return _r;
}

double circle::get_d() const
{
	return _r * 2;
}

void circle::set_r(double r)
{
	_r = r;
}

point circle::get_p()
{
	return *_p;
}


void circle::quarter() const //может, стоит переделать функцию так, чтобы она возвращала значение, а не печатала его
                             //тогда она будет полезнее
{
	if ((_p->get_x() - _r) > 0 && (_p->get_y() - _r) > 0) //было слишком много в одной строке
		//часть после уловия лучше переносить на следующую строчку
		cout << "Окружность лежит в первой четверти" << endl;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() - _r) > 0) 
		cout << "Окружность лежит во второй четверти" << endl;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() + _r) < 0) 
		cout << "Окружность лежит в третьей четверти" << endl;
	else if ((_p->get_x() - _r) > 0 && (_p->get_y() + _r) < 0) 
		cout << "Окружность лежит в четвертой четверти" << endl;
	else cout << "Окружность не лежит полностью ни в какой четверти" << endl;
}


void circle::intersection() const 
{    //не читабельный код - испрваить, также как в предыдущей
	if (_r * _r - (_p->get_x() * _p->get_x()) > 0) cout << "Точка пересечения с осью x:(0, " << sqrt(_r * _r - (_p->get_x() * _p->get_x())) << ")  " << endl;
	else if (_r * _r - (_p->get_y() * _p->get_y()) > 0) cout << "Точка пересечения с осью y:(" << sqrt(_r * _r - (_p->get_y() * _p->get_y())) << " ,0) " << endl;
	else cout << "Нет пересечения с осями" << endl;
}


void circle::length() const // пусть возвращает число
{
	cout << "Длина окружности: " << (get_r() * PI * 2) << endl;
}

line circle::tangent(point& p) //входные данные меняются? если нет, то конст
{
	double a = -2 * _p->get_x()+p.get_x();
	double b = -2 * _p->get_y()+p.get_y();
	double c = pow(_p->get_x(), 2) + pow(_p->get_y(), 2) - pow(_r, 2);
	return line(a, b, c);
}