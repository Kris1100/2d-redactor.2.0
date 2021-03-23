#include "line.h"
using namespace std;

line::line(point& p1, point& p2)
{
	_p1 = new point(p1.get_x(), p1.get_y());
	_p2 = new point(p2.get_x(), p2.get_y());
}
line::line(double a, double b, double c) {
	set_koef(a, b, c);
}
point* line::get_first()
{
	return _p1;
}

point* line::get_second()
{
	return _p2;
}
void line::set_koef(double& a, double& b, double& c) {
	_a = a; _b = b; _c = c;
}
void line::print()
{
	double a, b, c;
	koef(a, b,c);
	c = -(_p1->get_x()) * a - (_p1->get_y()) * b;
	if (a != 0)
		cout << a << 'x';
	else
		if (a == 1)
			cout << 'x';
		else
			if (a == -1)
				cout << '-x';
	if (b < 0 && b != -1)
		cout << b << 'y';
	else
		if (b == -1)
			cout << '-' << 'y';
		else
			if (b > 0 && b != 1)
				cout << '+' << b << 'y';
			else
				if (b == 1)
					cout << '+' << 'y';
	if (c < 0)
		cout << c;
	else
		if (c > 0)
			cout << '+' << c;
	cout << '=' << 0 << endl;
}

void line::param()
{
	double a, b,c;
	koef(a, b,c);
	cout << "Параметрическое уравнение" << endl;
	a = -a;
	cout << 'x' << '=' << _p1->get_x();
	if (b < 0)
		cout << b << 't' << endl;
	else
		cout << '+' << b << endl;
	cout << 'y' << '=' << _p1->get_y();
	if (a < 0)
		cout << a << 't' << endl;
	else
		cout << '+' << a << endl;
}

void line::normal()
{
	double a, b,c;
	koef(a, b,c);
	cout << "Вектор нормали" << endl;
	cout << '(' << a << ',' << b << ')' << endl;
}

void line::guide()
{
	double a, b,c;
	koef(a, b,c);
	cout << "Направляющие вектора" << endl;
	cout << '(' << b << ',' << -a << ')' << endl;
	cout << '(' << -b << ',' << a << ')' << endl;
}

void line::koef(double& a, double& b, double& c)
{
	a = _p2->get_y() - _p1->get_y();
	b = _p1->get_x() - _p2->get_x();
	c = (_p2->get_x() * _p1->get_y())-(_p2->get_y()* _p1->get_x());
}
