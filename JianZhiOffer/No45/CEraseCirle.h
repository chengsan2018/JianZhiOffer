#ifndef _CERASECIRLE_H
#define _CERASECIRLE_H

#include <list>

using namespace std;

int lastRemain(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	list<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}

	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; ++i) //�ҵ�current
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}

		//�ҵ�current����һ��
		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}
		
		//ɾ��current
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}

#endif
