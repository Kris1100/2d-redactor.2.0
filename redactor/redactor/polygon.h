#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "vector.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class polygon : public figure
{
public:
	//����������� ��������������. �� ��������� ��������� ���������� n-��������          
	polygon(size_t num_vert = 3);
	//����������� �����������
	polygon(const polygon& t);
	//����������
	~polygon();

	//�������� ���������� �����
	size_t get_num() const { return num_vert_; }
	//�������� ��������� �� ������ ����� ��������������
	point* get_vertexes() const { return vertex; }

	//��������� ��������
	double perimetr() const;
	//��������� �������
	double area() const;
	//�������� �������������� �� �������������(������������ �����)
	bool is_correct() const;
	//������� ���������� �����
	void print() const;
	//�������� �� ����������
	bool is_convex() const;
	//�������� �� ������������
	bool is_regular(bool convexity) const;

	//��������� ��������������
	void draw();
	
	//���� �������������� 
	friend std::istream& operator>>(std::istream& in, polygon& p);
	//����� ���� ���������� �� ��������������
	friend std::ostream& operator<<(std::ostream& out, polygon& p);

	void mymenu();

protected:
	size_t num_vert_ = 0;
	point* vertex = nullptr;

private:
	//���������� ���������� �����
	void set_num(size_t num_vert);
	//������ ������ �����(�� ��������� ������ ����� ����������� num_vert-���������)
	void set_point_array(point* vert);
};