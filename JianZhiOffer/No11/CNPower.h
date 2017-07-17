#ifndef _CNPOWER_H
#define _CNPOWER_H

#include <iostream>
#include <exception>
using namespace std;

double power(double base, int exponent)
{
	// 当base等于0时， exponent必须大于0
	if (base == 0 && exponent <= 0 )
	{
		throw "Input parameters has error !";
		return 0.0l;
	}

	int absExponent = exponent >= 0 ? exponent : -exponent;
	double result = 1.0l;
	while (absExponent > 0)
	{
		result *= base;
		absExponent--;
	}
	return exponent >= 0 ? result : 1.0l / result;
}

//改进： 当base为很小的数时，比如0.00000001，结果是一个很大的数，这种情况应当避免
bool equal_double(double a1, double a2);

double power1(double base, int exponent)
{
	// 当base等于0时， exponent必须大于0
	if (equal_double(base, 0.0l) && exponent <= 0)
	{
		throw "Input parameters has error !";
		return 0.0l;
	}

	int absExponent = exponent >= 0 ? exponent : -exponent;
	double result = 1.0l;
	while (absExponent > 0)
	{
		result *= base;
		absExponent--;
	}
	return exponent >= 0 ? result : 1.0l / result;
}

bool equal_double(double a1, double a2)
{
	if (a1 - a2 < 0.000001 && a1 - a2 > -0.000001)
	{
		return true;
	}
	else
		return false;
}

void test()
{
	cout << power(3, 3) << endl;
	cout << power(3, -3) << endl;
	cout << power(3, 0) << endl;
	cout << power(0, 0) << endl;
}
#endif
