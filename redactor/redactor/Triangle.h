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
	//Перегрузка оператора ввода
	friend ifstream& operator>>(ifstream& in, triangle& abc);//кажется, она уже есть в родительском классе
	//Находит среднюю линию треугольника к заданным сторонам
	segment middle_line(const segment& ab, const segment& bc);
	//Получить отрезки-стороны треугольника
	segment get_ab() const { return segment(vertex[0], vertex[1]); }
	segment get_bc() const { return segment(vertex[1], vertex[2]); }
	segment get_ac() const { return segment(vertex[0], vertex[2]); }

private:
	void set_vertex(const point& a, const point& b, const point& c);
};