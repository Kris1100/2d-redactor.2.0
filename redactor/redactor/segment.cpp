#include "segment.h"
void segment::set_extm_points(point& p1, point& p2)
{
	p1_ = p1;
	p2_ = p2;
}
double segment::len() 
{
	return sqrt( ((p1_.get_x() - p2_.get_x()) * (p1_.get_x() - p2_.get_x()))
			   + ((p1_.get_y() - p2_.get_y()) * (p1_.get_y() - p2_.get_y())) );
}
point segment::middle() {
	double x = (p1_.get_x() + p2_.get_x()) / 2;
	double y = (p1_.get_y() + p2_.get_y()) / 2;
	return point(x, y);
}