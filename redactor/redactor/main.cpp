#pragma once
#include "Menu.h"
#include "our_glut.h"
int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Work example");
	glutDisplayFunc(Display);
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetColor(1, 15);

	main_pr(argc,argv);
	int item = 0;
	print_menu(0, 1);
	while (true)
	{
		int key = _getch();
		if (key == 13)
		{
			switch (item)
			{
			case 0: return 0;
			case 1: print_point(0);  break;
			case 2: print_line(0);  break;
			case 3: print_circle(0); break;
			case 4: print_triangle(0);  break;
			case 5: print_polygon(0);  break;
			case 6: print_segment(0);  break;
			case 7: print_vector(0);  break;

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
			}
			print_menu(item, 15);
			if (item < 0)
				item = 7;
			if (item > 7)
				item = 0;
		}
	}
	system("pause");
	return 0;*/
}