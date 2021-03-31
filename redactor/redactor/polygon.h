#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include"vector.h"
using namespace std;

class polygon
{
public:
	//Конструктор многоугольника            //полагаю, что нужно определение вырожденного случая
	polygon(int num_vert = 3);
	//Ввод многоугольника 
	friend std::istream& operator>>(std::istream& in, polygon& p);      //std точно нужно?
	//Вывод всей информации по многоугольнику
	friend std::ostream& operator<<(std::ostream& out, polygon& p);
	//Получить количество углов
	int get_num() const;
	//Вычислить периметр
	double perimetr() const; //возможно, стоит переименовать на calc_perimetr
	//Вычислить площадь
	double area() const;
	//Вывести координаты точек
	void print() const;
	//Проверка на выпуклость
	bool is_convex() const;
	//Проверка на правильность
	bool is_regular(bool convexity) const;
	//Деструктор
	~polygon();

protected:
	int num_vert_;
	point* vertex;
private:
	//Установить количество углов
	void set_num(int num_vert);
	//Задать массив точек
	void set_point_array(point* vert);
};