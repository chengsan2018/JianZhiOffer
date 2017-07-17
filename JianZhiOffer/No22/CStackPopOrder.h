#ifndef _CSTACKPOPORDER_H
#define _CSTACKPOPORDER_H

#include <stack>
#include <iostream>
using namespace std;
bool isPopOrder(int *pPush, int *pPop, int n)
{
	bool result = false;
	int popIndex = 0;
	int pushIndex = 0;
	stack<int> stackData;
	while (pPush!= NULL && pPop != NULL && popIndex < n)
	{
		if (!stackData.empty() && stackData.top() == pPop[popIndex])
		{
			popIndex++;
			stackData.pop();
		}
		else
		{
			while (pPush[pushIndex] != pPop[popIndex] && pushIndex < n)
			{
				stackData.push(pPush[pushIndex]);
				pushIndex++;
			}
			if (pushIndex == n)
			{
				break;
			}
			popIndex++;
			pushIndex++;
		}
	}
	if (popIndex == n)
	{
		result = true;
	}
	return result;
}



void test()
{
	int n = 5;
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 4, 5, 3, 2, 1 };
	cout << isPopOrder((int*)a, (int *)b, n) << endl;
	
}


#endif
