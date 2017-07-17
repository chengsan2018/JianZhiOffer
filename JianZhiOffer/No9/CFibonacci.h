/************************************************************************/
/* 问题描述：实现斐波拉切数列
*/
/************************************************************************/

#ifndef _CFIBONACCI_H
#define _CFIBONACCI_H

#include <iostream>

using namespace std;

int Fibonacci0(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci0(n - 2) + Fibonacci0(n - 1);
	}
}

int Fibonacci(int n)
{
	int a0 = 0, a1 = 1;
	if (n <= 0)
	{
		return a0;
	}
	else if (n == 1)
	{
		return a1;
	}
	else
	{
		int result;
		for (int i = 2; i <= n;i++)
		{
			result = a0 + a1;
			a0 = a1;
			a1 = result;
		}
		return result;
	}
}

void test()
{
	cout << Fibonacci(10) << endl;
	cout << Fibonacci0(10) << endl;c
}
#endif
