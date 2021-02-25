#pragma once
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class polygon
{
public:
	//����������� ��������������
	polygon(int num_vert = 3);
	//���������� ���������� �����
	void set_num(int num_vert);
	//�������� ���������� �����
	int get_num();
	//��������� ��������
	double perimetr();
	//��������� �������
	double area();
	//������� ���������� �����
	void print();
protected:
	int num_vert_;
	point* vertex = new point[num_vert_];
};