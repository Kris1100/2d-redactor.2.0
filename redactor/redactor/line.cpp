#include "line.h"
#include "vector.h"
using namespace std;

line::line(point const& p1, point const& p2)
{
	_p1 = point(p1.get_x(), p1.get_y());
	_p2 = point(p2.get_x(), p2.get_y());
}

line::line(double a=1, double b=1, double c=0)
{
	set_a(a);
	set_b(b);
	set_c(c);
}

point line::get_first() const
{
	return _p1;
}

point line::get_second()const
{
	return _p2;
}

double line::get_a()const
{
	return _a;
}
double line::get_b()const
{
	return _b;
}
double line::get_c()const
{
	return _c;
}

void line::set_a(double& a) 
{
	_a = a;
}
void line::set_b(double& b)
{
	_b = b;
}
void line::set_c(double& c)
{
	_c = c;
}

void line::print() 
{
	double a, b, c;
	koef(a, b,c);
	if (a != 0)cout << a << 'x';
	else if (a == 1)cout << 'x';
	else if (a == -1)cout << '-x';
	if (b < 0 && b != -1)cout << b << 'y';
	else if (b == -1)cout << '-' << 'y';
	else if (b > 0 && b != 1) cout << '+' << b << 'y';
	else if (b == 1)cout << '+' << 'y';
	if (c < 0)cout << c;
	else if (c > 0)cout << '+' << c;
	cout << '='<< 0<< endl;
}

void line::print_param() 
{
	double a, b,c;
	koef(a, b,c);
	myvector v=normal_vector();
	cout << "Параметрическое уравнение" << endl;
	cout << 'x' << '=' << _p1.get_x();
	if (v.get_x() < 0)
		cout << v.get_x() << 't' << endl;
	else
		cout << '+' << v.get_x() << endl;
	cout << 'y' << '=' << _p1.get_y();
	if (v.get_y() < 0)
		cout << v.get_y() << 't' << endl;
	else
		cout << '+' << v.get_y() << endl;
}

myvector line::normal_vector()
{
	double a, b, c;
	koef(a, b, c);
	point p1(0,0), p2(a,b);
	return myvector(p1, p2);
}

myvector line::guide_vector() 
{
	double a, b, c;
	koef(a, b, c);
	point p1(0,0), p2(b,-a);
	return myvector(p1, p2);
}

void line:: koef( double& a, double& b, double& c)
{
	a = _p2.get_y() - _p1.get_y();
	b = _p1.get_x() - _p2.get_x();
	c = _p1.get_y() *( _p2.get_x()-_p1.get_x())+_p1.get_x()*(_p1.get_y()- _p2.get_y());
}
