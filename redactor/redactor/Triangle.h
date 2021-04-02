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
	bool is_equilateral();
	//Треугольник равнобедренный
	bool is_isosceles();
	//Треугольник прямоугольный
	bool is_right();
	//Определить, существует ли треугольник
	bool exists();
	//Радиус вписанной окружности
	double radius_inside();
	//Радиус описанной окружности
	double radius_outside();
};