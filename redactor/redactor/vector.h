#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//Конструктор                      
	myvector( const point& begin, const point& end);
	//Конструктор по координатам вектора (вектор прикрепляется к началу декартовой системы координат (0,0))
	myvector(double a = 1, double b = 1);
	//Получить x координату
	double get_x() const;
	//Получить y координату
	double get_y() const;
	//Деструктор
	~myvector() {}
	//Вычисление угла между векторами
	friend double angle(const myvector &v1, const myvector &v2);
	//Вычисление скалярного произведения векторов
	friend double vect_prod(const myvector& v1,const myvector& v2);
	friend ostream& operator<<(ostream& out,const myvector& v);
private:
	//Координаты вектора
	double x_, y_;
	//Установить координаты вектора
	void set_coord(double x, double y);
};

