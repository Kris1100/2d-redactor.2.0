#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T info;
	Node<T>* next = NULL;
	Node<T>* prev = NULL;
	//Node()//need to test
	//{
	//	return new Node<T>;
	//}
};

template <class T>
class bidir_list
{
public:
	////
	//bidir_list() { }
	////
	//bidir_list(size_t size_);
	////Деструктор
	//~bidir_list();
	////Добавить элемент в конец списка
	//void add_last(const T x);
	////Добавить элемент в начало списка
	//void add_first(const T x);
	////Извлечь первый элемент
	//Node<T>* get_first(); //const?
	////Получить последний элемент аналогично получению первого
	//Node<T>* get_last(); //const?
	//Конструктор
	bidir_list() { }
	//Конструктор по количеству элементов
	bidir_list(size_t size_)
	{
		if (size_ == 0)
			return;
		for (int i = 0; i < size_; i++)
		{
			add_last(0);
		}
		size = size_;
	}
	//Деструктор
	~bidir_list()
	{
		Node<T>* cur = NULL;
		while (size > 0)
		{
			cur = get_first();
			delete cur;
		}
	}
	//Добавить элемент в конец списка
	void add_last(const T x)
	{
		//Создаем объект добавления
		Node<T>* elem = new Node<T>;//Добавить конструктор струкруты
		elem->info = x;
		elem->next = NULL;
		elem->prev = tail;
		//Если список не пустой, то прикриепляем новый элемент к хвосту
		if (size > 0)
		{
			tail->next = elem;
			tail = elem;
		}
		//Иначе устанавливаем все указатели на элемент
		else
		{
			head = elem;
			tail = elem;
		}
		size++;
	}
	//Добавить элемент в начало списка
	void add_first(const T x)
	{
		Node<T>* elem = new Node;
		//Создадим объект
		elem->info = x;
		elem->next = head;
		elem->prev = NULL;
		//Если список не пустой, то прикриепляем новый элемент к голове
		if (size > 0)
		{
			head->prev = elem;
			head = elem;
		}
		//Иначе устанавливаем все указатели на элемент
		else
		{
			head = elem;
			tail = head;
		}
		size++;
	}
	//Извлечь первый элемент
	Node<T>* get_first()
	{
		//Если список пуст вернем NULL
		if (size == 0)
			return NULL;
		else
		{
			//Создадим объект, скопируем в него данные удаляемого элемента
			Node<T>* elem = new Node<T>;
			elem->info = head->info;
			elem->next = NULL;
			elem->prev = NULL;
			//Установим указатель на голову, а голову сместим вправо
			Node<T>* p = head;
			head = head->next;
			size--;
			//Если список без удаляемого элемента стал пустым то хвост и голова NULL
			if (size == 0)
				tail = head = NULL;
			//Иначе предыдущий элемент у первого узла NULL
			else
				head->prev = NULL;
			delete p;
			return elem;
		}
	}
	//Получить последний элемент аналогично получению первого
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
	//Получить размер списка
	size_t get_size() const { return size; }
	//Получить указатель на первый элемент
	Node<T>* get_head() const { return head; }
	//Получить указатель на последний жлемент
	Node<T>* get_tail() const { return tail; }
	
private:
	//указатели на начало и конец списка
	Node<T>* head = NULL;
	Node<T>* tail = NULL;
	//длина списка
	size_t size = 0;
};

