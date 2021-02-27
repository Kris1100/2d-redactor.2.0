#include "segment.h"
segment::segment(point& p1, point& p2) {
	set_extm_points(p1, p2);
}
segment::segment() {
}
segment::~segment() {
	delete p1_;
	delete p2_;
}
void segment::set_extm_points(point& p1, point& p2) {
	p1_ = new point(p1.get_x(),p1.get_y());
	p2_ = new point(p2.get_x(),p2.get_y());
}
point *segment::get_start() {
	return p1_;
}
point* segment::get_end() {
	return p2_;
}
double segment::len() {
	return sqrt(((p1_->get_x() - p2_->get_x()) * (p1_->get_x() - p2_->get_x())) + ((p1_->get_y() - p2_->get_y()) * (p1_->get_y() - p2_->get_y())));
}