#pragma once
#include <iostream>
#include <cmath>
#include "line.h"
#include "ray.h"
#include "segment.h"
#include "Triangle.h"
#include "polygon.h"
#include "circle.h"
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
	//����������� �� ����� ������, �������, ����, ������������, ��������������
	bool is_elem_line(line& l) const;
	bool is_elem_segment(const segment& s) const;
	bool is_elem_ray(const ray& r) const;
	bool is_elem_triangle(const triangle& abc) const;
	bool is_elem_polygon(const polygon& abz) const;
	bool is_elem_circle(const circle& w) const;

	//���������� ���������� ���������, ������, ������
	friend bool operator==(const point& p1, const point& p2);
	friend bool operator!=(const point& p1, const point& p2);
	friend istream& operator>>(istream& in, point& p);
	friend ostream& operator<<(ostream& out, const point& p);

private:
	double _x, _y;
};