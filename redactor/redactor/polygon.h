#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include"vector.h"
using namespace std;

class polygon
{
public:
	//����������� ��������������            //�������, ��� ����� ����������� ������������ ������
	polygon(int num_vert = 3);
	//���� �������������� 
	friend std::istream& operator>>(std::istream& in, polygon& p);      //std ����� �����?
	//����� ���� ���������� �� ��������������
	friend std::ostream& operator<<(std::ostream& out, polygon& p);
	//�������� ���������� �����
	int get_num() const;
	//��������� ��������
	double perimetr() const; //��������, ����� ������������� �� calc_perimetr
	//��������� �������
	double area() const;
	//������� ���������� �����
	void print() const;
	//�������� �� ����������
	bool is_convex() const;
	//�������� �� ������������
	bool is_regular(bool convexity) const;
	//����������
	~polygon();

protected:
	int num_vert_;
	point* vertex;
private:
	//���������� ���������� �����
	void set_num(int num_vert);
	//������ ������ �����
	void set_point_array(point* vert);
};