#pragma once
#include "point.h"
#include <cmath>
#include <math.h>
#include <cassert>
using namespace std;
//Класс отрезок
class segment
{
public:
	//Конструктор отрезка
	segment(point& p1, point& p2);
	segment() {}
	//Деструктор
	~segment() {}
	//Получить ссылку на начальную точку (начальная - p1_, в классе точка нет разницы, какая будет начальной)
	point get_start() const {  
		return p1_;
	}
	//Ссылка на конечную точку
	point get_end() const {
		return p2_;
	}
	//Задать крайние точки
	void set_extm_points(point& p1, point& p2);
	//Длина отрезка
	double len() const;
	//Координаты середины отрезка
	point middle() const;

protected:
	point p1_;
	point p2_;
};

