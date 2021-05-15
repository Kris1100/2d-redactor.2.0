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
	//указатели на начало и конец списка
	Node<T>* g = NULL;
	Node<T>* hv = NULL;
	//длина списка
	long long int ln = 0;
	bidir_list() {};
	//Деструктор
	~bidir_list() {
		Node<T>* cur;
		while (ln > 0) {
			cur = get_first();
			delete cur;
		}
	};
	//Добавить элемент в конец списка
	void add_last(T x) {
		//Создаем объект добавления
		Node<T>* elem = new Node<T>;//Добавить конструктор струкруты
		elem->info = x;
		elem->next = NULL;
		elem->prev = hv;
		//Если список не пустой,то прикриепляем новый элемент к хвосту
		if (ln > 0) {
			hv->next = elem;
			hv = elem;
		}
		//Иначе устанавливаем все указатели на элемент
		else {
			g = elem;
			hv = elem;
		}
		ln++;
	}
	//Добавить элемент в начало списка
	void add_first(long long int x) {
		Node<T>* elem = new Node;
		//Создадим объект, прикрепим его к голове
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
	//Извлечь первый элемент
	Node<T>* get_first() {
		//Если список пуст вернем NULL
		if (ln == 0) return NULL;
		else {
			//Создадим объект, скопируем в него данные удаляемого элемента
			Node<T>* elem = new Node<T>;
			elem->info = g->info;
			elem->next = NULL; elem->prev = NULL;
			Node<T>* p;
			//Установим указатель на голову, а голову сместим вправо
			p = g;
			g = g->next;
			ln--;
			//Если список без удаляемого элемента стал пустым то хвост и голова NULL
			if (ln == 0) hv = g = NULL;
			//Иначе предыдущий элемент у первого узла NULL
			else g->prev = NULL;
			delete p;
			return elem;
		}
	}
	//Получить последний элемент аналогично получению первого
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

