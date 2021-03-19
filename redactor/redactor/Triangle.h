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
	//Конструктор треугольника
	triangle();
	//Деструктор треугольника
	~triangle();
	//Ввод треугольника
	friend istream& operator>>(istream& in, triangle& abc);
	//Определить вид треугольника
	void define_kind();
	//Определить, существует ли треугольник
	bool exists();
	//Радиус вписанной окружности
	double radius_inside();
	//Радиус описанной окружности
	double radius_outside();
	
private:
	bool was_checked_existence = false;
};