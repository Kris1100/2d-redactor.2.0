#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "point.h"
#include "polygon.h"
#include "segment.h"
#include "line.h"
#include "math_const.h"
#include "private_menu.h"
#include "glut-3.7.6-bin/glut.h"
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
	segment middle_line(const segment& ab, const segment& bc) const;
	//Находит медиану треугольника
	segment median(const point& a, const segment& bc) const;
	//Возвращает новый динамический массив точек
	point* get_vertex() const;

	//Рисование треугольника
	void draw();
	//Меню треугольника
	void mymenu();

	//Friend функции
	//Ввод многоугольника 
	friend std::istream& operator>>(std::istream& in, triangle& t);

private:
	void set_vertex(const point& a, const point& b, const point& c);
};