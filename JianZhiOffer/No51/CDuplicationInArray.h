#ifndef _DUPLICATIONINARRAY_H
#define _DUPLICATIONINARRAY_H

#include <iostream>

using namespace std;

bool duplication(int* numbers, int len, int* duplication)
{
	if (numbers == NULL || len < 0)
	{
		return false;
	}

	for (int i = 0; i < len; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > len -1)
		{
			return false;
		}
	}

	for (int i = 0; i < len; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			//swap numbers[i] and numbers[numbers[i]]
			int temp = numbers[i]; 
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}


#endif
