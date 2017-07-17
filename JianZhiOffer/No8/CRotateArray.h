/************************************************************************/
/* 问题描述：输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素 

   对于排序数组的查找，比较好的做法就是*二分法查找*
*/
/************************************************************************/

#ifndef _CROTATEARRAY_H
#define _CROTATEARRAY_H
#include <iostream>

using namespace std;
  
//beta0 
template <class T>
T MinRotateArray(T* a, int low, int high)
{
	if (high - low == 1 ) //如果数组只包含两个元素
	{
		return a[high];
	}
	else
	{
		int mid = (low + high) / 2;
		if (a[mid] >= a[low])
		{
			return MinRotateArray(a, mid, high);
		}

		else //if (a[mid] < a[high])
		{
			return MinRotateArray(a, low, mid);
		}
	}
}


//上个函数， 没有考虑到递增数组没有旋转的情况，同时对于很长的数组，递归函数占用的内存栈很大！因此会导致调用栈溢出
//改进后
template <class T>
T MinRotateArray1(T* a, int low, int high)
{
	int minIndex = 0;
	while (a[low] >= a[high])  // 如果输入数组为旋转过的递增数组，则进入循环；如果输入数组是没有旋转的递增数组，则直接输入首元素a[0]
	{
		if (high - low == 1)
		{
			minIndex = high;
			break;
		}
		else
		{
			int mid = (low + high) / 2;
			if (a[mid] >= a[low])
			{
				low = mid;
			}
			else if (a[mid] <= a[high])
			{
				high = mid;
			}
		}
	}
	return a[minIndex];
}

//上个函数，没有考虑到中间元素与首尾元素都相等的情况{1， 0 ， 1， 1， 1}
//再改进
template <class T>
T MinRotateArray2(T* a, int low, int high)
{
	int minIndex = 0;
	while (a[low] >= a[high])  // 如果输入数组为旋转过的递增数组，则进入循环；如果输入数组是没有旋转的递增数组，则直接输入首元素a[0]
	{
		if (high - low == 1)
		{
			minIndex = high;
			break;
		}
		else
		{
			int mid = (low + high) / 2;

			if (a[mid] == a[low] && a[mid] == a[high]) //如果low 和 high mid的元素都相等，则按顺序查找
			{
				T min = a[low];
				for (int i = low; i <= high;i++)
				{
					if (a[i] < min)
					{
						minIndex = i;
					}
				}
				break;
			}
			else //否则，二分查找
			{
				if (a[mid] >= a[low])
				{
					low = mid;
				}
				else if (a[mid] <= a[high])
				{
					high = mid;
				}
			}
		}
	}
	return a[minIndex];
}


void test()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 41, 52, 120, 140, 211, 1000, 5, 15, 20, 34 , 35, 39};
	int c[] = { 1, 0, 1, 1, 1 };
	cout << "min of array a : " << MinRotateArray(a, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;  //???
	cout << "min of array b : " << MinRotateArray(b, 0, sizeof(b) / sizeof(b[0]) - 1) << endl;
	cout << endl;

	cout << "min of array a : " << MinRotateArray1(a, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
	cout << "min of array b : " << MinRotateArray1(b, 0, sizeof(b) / sizeof(b[0]) - 1) << endl;
	cout << "min of array c : " << MinRotateArray1(c, 0, sizeof(c) / sizeof(c[0]) - 1) << endl;
	cout << endl;

	cout << "min of array c : " << MinRotateArray2(c, 0, sizeof(c) / sizeof(c[0]) - 1) << endl;
}

#endif