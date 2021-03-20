#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"point.h"
#include"polygon.h"
using namespace std;

class triangle : public polygon
{
public:
	//����������� ������������
	triangle();
	//���������� ������������
	~triangle();
	//���� ������������
	friend istream& operator>>(istream& in, triangle& abc);
	//���������� ��� ������������
	void define_kind();
	//����������, ���������� �� �����������
	bool exists();
	//������ ��������� ����������
	double radius_inside();
	//������ ��������� ����������
	double radius_outside();
	
private:
	bool was_checked_existence = false;
};