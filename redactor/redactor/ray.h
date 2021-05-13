#pragma once
#include <iostream>
#include "point.h"

class ray
{
public:
	//Конструктор
	ray(const point& begin, const point& p);
	//Деструктор
	~ray() { }

	//Получить точку начала луча и точку на луче
	point get_begin() const { return _begin; }
	point get_p() const { return _p; }
	//Перегрузка операторов ввода и вывода
	friend ifstream& operator>>(ifstream& in, ray& r);
	friend ostream& operator<<(ostream& out, const ray& r);

private:
	//Сеттеры начала луча и произвольной точки на луче
	void set_begin(const point& begin) { _begin = begin; }
	void set_p(const point& p) { _p = p; }

	point _begin;
	point _p;
};