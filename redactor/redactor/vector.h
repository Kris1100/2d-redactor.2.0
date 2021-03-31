#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//Конструктор                      //частный случай - нулевой вектор, что тогда?
	myvector(point& begin,point& end);
	//Установить координаты вектора
	void set_coord(double x, double y); //приватная
	//Получить x координату
	double get_x() const;
	//Получить y координату
	double get_y() const;
	//Деструктор
	~myvector();
	//Вычисление угла между векторами
	friend double angel(myvector &v1,myvector &v2); // входные данные меняются? если нет, то конст
	//Вычисление скалярного произведения векторов
	friend double vect_prod(myvector& v1, myvector& v2);

private:
	//Координаты вектора
	double x_, y_;
};

