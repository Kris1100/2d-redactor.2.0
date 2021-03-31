#pragma once
#include "polygon.h"
#include "point.h"
#include "line.h"
#include "segment.h"
#include "Triangle.h"
#include "vector.h"
#include "point.h"
#include "circle.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>
//Установить цвет
void SetColor(int text, int Fon);
//Печать меню
void print_menu(int num, int col);
//Меню для точки
void print_point(int num);
//Меню для прямой
void print_line(int num);
//Меню для многоугольника
void print_polygon(int num);
//Меню для окружности
void print_circle(int num);
//Меню для отрезка
void print_segment(int num);
//Меню для треугольника
void print_triangle(int num);
//Меню для вектора
void print_vector(int num);