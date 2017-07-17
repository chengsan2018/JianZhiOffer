
#ifndef _CCOUNTNUMBER_H
#define _CCOUNTNUMBER_H

#include <iostream>

using namespace std;

int FindTheFirst(int* data, int low, int high, int k)
{
	int mid;
	int firstOfK = -1;
	int istart = low;
	int iend = high;
	while (istart <= iend)
	{
		mid = (istart + iend) / 2;
		if (data[mid] < k)
		{
			istart = mid + 1;
		}
		if (data[mid] > k)
		{
			iend = mid - 1;
		}
		if (data[mid] == k)
		{
			if (mid == low || data[mid - 1] != k )
			{
				firstOfK = mid;
				break;
			}
			else
			{
				iend = mid - 1;
			}
		}
	}
	return firstOfK;
}

int FindTheLast(int* data, int low, int high, int k)
{
	int mid;
	int firstOfK = -1;
	int istart = low;
	int iend = high;
	while (istart <= iend)
	{
		mid = (istart + iend) / 2;
		if (data[mid] < k)
		{
			istart = mid + 1;
		}
		if (data[mid] > k)
		{
			iend = mid - 1;
		}
		if (data[mid] == k)
		{
			if (mid == high || data[mid + 1] != k)
			{
				firstOfK = mid;
				break;
			}
			else
			{
				istart = mid + 1;
			}
		}
	}
	return firstOfK;
}

int CountNumber(int *data, int length, int k)
{
	int result = 0;
	if (data && length > 0)
	{
		int firstID = FindTheFirst(data, 0, length - 1, k);
		int lastID = FindTheLast(data, 0, length - 1, k);
		if (firstID > -1 && lastID > -1)
		{
			result = lastID - firstID + 1;
		}
	}
	return result;

}

void test()
{
	int a[] = { 3, 3, 3, 3, 4, 5 };
	cout << CountNumber(a, sizeof(a) / sizeof(a[0]), 3) << endl;

}


#endif
