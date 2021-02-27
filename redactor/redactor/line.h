#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
using namespace std;
class line
{
public:
	line(point& p1,point& p2);//конструктор прямой
	point* get_first();//получить первую точку
	point* get_second();//получить вторую точку
	void print();//выводу уравнениия прямой в виде ax+by+c=0
	void param();//вывод параметрического уравнения прямой
	void normal();//выводит вектор нормали
	void guide();//выводит направляющие вектора
	void koef(double &a,double &b);//считает коэфициенты в уравнении пряямой ax+by+c=0 при x и y
protected:
	point* _p1;
	point* _p2;
};

