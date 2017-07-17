#ifndef _CFINDMORETHANHALF_H
#define _CFINDMORETHANHALF_H

// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include <cstdio>
#include <iostream>

using namespace std;

bool g_bInputInvalid = false;

template <class T>
int Partition(T *a, int length, int low, int high)
{
	int key = a[low];  //选择第一个为中间的关键字
	while (low < high)
	{
		while (a[high] >= key && low < high)
		{
			high--;
		}
		//swap(a[high], a[low]);  //交换后关键字位于high        
		a[low] = a[high];

		while (a[low] <= key && low < high)
		{
			low++;
		}
		a[high] = a[low];
		//swap(a[low], a[high]);  //交换后关键字位于low
	}
	a[low] = key;
	return low;  //返回中间关键字的位置ID
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

// ====================方法1====================
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

// ====================方法2====================
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
