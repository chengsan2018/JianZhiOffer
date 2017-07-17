#ifndef _CREPEATINGCHAR_H
#define _CREPEATINGCHAR_H

#include <iostream>

using namespace std;

char FindFirstNotRepeating(char * str)
{
	if (str == NULL)
		return '\0';
	size_t nbyte = sizeof(char);
	int tablesize = 0x1 << (8 * nbyte);
	unsigned int* hashTable = new unsigned int[tablesize];
	for (int i = 0; i < tablesize; ++i)
	{
		hashTable[i] = 0;
	}

	




}


#endif
