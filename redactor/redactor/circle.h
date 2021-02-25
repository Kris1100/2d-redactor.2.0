#pragma once
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class circle
{
public:
	//������������ ������
	friend ostream& operator<<(ostream& out, const circle& c);
	//������������ �����
	friend istream& operator>>(istream& in, circle& p)const;
	//���������� �������
	double get_d() const;
	//����������� ����������
	circle(point p, double r = 1) const;
	//������� ����� ��������� !!����������!!
	void equation(double a, double b, double r);
	//������ ������
	void set_center(double x, double y);
	//���������� ������
	double get_r()const;
	//������ �������
	void set_r(double r);
	//��������, ���� ���������� ��������� � ���
	void quarter() const;
	//���������� ����� ����������
	double length() const;

private:
	point _p;
	double _r;
};
