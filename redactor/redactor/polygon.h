#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "vector.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class polygon : public figure
{
public:
	//Конструктор многоугольника. По умолчанию задачется правильный n-угольник          
	polygon(size_t num_vert = 3);
	//Конструктор копирования
	polygon(const polygon& t);
	//Деструктор
	~polygon();

	//Получить количество углов
	size_t get_num() const { return num_vert_; }
	//Получить указатель на массив точек многоугольника
	point* get_vertexes() const { return vertex; }

	//Вычислить периметр
	double perimetr() const;
	//Вычислить площадь
	double area() const;
	//Проверка многоугольника на существование(корректность ввода)
	bool is_correct() const;
	//Вывести координаты точек
	void print() const;
	//Проверка на выпуклость
	bool is_convex() const;
	//Проверка на правильность
	bool is_regular(bool convexity) const;

	//Рисование многоугольника
	void draw();
	
	//Ввод многоугольника 
	friend std::istream& operator>>(std::istream& in, polygon& p);
	//Вывод всей информации по многоугольнику
	friend std::ostream& operator<<(std::ostream& out, polygon& p);

	void mymenu();

protected:
	size_t num_vert_ = 0;
	point* vertex = nullptr;

private:
	//Установить количество углов
	void set_num(size_t num_vert);
	//Задать массив точек(по умолчанию задает точки правильного num_vert-угольника)
	void set_point_array(point* vert);
};