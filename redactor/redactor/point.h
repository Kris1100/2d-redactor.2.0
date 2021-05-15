#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class point
{
public:
	//����������� �����
	point(double x = 0, double y = 0);

	//������ ���������� �
	void set_x(double x) { _x = x; }
	//������ ���������� �
	void set_y(double y) { _y = y; }

	//�������� ���������� �
	double get_y() const { return _y; }
	//�������� ���������� �
	double get_x() const { return _x; }

	//���������� # ��������, ����� ������ �����, 0 - � ������, ���� ����� ����������� ������ ���������
	int quarter();
	//���������� ���������� �� ������ ���������
	double dist();
	//����� �� ����� �� ����������� ������������ ���������
	bool bisector();

	//���������� ���������� ���������, ������, ������,������������
	friend bool operator==(const point& p1, const point& p2);
	friend bool operator!=(const point& p1, const point& p2);
	friend istream& operator>>(istream& in, point& p);
	friend ostream& operator<<(ostream& out, const point& p);
	point& operator=(const point& p);
private:
	double _x, _y;
};