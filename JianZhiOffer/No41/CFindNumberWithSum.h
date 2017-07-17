#ifndef _CFINDNUMBERWITHSUM_H
#define _CFINDNUMBERWITHSUM_H

#include <iostream>

using namespace std;

bool FindNumberWithSum(int* data, int n, int sum, int* num1, int *num2)
{
	bool isFound = false;
	if (data && n >= 2)
	{
		int low = 0;
		int high = n - 1;
		int theResult = data[low] + data[high];
		while (theResult != sum && low < high)
		{
			if (theResult > sum)
			{
				--high;
			}

			if (theResult < sum)
			{
				++low;
			}

			theResult = data[low] + data[high];
		}

		if (theResult == sum && low != high)
		{
			*num1 = data[low];
			*num2 = data[high];
			isFound = true;
		}
	}
	return isFound;
}

void PrintArray(int low, int high);

void FindSequentNumberWithSum(int sum)
{
	if (sum > 0)
	{
		int low = 1;
		int high = 2;
		int theResult = low + high;
		while (low < high)
		{
			if (theResult < sum)
			{
				++high;
				theResult += high;
			}

			if (theResult > sum)
			{
				theResult -= low;
				++low;			
			}		

			if (theResult == sum)
			{
				PrintArray(low, high);
				++high;
				theResult += high;
			}
		}
	}
}

void PrintArray(int low, int high)
{
	if (low >= 0 && low < high)
	{
		while(low <= high)
		{
			cout << low++ << " ";
		}
		cout << endl;
	}
}

void test()
{
	int a[] = { 1, 2, 4, 6, 7, 11, 15 };
	int n1, n2;
	cout << FindNumberWithSum(a, sizeof(a) / sizeof(a[0]), 13, &n1, &n2) << ": ";
	cout << n1 << "  " << n2 << endl;
	FindSequentNumberWithSum(75);
}

#endif
