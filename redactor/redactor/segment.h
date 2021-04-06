#pragma once
#include "point.h"
#include "line.h"
#include "ray.h"
#include "math_const.h"
#include <cmath>
#include <math.h>
#include <cassert>
using namespace std;
//Класс отрезок
class segment
{
public:
	//Конструктор отрезка
	segment(const point& p1, const point& p2);
	//Конструктор по умолчанию необходим для класса vector
	segment() {};
	//Деструктор
	~segment() {}
	//Получить ссылку на начальную точку (начальная - p1_, в классе точка нет разницы, какая будет начальной)
	point get_start() const { return p1_; }
	//Ссылка на конечную точку
	point get_end() const {	return p2_;	}
	//Задать крайние точки
	void set_extm_points(const point& p1,const point& p2);
	//Длина отрезка
	double len() const;
	//Координаты середины отрезка
	point middle() const;
	//принадлежит ли отрезок прямой, лучу
	bool is_elememt(const line& l) const;
	bool is_elememt(const ray& r) const;

protected:
	point p1_;
	point p2_;
};

