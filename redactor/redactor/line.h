#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
#include "vector.h"
using namespace std;

class line
{
public:
	//Конструктор прямой по 2 точкам
	line(point const& p1, point const& p2);
	//Конструктор по коэф. прямой
	line(double a=1, double b=1, double c=0);

	//Получить первую точку
	point get_first()const;           
	//Получить вторую точку
	point get_second()const;
	//получить коэф a
	double get_a()const;
	//получить коэф b
	double get_b()const;
	//получить коэф c
	double get_c()const;


	//Вывод уравнениия прямой в виде ax+by+c=0
	void print();                                                                                                   
    //Вывод параметрического уравнения прямой
	void print_param();

	//Возвращает вектор нормали
	myvector normal_vector();
	//Возвращает направляющий вектор
	myvector guide_vector();

	//Считает коэфициенты в уравнении прямой ax+by+c=0
	void koef(double& a, double& b, double& c );
private:
	//Задать коэффициенты прямой
	void set_a(double& a);
	void set_b(double& b);
	void set_c(double& c);
protected:
	point _p1;
	point _p2;
	double _a, _b, _c;
};

