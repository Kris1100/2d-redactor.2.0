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
	void define_kind();                                                        // ���������� ��� ������������
	bool exists();                                                             // ����������, ���������� �� �����������
	double square();
	double perimetr();
	double radius_inside();                                                    // ������ ��������� ����������
	double radius_outside();                                                   // ������ ��������� ����������
	
private:
	vector<point> abc_apexes;
};