#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "bidir_list.h"
#include "Figure.h"
using namespace std;
struct elem {
	figure* obj;
	string comm = "";
};
//Указатель на переменную на отрисовку
extern bidir_list<figure*> queue;
//Общий двусвязный список с командами
extern bidir_list<elem> all;
//Установить цвет
void SetColor(int text, int Fon);
void print_inmenu(int num, int col, vector<string>& commands);
//Откатить рисование объекта
void roll_back_draw();
//Добваить объект в очередь рисования
template<typename T>
void add_draw(T& f) {
	elem one;
	queue.add_last(new T(f));
	one.comm = "DRAW";
	one.obj = queue.get_tail()->info;
	all.add_last(one);
}
