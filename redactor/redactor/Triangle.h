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
	void define_kind();                                                        // определить вид треугольника
	bool exists();                                                             // определяет, существует ли треугольник
	double square();
	double perimetr();
	double radius_inside();                                                    // радиус вписанной окружности
	double radius_outside();                                                   // радиус описанной окружности
	
private:
	vector<point> abc_apexes;
};