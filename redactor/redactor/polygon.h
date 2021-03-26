#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include"vector.h"
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
	//�������� ���������� �����
	int get_num();
	//��������� ��������
	double perimetr();
	//��������� �������
	double area();
	//������� ���������� �����
	void print();
	//�������� �� ����������
	bool is_convex();
	//�������� �� ������������
	bool is_regular(bool convexity);
	//����������
	~polygon();

protected:
	int num_vert_;
	point* vertex;
private:
	//���������� ���������� �����
	void set_num(int num_vert);
	//������ ������ �����
	void set_point_array(point* vert);
};