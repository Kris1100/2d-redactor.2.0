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