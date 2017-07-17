/************************************************************************/
/* 问题描述：输入一个整数数组，实现一个函数使得数组的前半部分为奇数，后半部分为偶数

   联想：根据某种条件，将数组分块这类问题都可以这样解答
*/
/************************************************************************/
#ifndef _CREORDERODDEVEN_H
#define _CREORDERODDEVEN_H

void swapInt(int &a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool isEven(int& a)
{
	if ( (a & 0x1) == 1)
		return true;
	else
		return false;
}

void ReorderOddEven(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int low = 0;
	int high = n - 1;

	while ( low < high)
	{
		while (low < high && isEven(a[low]))
		{
			low++;
		}
		//swapInt(a[low], a[high]);

		while (low < high && !isEven(a[high]))
		{
			high--;
		}
		swapInt(a[low], a[high]);
	}
}

void test()
{
	int a[] = { 102, 1, 2, 3, 22, 4, 5, 6, 7 };
	ReorderOddEven(a, sizeof(a) / sizeof(a[0]));
}

#endif
