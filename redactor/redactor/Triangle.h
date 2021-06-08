#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "point.h"
#include "polygon.h"
#include "segment.h"
#include "line.h"
#include "math_const.h"
#include "private_menu.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class triangle : public polygon
{
public:
	//����������� ������������
	triangle();
	//����������� �� ������� �����
	triangle(const point* vert);
	//���������� ������������                //���������� �����������, �� ������ ���� ����������� � ������������ ������
	//~triangle();

	//����������� ��������������
	bool is_equilateral() const;
	//����������� ��������������
	bool is_isosceles() const;
	//����������� �������������
	bool is_right() const;
	//����������, ���������� �� �����������
	bool exists() const;
	//������ ��������� ����������
	double radius_inside() const;
	//������ ��������� ����������
	double radius_outside() const;
	//����� �� ����� ������ ������������ (������)
	bool is_inside(const point& p) const;
	//������� ������� ����� ������������ � �������� �������
	segment middle_line(const segment& ab, const segment& bc) const;
	//������� ������� ������������
	segment median(const point& a, const segment& bc) const;
	//���������� ����� ������������ ������ �����
	point* get_vertex() const;

	//��������� ������������
	void draw();
	//���� ������������
	void mymenu();

	//Friend �������
	//���� �������������� 
	friend std::istream& operator>>(std::istream& in, triangle& t);

private:
	void set_vertex(const point& a, const point& b, const point& c);
};