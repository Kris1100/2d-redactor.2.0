#include "polygon.h"
polygon::polygon(int num_vert) {
	set_num(num_vert);
	double x, y;
	for (int i = 0; i < num_vert;i++) {
		cin >> x >> y;
		vertex[i].set_x(x);
		vertex[i].set_y(y);
	}
}
void polygon::set_num(int num_vert) {
	num_vert_ = num_vert;
}
int polygon:: get_num() {
	return num_vert_;
}
double polygon::perimetr() {
	double p = 0;
	for (int i = 0; i < num_vert_-1; i++) {
		p += abs(vertex[i].dist() - vertex[i + 1].dist());
	}
	p+= abs(vertex[num_vert_-1].dist() - vertex[0].dist());
	return p;
}
double polygon:: area() {
	double s1=0, s2=0, s=0;
	for (int i = 0; i < num_vert_ - 1; i++) {
		s1 += vertex[i].get_x() * vertex[i + 1].get_y();
	}
	s1 += vertex[0].get_y() * vertex[num_vert_ - 1].get_x();
	for (int i = 0; i < num_vert_ - 1; i++) {
		s2 += vertex[i+1].get_x() * vertex[i].get_y();
	}
	s2 += vertex[num_vert_-1].get_y() * vertex[0].get_x();
	s = 0.5 * abs(s1 - s2);
	return s;
}