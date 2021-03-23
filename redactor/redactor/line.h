#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
using namespace std;

class line
{
public:
	//Конструктор прямой
	line(point& p1, point& p2);
	//Конструктор по осному уравнению прямой
	line(double a=1, double b=1, double c=0);
	//Получить первую точку
	point* get_first();
	//Получить вторую точку
	point* get_second();
	//Задать коэффициенты прямой
	void set_koef(double& a, double& b, double& c);
	//Вывод уравнениия прямой в виде ax+by+c=0
	void print();
	//Вывод параметрического уравнения прямой
	void param();
	//Выводит вектор нормали
	void normal();
	//Выводит направляющие вектора
	void guide();
	//Считает коэфициенты в уравнении прямой ax+by+c=0 при x и y
	void koef(double& a, double& b, double& c );

protected:
	point* _p1;
	point* _p2;
	double _a, _b, _c;
};

