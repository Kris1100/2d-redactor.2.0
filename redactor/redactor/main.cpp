#pragma once
#include "Menu.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetColor(1, 15);

	print_menu(0, 1);
	return invalid();
	system("pause");
	return 0;
}