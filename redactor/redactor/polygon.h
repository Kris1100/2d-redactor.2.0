#pragma once
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class polygon
{
public:
	// Ќе уверенна, что так можно, к переменным точки не подобратьс€!  ак исправить?
	struct point_ {
		int x_, y_;
	};
	polygon(int num_vert = 3);
	void set_num(int num_vert);
	int get_num();
	double perimetr();
private:
	int num_vert_;
	point* vertex = new point[num_vert_];
};