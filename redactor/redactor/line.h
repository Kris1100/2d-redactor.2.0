#pragma once
#include<iostream>
#include <cmath>
#include <vector>
#include "point.h"
#include "vector.h"
using namespace std;

class line
{
public:
	//����������� ������ �� 2 ������
	line(point const& p1, point const& p2);
	//����������� �� ����. ������
	line(double a=1, double b=1, double c=0);

	//�������� ������ �����
	point get_first()const;           
	//�������� ������ �����
	point get_second()const;
	//�������� ���� a
	double get_a()const;
	//�������� ���� b
	double get_b()const;
	//�������� ���� c
	double get_c()const;


	//����� ���������� ������ � ���� ax+by+c=0
	void print();                                                                                                   
    //����� ���������������� ��������� ������
	void print_param();

	//���������� ������ �������
	myvector normal_vector();
	//���������� ������������ ������
	myvector guide_vector();

	//������� ����������� � ��������� ������ ax+by+c=0
	void koef(double& a, double& b, double& c );
private:
	//������ ������������ ������
	void set_a(double& a);
	void set_b(double& b);
	void set_c(double& c);
protected:
	point _p1;
	point _p2;
	double _a, _b, _c;
};

