#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T info;
	Node<T>* next = NULL;
	Node<T>* prev = NULL;
};

template <class T>
class bidir_list
{
public:
	//�����������
	bidir_list() { }
	//����������
	~bidir_list()
	{
		Node<T>* cur = NULL;
		while (size > 0)
		{
			cur = get_first();
			delete cur;
		}
	}
	//�������� ������� � ����� ������
	void add_last(const T x)
	{
		//������� ������ ����������
		Node<T>* elem = new Node<T>;//�������� ����������� ���������
		elem->info = x;
		elem->next = NULL;
		elem->prev = tail;
		//���� ������ �� ������, �� ������������ ����� ������� � ������
		if (size > 0)
		{
			tail->next = elem;
			tail = elem;
		}
		//����� ������������� ��� ��������� �� �������
		else
		{
			head = elem;
			tail = elem;
		}
		size++;
	}
	//�������� ������� � ������ ������
	void add_first(const T x)
	{
		Node<T>* elem = new Node;
		//�������� ������
		elem->info = x;
		elem->next = head;
		elem->prev = NULL;
		//���� ������ �� ������, �� ������������ ����� ������� � ������
		if (size > 0)
		{
			head->prev = elem;
			head = elem;
		}
		//����� ������������� ��� ��������� �� �������
		else
		{
			head = elem;
			tail = head;
		}
		size++;
	}
	//������� ������ �������
	Node<T>* get_first()
	{
		//���� ������ ���� ������ NULL
		if (size == 0)
			return NULL;
		else
		{
			//�������� ������, ��������� � ���� ������ ���������� ��������
			Node<T>* elem = new Node<T>;
			elem->info = head->info;
			elem->next = NULL;
			elem->prev = NULL;
			//��������� ��������� �� ������, � ������ ������� ������
			Node<T>* p = head;
			head = head->next;
			size--;
			//���� ������ ��� ���������� �������� ���� ������ �� ����� � ������ NULL
			if (size == 0)
				tail = head = NULL;
			//����� ���������� ������� � ������� ���� NULL
			else
				head->prev = NULL;
			delete p;
			return elem;
		}
	}
	//�������� ��������� ������� ���������� ��������� �������
	Node<T>* get_last()
	{
		if (size == 0)
			return NULL;
		else
		{
			Node<T>* elem = new Node<T>;
			elem->info = tail->info;
			elem->next = NULL;
			elem->prev = NULL;
			Node<T>* p = tail;
			tail = p->prev;
			size--;
			if (size == 0)
				head = tail = NULL;
			else
				tail->next = NULL;
			delete p;
			return elem;
		}
	}
	//������� ������� �� ����� ������
	T pop_back()
	{
		if (size == 0)
			throw "List is empty";
		T element = tail->info;
		Node<T>* tmp = tail;
		if (size == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		delete tmp;
		size--;
		return element;
	}
	//������� ������� �� ������ ������
	T pop_front()
	{
		if (size == 0)
			throw "List is empty";
		T element = head->info;
		Node<T>* tmp = head;
		if (size == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		delete tmp;
		size--;
		return element;
	}

	//�������� ������ ������
	size_t get_size() const { return size; }
	//�������� ��������� �� ������ �������
	Node<T>* get_head() const { return head; }
	//�������� ��������� �� ��������� �������
	Node<T>* get_tail() const { return tail; }
	
private:
	//��������� �� ������ � ����� ������
	Node<T>* head = NULL;
	Node<T>* tail = NULL;
	//����� ������
	size_t size = 0;
};

