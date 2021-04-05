#pragma once
#include <iostream>
#include "point.h"
#include "polygon.h"
#include "segment.h"
#include "line.h"
using namespace std;

class triangle : public polygon
{
public:
	//����������� ������������
	triangle();
	//���������� ������������                //���������� �����������, �� ������ ���� ����������� � ������������ ������
	//~triangle();

	//����������� ��������������
	bool is_equilateral() const;
	//����������� ��������������
	bool is_isosceles() const;
	//����������� �������������
	bool is_right() const;
	//����������, ���������� �� �����������
	bool exists() const;
	//������ ��������� ����������
	double radius_inside() const;
	//������ ��������� ����������
	double radius_outside() const;
	//����� �� ����� ������ ������������ (������)
	bool is_inside(const point& p) const;
	//���������� ��������� �����
	friend ifstream& operator>>(ifstream& in, triangle& abc);//�������, ��� ��� ���� � ������������ ������
	//������� ������� ����� ������������ � �������� ��������
	segment middle_line(const segment& ab, const segment& bc);
	//�������� �������-������� ������������
	segment get_ab() const { return segment(vertex[0], vertex[1]); }
	segment get_bc() const { return segment(vertex[1], vertex[2]); }
	segment get_ac() const { return segment(vertex[0], vertex[2]); }

private:
	void set_vertex(const point& a, const point& b, const point& c);
};