#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
using namespace std;

class line
{
public:
	//����������� ������
	line(point& p1,point& p2);
	//�������� ������ �����
	point* get_first();
	//�������� ������ �����
	point* get_second();
	//����� ���������� ������ � ���� ax+by+c=0
	void print();
	//����� ���������������� ��������� ������
	void param();
	//������� ������ �������
	void normal();
	//������� ������������ �������
	void guide();
	//������� ����������� � ��������� ������ ax+by+c=0 ��� x � y
	void koef(double &a,double &b);

protected:
	point* _p1;
	point* _p2;
};

