#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
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
	//Вычисление угла между векторами
	friend double angel(myvector &v1,myvector &v2);
	//Вычисление скалярного произведения векторов
	friend double vect_prod(myvector& v1, myvector& v2);

private:
	//Координаты вектора
	double x_, y_;
};

