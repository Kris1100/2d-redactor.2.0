#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T info;
	Node <T>* next = NULL;
	Node<T>* prev = NULL;
};
template <typename T>class bidir_list
{
public:
	//��������� �� ������ � ����� ������
	Node<T>* g = NULL;
	Node<T>* hv = NULL;
	//����� ������
	long long int ln = 0;
	bidir_list() {};
	//����������
	~bidir_list() {
		Node<T>* cur;
		while (ln > 0) {
			cur = get_first();
			delete cur;
		}
	};
	//�������� ������� � ����� ������
	void add_last(T x) {
		//������� ������ ����������
		Node<T>* elem = new Node<T>;//�������� ����������� ���������
		elem->info = x;
		elem->next = NULL;
		elem->prev = hv;
		//���� ������ �� ������,�� ������������ ����� ������� � ������
		if (ln > 0) {
			hv->next = elem;
			hv = elem;
		}
		//����� ������������� ��� ��������� �� �������
		else {
			g = elem;
			hv = elem;
		}
		ln++;
	}
	//�������� ������� � ������ ������
	void add_first(long long int x) {
		Node<T>* elem = new Node;
		//�������� ������, ��������� ��� � ������
		elem->info = x;
		elem->next = g;
		elem->prev = NULL;
		if (ln > 0) {
			g->prev = elem;
			g = elem;
		}
		else {
			g = elem;
			hv = g;
		}
		ln++;
	}
	//������� ������ �������
	Node<T>* get_first() {
		//���� ������ ���� ������ NULL
		if (ln == 0) return NULL;
		else {
			//�������� ������, ��������� � ���� ������ ���������� ��������
			Node<T>* elem = new Node<T>;
			elem->info = g->info;
			elem->next = NULL; elem->prev = NULL;
			Node<T>* p;
			//��������� ��������� �� ������, � ������ ������� ������
			p = g;
			g = g->next;
			ln--;
			//���� ������ ��� ���������� �������� ���� ������ �� ����� � ������ NULL
			if (ln == 0) hv = g = NULL;
			//����� ���������� ������� � ������� ���� NULL
			else g->prev = NULL;
			delete p;
			return elem;
		}
	}
	//�������� ��������� ������� ���������� ��������� �������
	Node<T>* get_last() {
		if (ln == 0) return NULL;
		else {
			Node<T>* elem = new Node<T>;
			elem->info = hv->info;
			elem->next = NULL; elem->prev = NULL;
			Node<T>* p = hv;
			hv = p->prev;
			ln--;
			if (ln == 0) g = hv = NULL;
			else hv->next = NULL;
			delete p;
			return elem;
		}
	}
};

