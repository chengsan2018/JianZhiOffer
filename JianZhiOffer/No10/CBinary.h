/************************************************************************/
/* ��������������һ������������ö���������1�ĸ���
*/
/************************************************************************/
#ifndef _CBINARY_H
#define _CBINARY_H

#include <iostream>

using namespace std;

int NumOfOne(int num)
{
	int count = 0;
	while (num != 0)
	{
		if (num & 1) //& ��λ��
		{
			count++;
		}
		num = num >> 1;

// 		if (num % 2 == -1 || num % 2 == 1)
// 		{
// 
// 
// 			count++;
// 		}
// 		num = num / 2;
	}
	return count;
}

int NumOfOne1(int num)
{
	int count = 0;
	int flag = 1;
	while (flag)
	{
		if (flag & num) //& ��λ��
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

void test()
{
	cout << NumOfOne1(9) << endl;
	cout << NumOfOne1(-9) << endl;
	//cout << -9 % 2<< endl;
}
#endif
