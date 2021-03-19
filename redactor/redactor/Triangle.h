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
	triangle();                                                                // �����������
	~triangle();
	friend istream& operator>>(istream& in, triangle& abc);                    // ����
	void define_kind();                                                        // ���������� ��� ������������
	bool exists();                                                             // ����������, ���������� �� �����������
	double square();                                                           // ������� �� ������
	double abc_perimetr();                                                     // ��������
	double radius_inside();                                                    // ������ ��������� ����������
	double radius_outside();                                                   // ������ ��������� ����������
	
private:
	point* abc_apexes;
};