#pragma once
#ifndef MATH_CONST_H
#define MATH_CONST_H
namespace constants 
{
	//Число пи
	const double pi = 3.141592653589793;
	//Погрешность
	const double eps = 0.0000001;
	//Общепринятое число округления. Округляем до rd-ых
	const double rd = 10000000;
	//Параметры окна с изображением
	const size_t width = 1024;
	const size_t height = 700;
}
#endif // !CONSTANTS_H