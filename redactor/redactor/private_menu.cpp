#include "private_menu.h"

void print_inmenu(int num, int col, vector<string>& commands)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int col2;
	if (col == 1)
		col2 = 7;
	else
		col2 = 1;
	system("cls");
	SetColor(15, 1);
	cout << "\n";
	SetColor(1, 15);
	if (num < 0)
		num = commands.size() + 1;
	if (num > commands.size() + 1)
		num = 0;
	if (num == 0)
	{
		SetColor(col, col2);
		cout << "    0) Выход\n";
		SetColor(1, 15);
	}
	else
		cout << "    0) Выход\n";
	for (int i = 0; i < commands.size(); i++)
	{
		if (num == i + 1)
		{
			SetColor(col, col2);
			cout << "    " << i + 1 << ") " << commands[i] << endl;
			SetColor(1, 15);
		}
		else
			cout << "    " << i + 1 << ") " << commands[i] << endl;
	}
}
void roll_back_draw() {
	Node<figure*>* p;
	p = queue.get_last();
	delete p;
	Node<elem>* t;
	t = all.get_last();
	delete t;
}