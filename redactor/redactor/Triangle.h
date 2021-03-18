#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"point.h"
#include"polygon.h"
#include"segment.h"
using namespace std;

class triangle : public polygon
{
public:
	triangle();                                                                // конструктор
	void define_kind();                                                        // определить вид треугольника
	//perimetr i ploschad' nasleduyutsa ot polygona, zrya pisala
	bool exists();                                                             // определяет, существует ли треугольник
	double radius_inside();                                                    // радиус вписанной окружности
	double radius_outside();                                                   // радиус описанной окружности
	
private:
	vector<point> abc_apexes;
};