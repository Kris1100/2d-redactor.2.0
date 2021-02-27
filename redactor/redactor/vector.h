#pragma once
#include "segment.h"
class myvector:public segment
{
public:
	//Конструктор
	myvector(point& begin,point& end);
	//Установить координаты вектора
	void set_coord(double x, double y);
	//Получить x координату
	double get_x();
	//Получить y координату
	double get_y();
	//Деструктор
	~myvector();
private:
	//Координаты вектора
	double x_, y_;
};

