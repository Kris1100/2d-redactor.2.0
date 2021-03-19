#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//�����������
	myvector(point& begin,point& end);
	//���������� ���������� �������
	void set_coord(double x, double y);
	//�������� x ����������
	double get_x();
	//�������� y ����������
	double get_y();
	//����������
	~myvector();
	//���������� ���� ����� ���������
	friend double angel(myvector &v1,myvector &v2);
	//���������� ���������� ������������ ��������
	friend double vect_prod(myvector& v1, myvector& v2);

private:
	//���������� �������
	double x_, y_;
};

