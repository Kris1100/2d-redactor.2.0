#include "vector.h"
myvector::myvector(point& begin,point& end) {
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}
myvector::~myvector() {
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
double angel(myvector &v1,myvector &v2) {
	return (v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y()) / (abs(v1.len()) * abs(v2.len()));
}