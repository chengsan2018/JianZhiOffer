/************************************************************************/
/* ��������������һ����������������һ����ת�������ת�������СԪ�� 

   ������������Ĳ��ң��ȽϺõ���������*���ַ�����*
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
	if (high - low == 1 ) //�������ֻ��������Ԫ��
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


//�ϸ������� û�п��ǵ���������û����ת�������ͬʱ���ںܳ������飬�ݹ麯��ռ�õ��ڴ�ջ�ܴ���˻ᵼ�µ���ջ���
//�Ľ���
template <class T>
T MinRotateArray1(T* a, int low, int high)
{
	int minIndex = 0;
	while (a[low] >= a[high])  // �����������Ϊ��ת���ĵ������飬�����ѭ�����������������û����ת�ĵ������飬��ֱ��������Ԫ��a[0]
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

//�ϸ�������û�п��ǵ��м�Ԫ������βԪ�ض���ȵ����{1�� 0 �� 1�� 1�� 1}
//�ٸĽ�
template <class T>
T MinRotateArray2(T* a, int low, int high)
{
	int minIndex = 0;
	while (a[low] >= a[high])  // �����������Ϊ��ת���ĵ������飬�����ѭ�����������������û����ת�ĵ������飬��ֱ��������Ԫ��a[0]
	{
		if (high - low == 1)
		{
			minIndex = high;
			break;
		}
		else
		{
			int mid = (low + high) / 2;

			if (a[mid] == a[low] && a[mid] == a[high]) //���low �� high mid��Ԫ�ض���ȣ���˳�����
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
			else //���򣬶��ֲ���
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