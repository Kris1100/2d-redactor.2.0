#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
using namespace std;
class line
{
public:
	line(point& p1,point& p2);//����������� ������
	point* get_first();//�������� ������ �����
	point* get_second();//�������� ������ �����
	void print();//������ ���������� ������ � ���� ax+by+c=0
	void param();//����� ���������������� ��������� ������
	void normal();//������� ������ �������
	void guide();//������� ������������ �������
	void koef(double &a,double &b);//������� ����������� � ��������� ������� ax+by+c=0 ��� x � y
protected:
	point* _p1;
	point* _p2;
};

