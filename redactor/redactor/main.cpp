#pragma once
#include "Menu.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetColor(1, 15);

	int item = 0;
	print_menu(0, 1);
	while (true)
	{
		int key = _getch();

		if (key == 13)
		{
			switch (item)
			{
			case 0: { queue.~bidir_list(); return 0; }
			case 1: main_pr(); break;
			case 2: print_point(0);  break;
			case 3: print_line(0);  break;
			case 4: print_circle(0); break;
			case 5: print_triangle(0);  break;
			case 6: print_polygon(0);  break;
			case 7: print_segment(0);  break;
			case 8: print_vector(0);  break;
			case 9: print_ray(0); break;
			case 10:
			{
				if (all.get_tail() != NULL) all.get_tail()->info.obj->mymenu();
				else cout << "�� ��� ������ �� ������";
			}
			break;
			default:
				break;
			}
		}
		else
		{
			switch (key)
			{
			case 72: item--;  break;
			case 80: item++;  break;
			case 48: item = 0;  break;
			case 49: item = 1;  break;
			case 50: item = 2;  break;
			case 51: item = 3;  break;
			case 52: item = 4;  break;
			case 53: item = 5;  break;
			case 54: item = 6;  break;
			case 55: item = 7;  break;
			case 56: item = 8; break;
			case 57: item = 9; break;
			case 58: item = 10; break;
			}
			print_menu(item, 15);
			if (item < 0)
				item = 10;
			if (item > 10)
				item = 0;
		}
	}
	system("pause");
	return 0;
}