#include "line.h"

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
line::line(const line& l) {
	_p1 = l.get_first();
	_p2 = l.get_second();
	is_drawn = l.is_drawn;
}
line::~line() {
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
	point p1(0, 0), p2(b,-a);
	return myvector(p1, p2);
}

void line::coef(double& a, double& b, double& c)
{
	a = _p2.get_y() - _p1.get_y();
	b = _p1.get_x() - _p2.get_x();
	c = _p1.get_y() * (_p2.get_x() - _p1.get_x()) + _p1.get_x() * (_p1.get_y() - _p2.get_y());
}

line line::parallel(const point& p)const
{
	double a, b, c;
	a = _a;
	b = _b;
	c = -(_a * p.get_x() + _b * p.get_y());
	return line(a, b, c);
}

size_t line::is_increasing() const {
	long long int res = (_p1.get_x() - _p2.get_x()) * (_p1.get_y() - _p2.get_y());
	//Если x и y изменяются обратнопропорционально, то убывает
	if (res < 0) return 0;
	//Если прямопропорционально, то возрастает
	if (res > 0) return 1;
	//Если x или y не меняется
	if (_p1.get_x()==_p2.get_x()) return 2;
	if (_p1.get_y() == _p2.get_y()) return 3;
}

//Фрэнд функции
istream& operator>>(istream& in, line& l) {
	cout << "Введите координаты первой точки для задания прямой:" << endl;
	cin >> l._p1;
	cout << "Введите координаты второй точки:" << endl;
	cin >> l._p2;
	return in;
}
figure& line:: operator=(line& l) {
	_p1 = l._p1;
	_p2 = l._p2;
	return *this;
}


void line::draw() {
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	long long int a, b;
	a = constants::width;
	b = constants::height;
	if (this->is_increasing()==0)b *= -1;
	if (this->is_increasing() == 2) a = 0;
	if (this->is_increasing() == 3) b = 0;
	glVertex2i(_p1.get_x()-2*a, _p1.get_y()-2*b);
	glVertex2i(_p2.get_x()+2*a, _p2.get_y()+2*b);
	glEnd();
}