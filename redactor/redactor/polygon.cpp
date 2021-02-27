#include "polygon.h"
polygon::polygon(int num_vert) {
	set_num(num_vert);
	point* vert = new point[num_vert];
	set_point_array(vert);
}
polygon::~polygon() {
	delete[] vertex;
	vertex = 0;
}
std::istream& operator>>(istream& in, polygon& p) {
	double x, y;
	for (int i = 0; i < p.num_vert_; i++) {
		cin >> x >> y;
		p.vertex[i].set_x(x);
		p.vertex[i].set_y(y);
	}
	return in;
}
std::ostream& operator<<(ostream& out, polygon& p) {
	out << " оличество углов " << p.num_vert_ << endl;
	for (int i = 0; i < p.num_vert_; i++) {
		out << "x= " << p.vertex[i].get_x() << " y= " << p.vertex[i].get_y() << endl;
	}
	return out;
}
void polygon::set_point_array(point* vert) {
	vertex = vert;
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
void polygon::print(){
	for (int i = 0; i < num_vert_; i++) {
		cout <<"x= "<< vertex[i].get_x() << " y= " << vertex[i].get_y() << endl;
	}
}
bool polygon::is_convex() {
	//ћногоугольник будет выпуклым если при его обходе в каждой тройке последовательных вершин происходит поворот всегда в одну и ту же сторону. ѕри обходе многоугольника против часовой стрелке поворот будет всегда налево, а при обходе по часовой - направо.
	//ƒл€ поворота налево это(значение формулы в total) значение будет положительным, а дл€ поворота направо - отрицательным
	int sign = 0;
	for (int i = 0; i < num_vert_ - 1; i++) {
		myvector v1 (vertex[i], vertex[i + 1]);
		myvector v2(vertex[i + 1], vertex[i + 2]);
		double total = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
		if (sign==0) {
			if (total < 0) sign = -1;
			else sign = 1;
		}
		else {
			if (total * sign < 0) return false;
		}
		v1.~myvector();
		v2.~myvector();
	}
	myvector v1(vertex[num_vert_ - 1], vertex[0]);
	myvector v2(vertex[0], vertex[1]);
	double total = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
	if (total * sign < 0) return false;
	v1.~myvector();
	v2.~myvector();
	return true;
}