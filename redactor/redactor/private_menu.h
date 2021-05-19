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
//��������� �� ���������� �� ���������
extern bidir_list<figure*> queue;
//����� ���������� ������ � ���������
extern bidir_list<elem> all;
//���������� ����
void SetColor(int text, int Fon);
void print_inmenu(int num, int col, vector<string>& commands);
//�������� ��������� �������
void roll_back_draw();
//�������� ������ � ������� ���������
template<typename T>
void add_draw(T& f) {
	elem one;
	Node<elem>* cur;
	cur = all.get_tail();
	bool t = false;
	while (cur != NULL && not t) {
		if (cur->info.comm == "CREATE") t = true;
		else cur = cur->prev;
	}
	queue.add_last((cur->info.obj));
	one.comm = "DRAW";
	one.obj = (cur->info.obj);
	all.add_last(one);
}
//�������� � ������ ��, ��� ������ ������
template<typename T>
void add_create(T& f) {
	elem one;
	one.comm = "CREATE";
	one.obj = new T(f);
	all.add_last(one);
	all.get_tail()->info.obj->is_created = true;
}
//�������� �������� �������
void roll_back_create();
