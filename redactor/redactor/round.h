#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include <circle.h>
using namespace std;
class my_round : public circle
{
public:
	//������������ ������
	friend ostream& operator<<(ostream& out, const my_round& c);
	//������������ �����
	friend istream& operator>>(istream& in, my_round& p);
	//����������� ����������
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//���������� ������� �����
	double get_square() const;
	//���������� ������� ��������, �������� - ���� � ��������
	double get_square_of_segment(double a = 1) const;
	void quarter() const;

	point* _p;
	double _r;
};
