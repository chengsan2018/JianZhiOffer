#ifndef _CFINDMORETHANHALF_H
#define _CFINDMORETHANHALF_H

// ������39�������г��ִ�������һ�������
// ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
// ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
// ������5�Σ��������鳤�ȵ�һ�룬������2��

#include <cstdio>
#include <iostream>

using namespace std;

bool g_bInputInvalid = false;

template <class T>
int Partition(T *a, int length, int low, int high)
{
	int key = a[low];  //ѡ���һ��Ϊ�м�Ĺؼ���
	while (low < high)
	{
		while (a[high] >= key && low < high)
		{
			high--;
		}
		//swap(a[high], a[low]);  //������ؼ���λ��high        
		a[low] = a[high];

		while (a[low] <= key && low < high)
		{
			low++;
		}
		a[high] = a[low];
		//swap(a[low], a[high]);  //������ؼ���λ��low
	}
	a[low] = key;
	return low;  //�����м�ؼ��ֵ�λ��ID
}

bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == nullptr && length <= 0)
		g_bInputInvalid = true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

// ====================����1====================
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}

// ====================����2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
			times++;
		else
			times--;
	}

	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}

void test()
{
	//int a[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int a[] = { 1, 2, 3, 2};
	cout << MoreThanHalfNum_Solution2((int*)a, sizeof(a) / sizeof(a[0])) <<endl;


}
#endif
