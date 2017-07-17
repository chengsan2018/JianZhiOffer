/************************************************************************/
/* ��������������һ���������飬ʵ��һ������ʹ�������ǰ�벿��Ϊ��������벿��Ϊż��

   ���룺����ĳ��������������ֿ��������ⶼ�����������
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
