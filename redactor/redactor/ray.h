#pragma once
#include <iostream>
#include "point.h"
#include "Figure.h"
#include "line.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"

class ray : public figure
{
public:
	//Конструктор
	ray(const point& begin, const point& p);
	//Конструктор копирования
	ray(const ray& r);
	//Деструктор
	~ray();

	//Получить точку начала луча и точку на луче
	point get_begin() const { return _begin; }
	point get_p() const { return _p; }
	//Функция принадлежности точки лучу
	bool is_element(const point& t);
	//Перегрузка операторов ввода и вывода
	friend ifstream& operator>>(ifstream& in, ray& r);
	friend ostream& operator<<(ostream& out, const ray& r);

	//Рисование 
	void draw();
	//
	void mymenu();

private:
	//Сеттеры начала луча и произвольной точки на луче
	void set_begin(const point& begin) { _begin = begin; }
	void set_p(const point& p) { _p = p; }

	point _begin;
	point _p;
};