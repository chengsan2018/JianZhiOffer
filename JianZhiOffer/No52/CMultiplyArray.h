#ifndef _CMULTIPLYARRAY_H
#define _CMULTIPLYARRAY_H

#include <iostream>
#include <vector>

using namespace std;

void multiply(const vector<double>& array1, vector<double>& array2)
{
	int len1 = array1.size();
	int len2 = array2.size();

	if (len1 == len2 && len2 > 1)
	{
		array2[0] = 1;
		for (int i = 1; i < len1; ++i)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}

		double temp = 1;
		for (int i = len1 - 2; i >= 0; --i)
		{
			temp *= array1[i+1];
			array2[i] *= temp;
		}
	}
}

void test()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<double> va(a, a + 6);
	vector<double> sa(6);

	multiply(va, sa);
}

#endif
