#ifndef _CJUDGECARDS_H
#define _CJUDGECARDS_H

#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinuous(int* numbers, int len)
{
	if (numbers)
	{
		qsort(numbers, len, sizeof(int), compare);

		int numberOfZero = 0;
		int numberOfGap = 0;

		for (int i = 0; i < len && numbers[i] == 0; ++i)
		{
			++numberOfZero;
		}

		int small = numberOfZero;
		int big = small + 1;
		while (big < len)
		{
			if (numbers[small] == numbers[big])
			{
				return false;
			}

			numberOfGap += numbers[big] - numbers[small] - 1;
			small = big;
			++big;
		}
		return (numberOfGap > numberOfZero) ? false : true;
	}
}

void test()
{
	int cards[] = { 1, 3, 0, 4, 6, 0};
	IsContinuous(cards, sizeof(cards) / sizeof(cards[0]));
	cout << IsContinuous(cards, sizeof(cards) / sizeof(cards[0])) << endl;
}



#endif
