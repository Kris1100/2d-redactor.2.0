#pragma once
#include "polygon.h"
#include "point.h"
#include "line.h"
#include "segment.h"
#include "Triangle.h"
#include "vector.h"
#include "point.h"
#include "circle.h"
#include "round.h"
#include "Figure.h"
#include "ray.h"
#include "bidir_list.h"
#include "private_menu.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <fstream>
#include <string>

#include <stdlib.h>
#include "glut-3.7.6-bin/glut.h"

extern int window;
extern bool win;

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
//Меню для луча
void print_ray(int num);
//Фкнкция, соединяющая рисование
void main_pr();
//Оформление фона окна редактора
void paint_field();
//Вызывает метод draw конкретного класса,управляет выводом на экран
void Display(void);
//Вызывается при изменении размера окна
void Reshape(GLint w, GLint h);
//Обработчик клавиатуры
void KeyBoard(unsigned char key,int x,int y);
//Функция обработки клавиш главного меню
int invalid();