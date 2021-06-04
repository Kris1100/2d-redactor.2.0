#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "point.h"
#include "line.h"
#include "math_const.h"
#include "Figure.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class circle : public figure
{
public:
	//����������� ����������
	circle(double x = 0.0, double y = 0.0, double r = 1.0);
	//����������� �����������
	circle(const circle& c);
	//����������
	~circle();

	//������������ ������                
	friend ostream& operator<<(ostream& out, const circle& c);
	//������������ �����
	friend istream& operator>>(istream& in, circle& p);

	//���������� �������
	double get_d() const {
		return _r * 2;
	}
	//���������� ������
	double get_r()const {
		return _r;
	}
	// ���������� �����
	point get_p() const {
		return _p;
	}

	//���������� ��������, ���� ���������� ��������� � ��� � -1 ���� ����� � ���������� �� ���������
	int quarter() const;
	//���������� ����� ����������
	double length() const {
		return (get_r() * constants::pi * 2);
	}
	//����� ����������� � �����
	void intersection() const; // �����, ����� �������� �� ���� ����� � �������� �� � �������, ����� ��� ���� �������
	//���������� ����������� � ���������� ����� ������ �����
	line tangent(point &p);

	//��������� ����������
	void draw();
	
	void mymenu();

private:
	point _p;
	double _r;
	//������ �������
	void set_r(double r = 1.0) {
		_r = r;
	}
};
