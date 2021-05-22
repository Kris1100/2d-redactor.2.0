#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include "circle.h"
#include "Figure.h"
using namespace std;

class my_round : public circle
{
public:
	//����������� �����
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);

	//������������ ������               //������� ������ - ������ 0. ��� ���� ������ �������������?(���� �� ������� ����� ������������)
	friend ostream& operator<<(ostream& out, const my_round& c);
	//������������ �����
	friend istream& operator>>(istream& in, my_round& p);

	//���������� ������� ��������, �������� - ���� � ��������
	double get_square_of_segment(double a = 1) const;

	void draw();
	
private:
	point _p;
	double _r;
	//������ �������
	void set_r(double r = 1.0) {
		_r = r;
	}
};
