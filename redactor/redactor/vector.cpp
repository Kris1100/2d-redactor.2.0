#include "vector.h"

myvector::myvector(const point& begin, const point& end)
{
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}

myvector::myvector(double a, double b) 
{
	set_coord(a, b);
	point begin, end;
	begin.set_x(0); begin.set_y(0);
	end.set_x(a); end.set_y(b);
}

void myvector::set_coord(double x, double y)
{
	x_ = x;
	y_ = y;
}

double myvector::get_x() const
{
	return x_;
}

double myvector::get_y() const
{
	return y_;
}

double vect_prod(const myvector& v1,const myvector& v2)
{
	return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y();
}

double angle(const myvector& v1, const myvector& v2) 
{
	if (abs(v1.len()) == 0 || abs(v2.len()) == 0) 
		return 0;
	return round((acos((vect_prod(v1, v2)) / (abs(v1.len()) * 
		abs(v2.len())))*180/constants::pi)*constants::rd)/constants::rd; 
}

ostream& operator<<(ostream& out,const myvector& v)
{
	cout << "(" << v.get_x() << " ," << v.get_y() <<")"<< endl;
	return out;
}

void myvector::draw()
{
	point p(p1_.centerize().get_x(), p1_.centerize().get_y());
	point end(p2_.centerize().get_x(), p2_.centerize().get_y());
	double angle = atan2(p.get_x() - end.get_x(), p.get_y() - end.get_y());
	int arrow_length = 15;
	int arrow_angle = 120;
	point p1(end.get_x() + arrow_length * sin(angle + arrow_angle), 
		     end.get_y() + arrow_length * cos(angle + arrow_angle));
	point p2(end.get_x() + arrow_length * sin(angle - arrow_angle), 
		     end.get_y() + arrow_length * cos(angle - arrow_angle));
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(p.get_x(), p.get_y());
	glColor3ub(179, 222, 255);
	glVertex2f(end.get_x(), end.get_y());
	glVertex2f(end.get_x(), end.get_y());
	glVertex2f(p1.get_x(), p1.get_y());
	glVertex2f(end.get_x(), end.get_y());
	glVertex2f(p2.get_x(), p2.get_y());
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	int N = 360;
	int R = 3;
	for (int i = 1; i <= N; i++)
	{
		glVertex2f(p.centerize().get_x() + R * cos(2 * 3.14 / N * i),
			p.centerize().get_y() + R * sin(2 * 3.14 / N * i));
	}
	glEnd();
}