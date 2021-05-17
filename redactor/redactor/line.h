#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "point.h"
#include "vector.h"
#include "glut-3.7.6-bin/glut.h"
#include "math_const.h"
using namespace std;

class line : public figure
{
public:
	//����������� ������ �� 2 ������
	line(point const& p1, point const& p2);
	//����������� �� ����. ������
	line(double a = 1, double b = 1, double c = 0);
	//����������� ����������� ������
	line(const line& l);
	//����������
	~line();

	//�������� ������ �����
	point get_first() const { return _p1; }
	//�������� ������ �����
	point get_second() const { return _p2; }
	//�������� ���� a
	double get_a() const { return _a; }
	//�������� ���� b
	double get_b() const { return _b; }
	//�������� ���� c
	double get_c() const { return _c; }

	//���������� ������ �������
	myvector normal_vector();
	//���������� ������������ ������
	myvector guide_vector();

	//������� ����������� � ��������� ������ ax+by+c=0
	void coef(double& a, double& b, double& c );
	//���������� ��������� ������,���������� ����� �������� �����
	//� ������������ ������ 
	line parallel(const point& p)const;
	//�������� ����������� ������. 1-����������, 0-�������, 2- x ���������, 3-y ���������
	size_t is_increasing() const;

	//����� ���������� ������ � ���� ax+by+c=0(�������� ����� �������)
	void print_v1();
	//����� ���������� ������ � ���� ax+by+c=0(�������� ����.)
	void print_v2();
	void print_all(double& a,double& b,double& c);
	//����� ���������������� ��������� ������
	void print_param();

	//��������� ������
	void draw();
	//��������� �� ������
	bool is_drawn = false;

	//����� �������
	friend std::istream& operator>>(std::istream& in, line& l);

private:
	//������ ������������ ������
	void set_a(double& a) {	_a = a;	}
	void set_b(double& b) {	_b = b;	}
	void set_c(double& c) {	_c = c;	}

protected:
	point _p1;
	point _p2;
	double _a, _b, _c;
};

