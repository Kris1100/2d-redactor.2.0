#pragma once
#include <iostream>
#include "main.h"
class ray
{
public:
	//�����������
	ray(const point& begin, const point& p);
	//����������
	~ray() { }

	//�������� ����� ������ ���� � ����� �� ����
	point get_begin() const { return _begin; }
	point get_p() const { return _p; }

private:
	//������� ������ ���� � �����-�� ����� �� ����
	void set_begin(const point& begin) { _begin = begin; }
	void set_p(const point& p) { _p = p; }

	point _begin;
	point _p;
};

