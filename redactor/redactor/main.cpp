#pragma once
#include "polygon.h"
#include "point.h"
#include "circle.h"
#include "line.h"
#include "segment.h"
#include "Triangle.h"
#include "vector.h"


#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
void SetColor(int text, int Fon);
void print_menu(int num);
void print_menu1(int num);
void print_point(int num);// Меню для точки
void print_line(int num);// Меню для прямой
void print_polygon(int num);// Меню для многоугольника
void print_circle(int num);// Меню для окружности
void print_segment(int num);// Меню для отрезка
void print_triangle(int num);// Меню для треугольника
void print_vector(int num);// Меню для вектора



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetColor(1, 15);

	int item = 0;
	print_menu(0, 1);
	while (true) {
		int key = _getch();
		if (key == 13) {
			switch (item)
			{
			case 0: return 0;
			case 1: print_point(0);  break;
			case 2: print_line(0);  break;
			case 3: print_circle(0); break;
			case 4: print_triangle(0);  break;
			case 5: print_polygon(0);  break;
			case 6: print_segment(0);  break;
			case 7: print_vector(0);  break;

			default:
				break;
			}
		}
		else {

			switch (key)
			{
			case 72: item--;  break;
			case 80: item++;  break;
			case 48: item = 0;  break;
			case 49: item = 1;  break;
			case 50: item = 2;  break;
			case 51: item = 3;  break;
			case 52: item = 4;  break;
			case 53: item = 5;  break;
			case 54: item = 6;  break;
			case 55: item = 7;  break;



			}
			print_menu(item, 15);
			if (item < 0) item = 7;
			if (item > 7) item = 0;

		}

	}

	system("pause");
	return 0;

}
void print_menu(int num, int col) {
	if (col == 1) col2 = 7;
	else col2 = 1;
	system("cls");
	SetColor(15, 1);
	cout << "\n";
	SetColor(1, 15);
	if (num < 0) num = 7;
	if (num > 7) num = 0;
	if (num == 0) {
		SetColor(col, col2);
		cout << "0. Выход\n";
		SetColor(1, 15);
	}
	else cout << "0. Выход\n";
	if (num == 1) {
		SetColor(col, col2);
		cout << "1. Точка\n";
		SetColor(1, 15);
	}
	else cout << "1. Точка\n";
	if (num == 2) {
		SetColor(col, col2);
		cout << "2. Прямая\n";
		SetColor(1, 15);
	}
	else cout << "2. Прямая\n";
	if (num == 3) {
		SetColor(col, col2);
		cout << "3. Окружность\n";
		SetColor(1, 15);
	}
	else cout << "3. Окружность\n";
	if (num == 4) {
		SetColor(col, col2);
		cout << "4. Треугольник\n";
		SetColor(1, 15);
	}
	else cout << "4. Треугольник\n";
	if (num == 5) {
		SetColor(col, col2);
		cout << "5. Треугольник\n";
		SetColor(1, 15);
	}
	else cout << "5. Треугольник\n";
	if (num == 6) {
		SetColor(col, col2);
		cout << "6. Треугольник\n";
		SetColor(1, 15);
	}
	else cout << "6. Треугольник\n";
	if (num == 7) {
		SetColor(col, col2);
		cout << "7. Треугольник\n";
		SetColor(1, 15);
	}
	else cout << "7. Треугольник\n";

}

void SetColor(int text, int Fon) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (Fon << 4) + text);
}