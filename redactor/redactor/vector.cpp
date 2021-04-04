#include "vector.h"

myvector::myvector(const point& begin, const point& end)
{
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}
myvector::myvector(double a, double b) {
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
	if (abs(v1.len()) == 0 || abs(v2.len()) == 0) return 0;
	return (vect_prod(v1, v2)) / (abs(v1.len()) * abs(v2.len())); 
}
ostream& operator<<(ostream& out,const myvector& v)
{
	cout << "(" << v.get_x() << " ," << v.get_y() <<")"<< endl;
	return out;
}