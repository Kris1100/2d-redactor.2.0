#pragma once
#include <iostream>
#include "point.h"
#include "line.h"

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

<<<<<<< HEAD
	//����������� �� ��� ������
	bool is_elem_line(line& l) const;
=======
	bool is_element(const point& t) const;
>>>>>>> 6e2314bef907c45c389be0c4b4753a8f3afd65e7

private:
	//������� ������ ���� � �����-�� ����� �� ����
	void set_begin(const point& begin) { _begin = begin; }
	void set_p(const point& p) { _p = p; }

	point _begin;
	point _p;
};

