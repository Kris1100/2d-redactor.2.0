#pragma once
#include <cmath>
#include "segment.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"

class myvector: public segment
{
public:
	//�����������                      
	myvector( const point& begin, const point& end);
	//����������� �� ����������� ������� (������ ������������� � ������ ���������� ������� ��������� (0,0))
	myvector(double a = 1, double b = 1);
	//����������
	~myvector() {}

	//�������� x ����������
	double get_x() const;
	//�������� y ����������
	double get_y() const;

	//���������� ���� ����� ���������
	friend double angle(const myvector &v1, const myvector &v2);
	//���������� ���������� ������������ ��������
	friend double vect_prod(const myvector& v1,const myvector& v2);
	friend ostream& operator<<(ostream& out,const myvector& v);

	//���������
	void draw();

	void mymenu();

private:
	//���������� �������
	double x_, y_;
	//���������� ���������� �������
	void set_coord(double x, double y);
};

