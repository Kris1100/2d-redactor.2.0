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
	//Ввод многоугольника 
	friend std::istream& operator>>(std::istream& in, polygon& p);
	//Вывод всей информации по многоугольнику
	friend std::ostream& operator<<(std::ostream& out, polygon& p);
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
	//Задать массив точек
	void set_point_array(point *vert);
	//Деструктор
	~polygon();
protected:
	int num_vert_;
	point* vertex;
};