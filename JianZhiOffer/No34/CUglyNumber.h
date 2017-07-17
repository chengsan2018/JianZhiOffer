/************************************************************************/
/* 问题描述：丑数：只包含因子2、3、5的正整数。
		   求从小到大的顺序的第N个丑数。
*/
/************************************************************************/

#ifndef _CUGLYNUMBER_H
#define _CUGLYNUMBER_H

#include <iostream>

using namespace std;

template <class T>
T MinOfThree(T n1, T n2, T n3);

int GetUglyNumber(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int *allUgly = new int[index];
	allUgly[0] = 1;
	int uglyindex = 1;

	int *Multiply2 = allUgly;
	int *Multiply3 = allUgly;
	int *Multiply5 = allUgly;

	while (uglyindex < index)
	{
		int nextUgly = MinOfThree(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
		allUgly[uglyindex] = nextUgly;

		if (nextUgly == *Multiply2 * 2)
		{
			++Multiply2;
		}
		if (nextUgly == *Multiply3 * 3)
		{
			++Multiply3;
		}
		if (nextUgly == *Multiply5 * 5)
		{
			++Multiply5;
		}
		++uglyindex;

	}

	int result = allUgly[index - 1];
	delete[]allUgly;
	return result;

}


template <class T>
T MinOfThree(T n1, T n2, T n3)
{
	T result = (n1 < n2) ? n1 : n2;
	result = (result < n3) ? result : n3;
	return result;
}

void test()
{
	cout << GetUglyNumber(15) << endl;
}


#endif




