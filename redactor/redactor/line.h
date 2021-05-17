#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "point.h"
#include "vector.h"
#include "glut-3.7.6-bin/glut.h"
#include "math_const.h"
using namespace std;

class line : public figure
{
public:
	//Конструктор прямой по 2 точкам
	line(point const& p1, point const& p2);
	//Конструктор по коэф. прямой
	line(double a = 1, double b = 1, double c = 0);
	//Конструктор копирования прямой
	line(const line& l);
	//Деструктор
	~line();

	//Получить первую точку
	point get_first() const { return _p1; }
	//Получить вторую точку
	point get_second() const { return _p2; }
	//получить коэф a
	double get_a() const { return _a; }
	//получить коэф b
	double get_b() const { return _b; }
	//получить коэф c
	double get_c() const { return _c; }

	//Возвращает вектор нормали
	myvector normal_vector();
	//Возвращает направляющий вектор
	myvector guide_vector();

	//Считает коэфициенты в уравнении прямой ax+by+c=0
	void coef(double& a, double& b, double& c );
	//Возвращает уравнение прямой,проходящей через заданную точку
	//и параллельной данной 
	line parallel(const point& p)const;
	//Проверка возрастания прямой. 1-возрастает, 0-убывает, 2- x постоянна, 3-y постоянна
	size_t is_increasing() const;

	//Вывод уравнениия прямой в виде ax+by+c=0(заданной двумя точками)
	void print_v1();
	//Вывод уравнениия прямой в виде ax+by+c=0(заданной коэф.)
	void print_v2();
	void print_all(double& a,double& b,double& c);
	//Вывод параметрического уравнения прямой
	void print_param();

	//Рисование прямой
	void draw();
	//Нарисован ли объект
	bool is_drawn = false;

	//Фрэнд функции
	friend std::istream& operator>>(std::istream& in, line& l);

private:
	//Задать коэффициенты прямой
	void set_a(double& a) {	_a = a;	}
	void set_b(double& b) {	_b = b;	}
	void set_c(double& c) {	_c = c;	}

protected:
	point _p1;
	point _p2;
	double _a, _b, _c;
};

