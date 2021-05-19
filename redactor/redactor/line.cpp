#include "line.h"
#include "Menu.h";
line::line(const point& p1, const point& p2)
{
	_p1 = point(p1.get_x(), p1.get_y());
	_p2 = point(p2.get_x(), p2.get_y());
}

line::line(double a, double b, double c)
{
	set_a(a);
	set_b(b);
	set_c(c);
}

line::line(const line& l) 
{
	_p1 = l.get_first();
	_p2 = l.get_second();
	is_drawn = l.is_drawn;
}

line::~line()
{
	_p1.~point();
	_p2.~point();
	is_drawn = false;
}

void line::print_all(double& a,double& b,double& c)
{
	if (a != 0 && a != 1 && a != -1)
		cout << a << 'x';
	else if (a == 1)
		cout << 'x';
	else if (a == -1)
		cout << '-x';

	if (b < 0 && b != -1)
		cout << b << 'y';
	else if (b == -1)
		cout << '-' << 'y';
	else if (b > 0 && b != 1 && a != 0)
		cout << '+' << b << 'y';
	else if (b == 1 && a != 0)
		cout << '+' << 'y';
	else if (b > 0 && b != 1)
		cout << b << 'y';
	else if (b == 1)
		cout << 'y';

	if (c < 0)
		cout << c;
	else if (c > 0)
		cout << '+' << c;
	cout << '=' << 0 << endl;
}

void line::print_v1()
{
	double a, b, c;
	coef(a, b, c);
	print_all(a, b, c);
}

void line::print_v2()
{
	coef(_a, _b, _c);
	double a = _a, b = _b, c = _c;
	print_all(a, b, c);
}

void line::print_param()
{
	double a, b, c;
	coef(a, b, c);
	myvector v = guide_vector();
	cout << "Параметрическое уравнение" << endl;

	cout << 'x' << '=' << _p1.get_x();
	if (v.get_x() < 0)
		cout << v.get_x() << 't' << endl;
	else if (v.get_x() > 0)
		cout << '+' << v.get_x() << endl;

	cout << 'y' << '=' << _p1.get_y();
	if (v.get_y() < 0)
		cout << v.get_y() << 't' << endl;
	else if(v.get_y() > 0)
		cout << '+' << v.get_y() << endl;
}

myvector line::normal_vector()
{
	double a, b, c;
	coef(a, b, c);
	return myvector(a, b);
}

myvector line::guide_vector()
{
	double a, b, c;
	coef(a, b, c);
	point p1(0, 0), p2(b, -a);
	return myvector(p1, p2);
}

void line::coef(double& a, double& b, double& c)
{
	a = _p2.get_y() - _p1.get_y();
	b = _p1.get_x() - _p2.get_x();
	c = _p1.get_y() * (_p2.get_x() - _p1.get_x()) + _p1.get_x() * (_p1.get_y() - _p2.get_y());
}

line line::parallel(const point& p)
{
	double a, b, c;
	coef(a, b, c);
	double a1 = a;
	double b1 = b;
	double c1 = -(a * p.get_x() + b * p.get_y());
	return line(a1, b1, c1);
}

unsigned int line::is_increasing() const
{
	long long int res = (_p1.get_x() - _p2.get_x()) * (_p1.get_y() - _p2.get_y());
	//Если x и y изменяются обратнопропорционально, то убывает
	if (res < 0)
		return 0;
	//Если прямопропорционально, то возрастает
	if (res > 0)
		return 1;
	//Если x или y не меняется
	if (_p1.get_x() == _p2.get_x()) 
		return 2;
	if (_p1.get_y() == _p2.get_y()) 
		return 3;
}

//Перегрузка оператора ввода
istream& operator>>(istream& in, line& l) 
{
	cout << "Введите координаты первой точки:" << endl;
	cin >> l._p1;
	cout << "Введите координаты второй точки:" << endl;
	cin >> l._p2;
	return in;
}

figure& line:: operator=(line& l) 
{
	_p1 = l._p1;
	_p2 = l._p2;
	return *this;
}

void line::draw()
{
	double a, b, c;
	coef(a, b, c);
	double k = -1 * a / b;
	size_t w, h;
	w = constants::width;
	h = constants::height;
	int coef = max(w, h);
	int increase = this->is_increasing();
	if (increase == 0 || k < 0) //decreases
	{
		if (_p1.get_x() > _p2.get_x())
			swap(_p1, _p2);
		k = abs(k);
		double y1 = _p1.centerize().get_y();
		double x1 = _p1.centerize().get_x();
		double y11 = k * x1;
		double x1p, y1p, x2p, y2p;
		if (y1 + y11 <= h)
		{
			x1p = 0;
			y1p = y1 + y11;
		}
		else
		{
			y1p = h;
			x1p = (y1 + y11 - h) / k;
		}
		double y2 = _p2.centerize().get_y();
		double x2 = _p2.centerize().get_x();
		double x22 = y2 / k;
		if (x2 + x22 <= w)
		{
			x2p = x2 + x22;
			y2p = 0;
		}
		else
		{
			x2p = w;
			y2p = k * (x2 + x22 - w);
		}
		glLineWidth(2);
		glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(x1p, y1p);
		glColor3ub(205, 164, 222);
		glVertex2f(x2p, y2p);
		glEnd();
		return;
	}
	else if (increase == 1 || k > 0) //increases
	{
		if (_p1.get_x() > _p2.get_x())
			swap(_p1, _p2);
		k = abs(k);
		double y2 = _p2.centerize().get_y();
		double x2 = _p2.centerize().get_x();
		double y22 = k * (w - x2);
		double x1p, y1p, x2p, y2p;
		if (y2 + y22 <= h)
		{
			x2p = w;
			y2p = y2 + y22;
		}
		else
		{
			y2p = h;
			x2p = (y2 + y22 - h) / k;
		}
		double y1 = _p1.centerize().get_y();
		double x1 = _p1.centerize().get_x();
		double x11 = y1 / k;
		if (x1 - x11 > 0)
		{
			x1p = x1 - x11;
			y1p = 0;
		}
		else
		{
			x1p = 0;
			y1p = k * (x11 - x1);
		}
		glLineWidth(2);
		glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(x1p, y1p);
		glColor3ub(158, 90, 140);
		//glColor3ub(205, 164, 222);
		glVertex2f(x2p, y2p);
		glEnd();
		return;
	}
	else if (increase == 2) //x=a
	{
		glLineWidth(2);
		glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(_p1.centerize().get_x(), 0);
		glColor3ub(205, 164, 222);
		glVertex2f(_p2.centerize().get_x(), h);
		glEnd();
		return;
	}
	else if (increase == 3 || k == 0) //y=b
	{
		glLineWidth(2);
		glBegin(GL_LINES);
		glColor3ub(255, 255, 255);
		glVertex2f(0, _p1.centerize().get_y());
		glColor3ub(205, 164, 222);
		glVertex2f(w, _p2.centerize().get_y());
		glEnd();
		return;
	}
	//glColor3ub(255, 255, 255);
	//glVertex2i(_p1.centerize().get_x() - 2 * a, _p1.centerize().get_y() - 2 * b);
	//glColor3ub(205, 164, 222);
	//glVertex2i(_p2.centerize().get_x() + 2 * a, _p2.centerize().get_y() + 2 * b);
	//glEnd();
}

void line::mymenu() 
{
	ifstream in("line.txt");
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
	if (not this->is_created) {
		cin >> *this;
		add_create(*this);
	}
	point p3;
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
			case 1: {
				cin >> *this;
				roll_back_draw();
				add_draw(*this);
			}
				  break;
			case 2:
			{
				(this)->print_v1();
			}
			break;
			case 3:
			{
				this->print_param();
			}
			break;
			case 4:
			{
				myvector v1 = this->normal_vector();
				cout << "Координаты вектора нормали: " << v1;
			}
			break;
			case 5:
			{
				myvector v2 = this->guide_vector();
				cout << "Координаты направляющего вектора: " << v2;
			}
			break;
			case 6:
			{
				cout << "Введиите координаты точки, через которую нужно построить прямую, параллельную данной:" << endl;
				cin >> p3;
				line l2 = this->parallel(p3);
				cout << "Уравнение прямой, параллельной данной: ";
				l2.print_v2();//не работает, как надо
			}
			break;
			case 7:
			{
				if (not this->is_drawn) {
					add_draw(*this);
					cout << "Объект успешно добавлен в очередь на отрисовку, вы увидите его, когда завершите работу";
					this->is_drawn = true;
				}
				else {
					cout << "Объект уже в очереди на отрисовку";
				}
			}
			break;
			case 8:
			{
				if (this->is_drawn) {
					roll_back_draw();
					this->is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else cout << "Вы еще не нарисовали объект";
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
			case 55: item = 7; break;
			case 56: item = 8; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}