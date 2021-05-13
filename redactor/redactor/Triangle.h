#pragma once
#include <iostream>
#include "point.h"
#include "polygon.h"
#include "segment.h"
#include "line.h"
using namespace std;

class triangle : public polygon
{
public:
	//Конструктор треугольника
	triangle();
	//Конструктор по массиву точек
	triangle(const point* vert);
	//Деструктор треугольника                //деструктор наследуется, но должен быть виртуальным в родительском классе
	//~triangle();

	//Треугольник равносторонний
	bool is_equilateral() const;
	//Треугольник равнобедренный
	bool is_isosceles() const;
	//Треугольник прямоугольный
	bool is_right() const;
	//Определить, существует ли треугольник
	bool exists() const;
	//Радиус вписанной окружности
	double radius_inside() const;
	//Радиус описанной окружности
	double radius_outside() const;
	//Лежит ли точка внутри треугольника (строго)
	bool is_inside(const point& p) const;
	//Находит среднюю линию треугольника к заданной стороне
	segment middle_line(const segment& ab, segment& bc)const;
	//Находит медиану треугольника
	segment median(const point& a, segment& bc)const;

private:
	void set_vertex(const point& a, const point& b, const point& c);
};