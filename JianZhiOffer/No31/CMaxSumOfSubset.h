#ifndef _CMAXSUMOFSUBSET_H
#define _CMAXSUMOFSUBSET_H

#include <iostream>

using namespace std;

bool g_InvalidInput = false;

int FindMaxSumOfSubset(int* pData,int nLength)
{
	if (!pData || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength;++i)
	{
		if (nCurSum <= 0)
		{
			nCurSum = pData[i];
		}
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}

	return nGreatestSum;
}


void test()
{
	//int a[] = { 50, -67, 3, -1, 2};
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << FindMaxSumOfSubset((int*)a, sizeof(a) / sizeof(a[0])) << endl;

}
#endif
