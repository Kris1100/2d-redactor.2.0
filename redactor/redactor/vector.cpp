#include "vector.h"
vector::vector(point& begin,point& end) {
	set_extm_points(begin, end);
	set_coord(end.get_x() - begin.get_x(), end.get_y() - begin.get_y());
}
void vector::set_coord(double x,double y) {
	x_ = x;
	y_ = y;
}