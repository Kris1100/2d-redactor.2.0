#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//�����������                      
	myvector(point& begin,point& end);
	//����������� �� ����������� ������� (������ ������������� � ������ ���������� ������� ��������� (0,0))
	myvector(double a = 1, double b = 1);
	//�������� x ����������
	double get_x() const;
	//�������� y ����������
	double get_y() const;
	//����������
	~myvector() {}
	//���������� ���� ����� ���������
	friend double angle(myvector &v1,myvector &v2);
	//���������� ���������� ������������ ��������
	friend double vect_prod(myvector& v1, myvector& v2);
	friend ostream& operator<<(ostream& out, myvector& v);
private:
	//���������� �������
	double x_, y_;
	//���������� ���������� �������
	void set_coord(double x, double y);
};

