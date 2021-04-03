#pragma once
#include <iostream>
#include "point.h"
#include "polygon.h"
#include "main.h"
#include "segment.h"
using namespace std;

class triangle : public polygon
{
public:
	//����������� ������������
	triangle();
	//�������������, set
	void init();
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
};