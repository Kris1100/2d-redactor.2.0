#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//�����������                      
	myvector(point& begin,point& end);
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

private:
	//���������� �������
	double x_, y_;
	//���������� ���������� �������
	void set_coord(double x, double y);
};

