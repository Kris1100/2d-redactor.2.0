#include "segment.h"

segment::segment(const point& p1,const point& p2) 
{
	set_extm_points(p1, p2);
	is_correct();
}

segment::segment(const segment& s) 
{
	p1_ = s.get_start();
	p2_ = s.get_end();
	is_drawn = s.is_drawn;
}

segment::~segment()
{
	p1_.~point();
	p2_.~point();
	is_drawn = false;
}

void segment::is_correct()
{
	//Отлавливаем ошибку на две одинаковые точки
	try
	{
		if (p1_ == p2_)
			throw "Обе точки отрезка совпадают, будет установлено значение по умолчанию (0,0) и (1,1)";
	}
	catch (const char* err)
	{
		cout << "Ошибка: " << err << endl;
		//В случае ошибки задаем значение по умолчанию
		point d1(0, 0);
		point d2(1, 1);
		set_extm_points(d1, d2);
	}
}

void segment::set_extm_points(const point& p1, const point& p2)
{
	p1_ = p1;
	p2_ = p2;
}

double segment::len() const
{
	return round(sqrt( ((p1_.get_x() - p2_.get_x()) * (p1_.get_x() - p2_.get_x()))
			   + ((p1_.get_y() - p2_.get_y()) * (p1_.get_y() - p2_.get_y())) )*constants::rd)/constants::rd;
}

point segment::middle() const
{
	double x = (p1_.get_x() + p2_.get_x()) / 2;
	double y = (p1_.get_y() + p2_.get_y()) / 2;
	return point(x, y);
}

void segment::draw()
{
	glLineWidth(constants::line_width);
	glBegin(GL_LINES);
	glColor3ub(255, 203, 219);
	glVertex2f(p1_.centerize().get_x(), p1_.centerize().get_y());
	glColor3ub(255, 107, 142);
	glVertex2f(p2_.centerize().get_x(), p2_.centerize().get_y());
	glEnd();
}
 
bool segment::point_lay(const point& p) const {
	segment ap(p1_, p);
	segment pb(p, p2_);
	if (ap.len() + pb.len() == len()) return true;
	else return false;
}

istream& operator>>(istream& in, segment& s)
{
	cout << "Введите координаты первой точки:" << endl;
	cin >> s.p1_;
	cout << "Введите координаты второй точки:" << endl;
	cin >> s.p2_;
	s.is_correct();
	return in;
}

void segment::mymenu()
{
	ifstream in("segment.txt");
	vector<string> commands;
	while (in)
	{
		string s = "";
		getline(in, s, '\n');
		commands.push_back(s);
	}
	if (commands[commands.size() - 1] == "" || commands[commands.size() - 1] == "\n")
		commands.pop_back();
	SetColor(1, 15);
	int item = 0;
	print_inmenu(0, 1, commands);
	if (not this->is_created)
	{
		cin >> *this;
		this->is_created = true;
	}
	while (true)
	{
		int key = _getch();

		if (key == 13)
		{
			switch (item)
			{
			case 0:
			{
				in.close();
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1: cin >> *this; break;
			case 2:
			{
				cout << "Длина отрезка: " << len() << endl;
			}
			break;
			case 3:
			{
				if (not this->is_drawn)
				{
					add_draw(*this);
					cout << "Объект успешно добавлен в очередь на отрисовку, вы увидите его, когда завершите работу";
					this->is_drawn = true;
				}
				else
				{
					cout << "Объект уже в очереди на отрисовку";
				}
			}
			break;
			case 4:
			{
				if (this->is_drawn)
				{
					roll_back_draw();
					this->is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else
					cout << "Вы еще не нарисовали объект";
			}
			break;
			case 5:
			{
				roll_back_create();
				cout << "Объект успешно удален,перейдите в главное меню";
				return;
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}