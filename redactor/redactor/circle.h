#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include "line.h"
using namespace std;

class circle
{
public:	
	//����������� ����������
	circle(double x = 0.0, double y = 0.0, double r = 1.0);
	//������������ ������                
	friend ostream& operator<<(ostream& out, const circle& c);
	//������������ �����
	friend istream& operator>>(istream& in, circle& p);
	//���������� �������
	double get_d() const;
	//���������� ������
	double get_r()const;
	// ���������� �����
	point get_p() const;
	//���������� ��������, ���� ���������� ��������� � ��� � -1 ���� ����� � ���������� �� ���������
	int quarter() const;
	//���������� ����� ����������
	double length() const;
	//����� ����������� � �����
	void intersection() const; // �����, ����� �������� �� ���� ����� � �������� �� � �������, ����� ��� ���� �������
	//���������� ����������� � ���������� ����� ������ �����
	line tangent(point &p) ;
	//����������?
private:
	point* _p;
	double _r;
	//������ �������
	void set_r(double r = 1.0); 
};
