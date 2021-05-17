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

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <fstream>
#include <string>

#include <stdlib.h>
#include "glut-3.7.6-bin/glut.h"
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
//������ ����
void print_menu(int num, int col);
//���� ��� �����
void print_point(int num);
//���� ��� ������
void print_line(int num);
//���� ��� ��������������
void print_polygon(int num);
//���� ��� ����������
void print_circle(int num);
//���� ��� �������
void print_segment(int num);
//���� ��� ������������
void print_triangle(int num);
//���� ��� �������
void print_vector(int num);
//���� ��� ����
void print_ray(int num);
//�������, ����������� ���������
void main_pr();
//���������� ���� ���� ���������
void paint_field();
//�������� ����� draw ����������� ������,��������� ������� �� �����
void Display(void);
//���������� ��� ��������� ������� ����
void Reshape(GLint w, GLint h);
//�������� ��������� �������
void roll_back_draw();
//�������� ������ � ������� ���������
template<typename T>
void add_draw(T& f);