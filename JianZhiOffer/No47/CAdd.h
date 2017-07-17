#ifndef _CADD_H
#define _CADD_H


#include <iostream>

using namespace std;

int Add(int a, int b)
{
	int sum;
	do
	{
		sum = a ^ b;
		int carry = (a & b) << 1;

		a = sum;
		b = carry;
	} while (b != 0);		
	return sum;
}

void test()
{
	cout << Add(10, 20) << endl;
}


#endif
