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
//	//Создаем объект добавления
//	Node<T>* elem = new Node<T>;//Добавить конструктор струкруты
//	elem->info = x;
//	elem->next = NULL;
//	elem->prev = tail;
//	//Если список не пустой, то прикриепляем новый элемент к хвосту
//	if (size > 0)
//	{
//		tail->next = elem;
//		tail = elem;
//	}
//	//Иначе устанавливаем все указатели на элемент
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
//	//Создадим объект
//	elem->info = x;
//	elem->next = head;
//	elem->prev = NULL;
//	//Если список не пустой, то прикриепляем новый элемент к голове
//	if (size > 0)
//	{
//		head->prev = elem;
//		head = elem;
//	}
//	//Иначе устанавливаем все указатели на элемент
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
//	//Если список пуст вернем NULL
//	if (size == 0)
//		return NULL;
//	else
//	{
//		//Создадим объект, скопируем в него данные удаляемого элемента
//		Node<T>* elem = new Node<T>;
//		elem->info = head->info;
//		elem->next = NULL;
//		elem->prev = NULL;
//		//Установим указатель на голову, а голову сместим вправо
//		Node<T>* p = head;
//		head = head->next;
//		size--;
//		//Если список без удаляемого элемента стал пустым то хвост и голова NULL
//		if (size == 0)
//			tail = head = NULL;
//		//Иначе предыдущий элемент у первого узла NULL
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