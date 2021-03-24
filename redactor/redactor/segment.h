#pragma once
#include "point.h"
#include <cmath>
#include <math.h>

//Класс отрезок
class segment
{
public:
	//Конструктор отрезка
	segment(point& p1, point& p2) {
		set_extm_points(p1, p2);
	}
	segment() {}
	//Деструктор
	~segment() {}
	//Задать крайние точки
	void set_extm_points(point& p1, point& p2);
	//Получить ссылку на начальную точку (начальная - p1_, в классе точка нет разницы, какая будет начальной)
	point& get_start() {
		return p1_;
	}
	//Ссылка на конечную точку
	point& get_end() {
		return p2_;
	}
	//Длина отрезка
	double len();
	//Координаты середины отрезка
	point middle();

protected:
	point p1_;
	point p2_;
};

