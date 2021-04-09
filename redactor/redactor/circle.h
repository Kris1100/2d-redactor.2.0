#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "point.h"
#include "line.h"
using namespace std;
const double PI = 3.141592653589793238463;
class circle
{
public:	
	//����������� ����������
	circle(double x = 0.0, double y = 0.0, double r = 1.0);//��� ���� ������ 0? ��� �����? � ���� �������������?
	//����������
	~circle();
	
	//������������ ������                
	friend ostream& operator<<(ostream& out, const circle& c);
	//������������ �����
	friend istream& operator>>(istream& in, circle& p);
	//���������� �������
	double get_d() const { return _r * 2; }
	//���������� ������
	double get_r()const { return _r; }
	// ���������� �����
	// !!TODO �������������
	point get_p() const { return _centr; }
	
	//���������� ����� ��������, ���� ���������� ��������� � ��� � -1 ���� ����� � ���������� �� ���������
	int quarter() const;
	//���������� ����� ����������
	double length() const {	return (get_r() * M_PI * 2); }
	//����� ����������� � �����
	// !!TODO �����, ����� �������� �� ���� ����� � �������� �� � �������, ����� ��� ���� �������
	void intersection() const; 
	//���������� ����������� � ���������� ����� ������ �����
	line tangent(const point &p)const;
private:
	point _centr; 
	double _r;
	//������ �������
	void set_r(double r = 1.0) { _r = r; }
};
