#pragma once
#include<iostream>
#include <cmath>
using namespace std;

class point
{
public:
	//����������� �����
	point(double x=0, double y=0);

	//������ ���������� �
	void set_x(double x);
	//������ ���������� �
	void set_y(double y);

	//�������� ���������� �
	double get_y() const;
	//�������� ���������� �
	double get_x() const;

	//���������� � ����� �������� ����� ������ �����,0-� ������,���� ����� ����������� ������ ���������
	double quarter();
	// ���������� ���������� �� ������ ���������
	double dist();
	//����� �� ����� �� ����������� ������������ ���������
	//���������� true /false
	bool bisector();

private:
	double _x, _y;
};

