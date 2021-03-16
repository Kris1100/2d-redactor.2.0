#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
using namespace std;
class my_round
{
public:
	//������������ ������
	friend ostream& operator<<(ostream& out, const my_round& c);
	//������������ �����
	friend istream& operator>>(istream& in, my_round& p);
	//���������� �������
	double get_d() const;
	//����������� ����������
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//������� ����� ���������
	void equation(double a = 0.0, double b = 0.0, double r = 1.0);
	//���������� ������
	double get_r()const;
	//������ �������
	void set_r(double r = 1.0);
	//��������, ���� ���������� ��������� � ���
	void quarter() const;
	//���������� ����� ����������
	double length() const;
	//����� ����������� � �����
	void intersection() const;
	//���������� ������� �����
	double get_square() const;
	//���������� ������� ��������, �������� - ���� � ��������
	double get_square_of_segment(double a = 1) const;

	point get_p();



private:
	point* _p;
	double _r;
};
