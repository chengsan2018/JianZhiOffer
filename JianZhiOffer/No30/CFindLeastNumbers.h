/************************************************************************/
/* ��������������n���������ҳ�������С��k������
*/
/************************************************************************/


#ifndef _CFINDLEASTNUMBERS_H
#define _CFINDLEASTNUMBERS_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <class T>
int Partition(T *a, int low, int high)
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


void GetLeastNumbers(vector<int> &input, vector<int> &output, int k)
{
	if (!input.empty() && k > 0)
	{
		int inputLength = input.size();

		int iPartition = Partition(&input[0], 0, inputLength - 1);

		while (iPartition != k-1)
		{
			if (iPartition > k - 1)
			{
				iPartition = Partition(&input[0], 0, iPartition - 1);
			}

			if (iPartition < k - 1)
			{
				iPartition = Partition(&input[0], iPartition + 1, inputLength - 1);
			}
		}

		output.clear();
		for (int i = 0; i <= k - 1; ++i)
		{
			output.push_back(input[i]);
		}
	}
}


//���ô������ʵ��
template<class T>
struct greater
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return lhs > rhs;
	}
};

typedef multiset<int, greater<int> >  intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void GetLeastNumbers2(const vector<int> &data, intSet &leastNumbers, int k)
{
	if (data.size() >= k && k >= 1)
	{
		for (vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
		{
			if (leastNumbers.size() < k)
			{
				leastNumbers.insert(*it);
			}
			else
			{
				setIterator iterGreatest = leastNumbers.begin();
				if (*it < * iterGreatest)
				{
					leastNumbers.erase(iterGreatest);
					leastNumbers.insert(*it);
				}
			}
		}
	}
}

void test()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> input(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> output;
	intSet result;

// 	GetLeastNumbers(input, output, 4);
// 	for (vector<int>::iterator it = output.begin(); it != output.end(); ++it)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;

	GetLeastNumbers2(input, result, 4);
	for (setIterator it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
#endif
