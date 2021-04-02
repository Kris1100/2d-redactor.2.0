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
	bool is_equilateral();
	//����������� ��������������
	bool is_isosceles();
	//����������� �������������
	bool is_right();
	//����������, ���������� �� �����������
	bool exists();
	//������ ��������� ����������
	double radius_inside();
	//������ ��������� ����������
	double radius_outside();
};