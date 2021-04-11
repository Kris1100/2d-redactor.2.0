#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include"vector.h"
using namespace std;

class polygon
{
public:
	//Конструктор многоугольника. По умолчанию задачется правильный n-угольник          
	polygon(int num_vert = 3);
	//Деструктор
	~polygon();

	//Получить количество углов
	int get_num() const;
	//Получить указатель на массив точек многоугольника
	point* get_vertexes() const;

	//Вычислить периметр
	double perimetr() const;
	//Вычислить площадь
	double area() const;
	//Вывести координаты точек
	void print() const;
	//Проверка на выпуклость
	bool is_convex() const;
	//Проверка на правильность
	bool is_regular(bool convexity) const;
	
	//Ввод многоугольника 
	friend std::istream& operator>>(std::istream& in, polygon& p);
	//Вывод всей информации по многоугольнику
	friend std::ostream& operator<<(std::ostream& out, polygon& p);
protected:
	int num_vert_;
	point* vertex;
private:
	//Установить количество углов
	void set_num(int num_vert);
	//Задать массив точек(по умолчанию задает точки правильного num_vert-угольника)
	void set_point_array(point* vert);
};