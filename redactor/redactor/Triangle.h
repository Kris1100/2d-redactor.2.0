#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"point.h"
#include"polygon.h"
using namespace std;

class triangle : public polygon
{
public:
	triangle();                                                                // конструктор
	~triangle();
	friend istream& operator>>(istream& in, triangle& abc);                    // ввод
	void define_kind();                                                        // определить вид треугольника
	bool exists();                                                             // определяет, существует ли треугольник
	double square();                                                           // площадь по герону
	double abc_perimetr();                                                     // периметр
	double radius_inside();                                                    // радиус вписанной окружности
	double radius_outside();                                                   // радиус описанной окружности
	
private:
	point* abc_apexes;
};