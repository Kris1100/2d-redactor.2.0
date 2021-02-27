#include "vector.h"
myvector::myvector(point& begin,point& end) {
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}
myvector::~myvector() {
	delete p1_;
	delete p2_;
}
void myvector::set_coord(double x,double y) {
	x_ = x;
	y_ = y;
}
double myvector:: get_x() {
	return x_;
}
double myvector::get_y() {
	return y_;
}