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
	//���� �������������� 
	friend std::istream& operator>>(std::istream& in, polygon& p);
	//����� ���� ���������� �� ��������������
	friend std::ostream& operator<<(std::ostream& out, polygon& p);
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
	//������ ������ �����
	void set_point_array(point *vert);
	//����������
	~polygon();
protected:
	int num_vert_;
	point* vertex;
};