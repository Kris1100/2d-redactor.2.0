#pragma once
#include "segment.h"
class myvector:public segment
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
private:
	//���������� �������
	double x_, y_;
};

