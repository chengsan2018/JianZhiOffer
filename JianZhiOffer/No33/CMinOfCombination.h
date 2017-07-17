/************************************************************************/
/* 问题描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接处的所有数字
	       中最小的一个。
*/
/************************************************************************/


#ifndef _CMINOFCOMBINATION_H
#define _CMINOFCOMBINATION_H

#include <iostream>

using namespace std;

int GetKthDigitOfInteger(int number, int k);
int GetBitsOfInteger(int number);
int CompareNumbers(int a, int b);

void PrintMinOfCombination(int*numbers, int length)
{
	if (numbers && length > 0)
	{
		int minIndex;
		for (int i = 0; i < length; ++i)
		{
			minIndex = i;
			for (int j = i + 1; j < length; ++j)
			{
				if (CompareNumbers(numbers[minIndex], numbers[j]) == 1)
				{
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				int temp = numbers[minIndex];
				numbers[minIndex] = numbers[i];
				numbers[i] = temp;
			}
			cout << numbers[i];
		}
		cout << endl;
	}


}

int CompareNumbers(int a, int b)
{
	int na = GetBitsOfInteger(a);
	int nb = GetBitsOfInteger(b);

	int a_digit, b_digit;
	int ia = na, ib = nb;
	while (ia >= 0 && ib >= 0)
	{
		if (ia >= 1 && ib >= 1)
		{
			a_digit = GetKthDigitOfInteger(a, ia);
			b_digit = GetKthDigitOfInteger(b, ib);
			if (a_digit > b_digit)
			{
				return 1;
			}
			if (a_digit < b_digit)
			{
				return -1;
			}
		}
		else if (ia == 0 || ib == 0)
		{
			if (ia == 0)
			{
				a_digit = GetKthDigitOfInteger(a, na);
				b_digit = GetKthDigitOfInteger(b, ib);


				while (a_digit == b_digit && ib > 1)
				{
					ib--;
					b_digit = GetKthDigitOfInteger(b, ib);
				}
				if (ib == 0)
				{
					return 0;
				}

				if (a_digit > b_digit)
				{
					return 1;
				}
				if (a_digit < b_digit)
				{
					return -1;
				}

			}
			if (ib == 0)
			{
				a_digit = GetKthDigitOfInteger(a, ia);
				b_digit = GetKthDigitOfInteger(b, nb);

				while (a_digit == b_digit && ia > 1)
				{
					ia--;
					a_digit = GetKthDigitOfInteger(a, ia);
				}

				if (ia == 0)
				{
					return 0;
				}

				if (a_digit > b_digit)
				{
					return 1;
				}
				if (a_digit < b_digit)
				{
					return -1;
				}
			}
			
		}
		ia--, ib--;
	}
	return 0;
}


int GetBitsOfInteger(int number)
{
	int icount = 1;
	int ifx = number / 10;
	while (ifx)
	{
		ifx = ifx / 10;
		icount++;
	}
	return icount;
}

int GetKthDigitOfInteger(int number, int k)
{
	while (k > 1)
	{
		number = number / 10;
		k--;
	}
	return number % 10;
}

void test()
{
	int a[] = { 3, 32, 321 };
	PrintMinOfCombination(&a[0], sizeof(a) / sizeof(a[0]));
}


#endif
