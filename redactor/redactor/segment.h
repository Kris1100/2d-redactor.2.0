#pragma once
#include "point.h"
#include <cmath>
#include <math.h>

//Класс отрезок
class segment
{
public:
	//Конструктор отрезка
	segment(point& p1, point& p2);
	segment();
	//Деструктор
	~segment();
	//Задать крайние точки
	void set_extm_points(point& p1, point& p2);
	//Получить ссылку на начальную точку (начальная - p1_, в классе точка нет разницы, какая будет начальной)
	point& get_start();
	//Ссылка на конечную точку
	point& get_end();
	//Длина отрезка
	double len();

protected:
	point p1_;
	point p2_;
};

