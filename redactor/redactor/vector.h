#pragma once
#include "segment.h"
class vector:public segment
{
public:
	//�����������
	vector(point& begin,point& end);
	//���������� ���������� �������
	void set_coord(double x, double y);
private:
	//���������� �������
	double x_, y_;
};

