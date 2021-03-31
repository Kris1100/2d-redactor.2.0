#include "vector.h"

myvector::myvector(point& begin, point& end)
{
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}

myvector::~myvector() 
{
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

double vect_prod(myvector& v1, myvector& v2)
{
	return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y();
}

double angel(myvector& v1, myvector& v2)
{
	return (vect_prod(v1, v2)) / (abs(v1.len()) * abs(v2.len()));
}