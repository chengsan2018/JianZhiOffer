/************************************************************************/
/* �����������ж�һ�������Ƿ���ĳ�����������ĺ����������
   ע�⣺����������(Binary search tree)�Ķ���
*/
/************************************************************************/

#ifndef _CBINARYSEARCHTREE_H
#define _CBINARYSEARCHTREE_H

#include <iostream>
using namespace std;

bool IsPostOrderOfBST(int* inputOrder, int istart, int iend)
{
	if (!inputOrder)
	{
		return false;
	}

	if (istart >= iend)
	{
		return true;
	}

	int root = inputOrder[iend];

	int rightSubTree_start = istart;
	while (rightSubTree_start < iend && inputOrder[rightSubTree_start] < root)
	{
		rightSubTree_start++;
	}
	
	for (int i = rightSubTree_start; i <= iend - 1; i++) //��������������нڵ��Ƿ���ڸ��ڵ�
	{
		if (inputOrder[i] <= root)
		{
			return false;
		}
	}

	if (!IsPostOrderOfBST(inputOrder, istart, rightSubTree_start - 1))
		return false;
	if (!IsPostOrderOfBST(inputOrder, rightSubTree_start, iend - 1))
		return false;
	return true;
}



void test()
{
	int a[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << IsPostOrderOfBST((int*)a, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;

	int b[] = {7, 4, 6, 5};
	cout << IsPostOrderOfBST((int*)b, 0, sizeof(b) / sizeof(b[0]) - 1) << endl;

}



#endif
