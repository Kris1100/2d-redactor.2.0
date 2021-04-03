#pragma once
#include <iostream>
#include "point.h"
#include "polygon.h"
#include "main.h"
#include "segment.h"
using namespace std;

class triangle : public polygon
{
public:
	//Конструктор треугольника
	triangle();
	//Инициализация, set
	void init();
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
};