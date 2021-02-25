#pragma once
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class polygon
{
public:
	//Конструктор многоугольника
	polygon(int num_vert = 3);
	//Установить количество углов
	void set_num(int num_vert);
	//Получить количество углов
	int get_num();
	//Вычислить периметр
	double perimetr();
	//Вычислить площадь
	double area();
	//Вывести координаты точек
	void print();
protected:
	int num_vert_;
	point* vertex = new point[num_vert_];
};