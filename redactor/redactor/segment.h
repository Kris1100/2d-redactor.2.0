#pragma once
#include "point.h"
#include <cmath>
#include <math.h>
#include <cassert>
#include "Figure.h"
using namespace std;
//����� �������
class segment : public figure
{
public:
	//����������� �������
	segment(const point& p1, const point& p2);
	//����������� �� ��������� ��������� ��� ������ vector
	segment() {};
	//����������� �����������
	segment(const segment& s);
	//����������
	~segment() {}
	//�������� ������ �� ��������� ����� (��������� - p1_, � ������ ����� ��� �������, ����� ����� ���������)
	point get_start() const {  
		return p1_;
	}
	//������ �� �������� �����
	point get_end() const {
		return p2_;
	}
	//������ ������� �����
	void set_extm_points(const point& p1,const point& p2);
	//����� �������
	double len() const;
	//���������� �������� �������
	point middle() const;
	void is_correct();

	//���������� �������
	void draw();
	void mymenu();

	//����� �������
	//��������� �����
	friend std::istream& operator>>(std::istream& in, segment& s);
protected:
	point p1_;
	point p2_;
};

