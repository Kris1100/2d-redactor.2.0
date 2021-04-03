#pragma once
#include <iostream>
#include "point.h"
#include "line.h"

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

	bool is_element(const point& t);

private:
	//Сеттеры начала луча и какой-то точки на луче
	void set_begin(const point& begin) { _begin = begin; }
	void set_p(const point& p) { _p = p; }

	point _begin;
	point _p;
};

