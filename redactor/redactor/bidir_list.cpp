//#include "bidir_list.h"
//
//template <class T>
//bidir_list<T>::bidir_list(size_t size_)
//{
//	if (size_ == 0)
//		return;
//	for (int i = 0; i < size_; i++)
//	{
//		add_last(0);
//	}
//	size = size_;
//}
//
//template <class T>
//bidir_list<T>::~bidir_list()
//{
//	Node<T>* cur = NULL;
//	while (size > 0)
//	{
//		cur = get_first();
//		delete cur;
//	}
//}
//
//template <class T>
//void bidir_list<T>::add_last(const T x)
//{
//	//������� ������ ����������
//	Node<T>* elem = new Node<T>;//�������� ����������� ���������
//	elem->info = x;
//	elem->next = NULL;
//	elem->prev = tail;
//	//���� ������ �� ������, �� ������������ ����� ������� � ������
//	if (size > 0)
//	{
//		tail->next = elem;
//		tail = elem;
//	}
//	//����� ������������� ��� ��������� �� �������
//	else
//	{
//		head = elem;
//		tail = elem;
//	}
//	size++;
//}
//
//template <class T>
//void bidir_list<T>::add_first(const T x)
//{
//	Node<T>* elem = new Node;
//	//�������� ������
//	elem->info = x;
//	elem->next = head;
//	elem->prev = NULL;
//	//���� ������ �� ������, �� ������������ ����� ������� � ������
//	if (size > 0)
//	{
//		head->prev = elem;
//		head = elem;
//	}
//	//����� ������������� ��� ��������� �� �������
//	else
//	{
//		head = elem;
//		tail = head;
//	}
//	size++;
//}
//
//template <class T>
//Node<T>* bidir_list<T>::get_first()
//{
//	//���� ������ ���� ������ NULL
//	if (size == 0)
//		return NULL;
//	else
//	{
//		//�������� ������, ��������� � ���� ������ ���������� ��������
//		Node<T>* elem = new Node<T>;
//		elem->info = head->info;
//		elem->next = NULL;
//		elem->prev = NULL;
//		//��������� ��������� �� ������, � ������ ������� ������
//		Node<T>* p = head;
//		head = head->next;
//		size--;
//		//���� ������ ��� ���������� �������� ���� ������ �� ����� � ������ NULL
//		if (size == 0)
//			tail = head = NULL;
//		//����� ���������� ������� � ������� ���� NULL
//		else
//			head->prev = NULL;
//		delete p;
//		return elem;
//	}
//}
//
//template <class T>
//Node<T>* bidir_list<T>::get_last()
//{
//	if (size == 0)
//		return NULL;
//	else
//	{
//		Node<T>* elem = new Node<T>;
//		elem->info = tail->info;
//		elem->next = NULL;
//		elem->prev = NULL;
//		Node<T>* p = tail;
//		tail = p->prev;
//		size--;
//		if (size == 0)
//			head = tail = NULL;
//		else
//			tail->next = NULL;
//		delete p;
//		return elem;
//	}
//}