#include "round.h"
#include "math_const.h"

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

void my_round::draw() {
	glColor3ub(220, 195, 232);
	int N = 300;
	int xp = _p.centerize().get_x();
	int yp = _p.centerize().get_y();
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 1; i <= N + 2; i++)
	{
		glVertex2f(xp + _r * 40 * cos(2 * 3.14 / N * i),
			yp + _r * 40 * sin(2 * 3.14 / N * i));
	}
	glEnd();
}
