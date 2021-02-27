#pragma once
#include "segment.h"
class vector:public segment
{
public:
	//Конструктор
	vector(point& begin,point& end);
	//Установить координаты вектора
	void set_coord(double x, double y);
private:
	//Координаты вектора
	double x_, y_;
};

