#pragma once
#include "segment.h"
#include <cmath>

class myvector: public segment
{
public:
	//�����������                      
	myvector( const point& begin, const point& end);
	//����������� �� ����������� ������� (������ ������������� � ������ ���������� ������� ��������� (0,0))
	myvector(double a = 1, double b = 1);
	//�������� x ����������
	double get_x() const;
	//�������� y ����������
	double get_y() const;
	//����������
	~myvector() {}
	//���������� ���� ����� ���������
	friend double angle(const myvector &v1, const myvector &v2);
	//���������� ���������� ������������ ��������
	friend double vect_prod(const myvector& v1,const myvector& v2);
	friend ostream& operator<<(ostream& out,const myvector& v);
private:
	//���������� �������
	double x_, y_;
	//���������� ���������� �������
	void set_coord(double x, double y);
};

