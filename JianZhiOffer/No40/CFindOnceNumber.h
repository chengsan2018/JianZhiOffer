/************************************************************************/
/* 一个整型数组除了两个数字之外，其他的数字都出现了两次，找出这两个只出现一次的数字。
   要求时间复杂度O(n)， 空间复杂度O(1)。
*/
/************************************************************************/


#ifndef _CFINDONCENUMBER_H
#define _CFINDONCENUMBER_H

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindOnceNumber(int *data, int n, int *num1, int* num2)
{
	if (data && n >= 2)
	{
		int resultExclusiveOR = 0;
		for (int i = 0; i < n; ++i)
		{
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
		*num1 = *num2 = 0;
		for (int j = 0; j < n; ++j)
		{
			if (IsBit1(data[j], indexOf1))
			{
				*num1 ^= data[j];
			}
			else
			{
				*num2 ^= data[j];
			}
		}
	}
}

// 找到数字从低位起第一个为1的位数
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 8*sizeof(int)) )
	{
		num >>= 1;
		++indexBit;
	}
	return indexBit;
}

// 判断数字的第几位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num >>= indexBit;
	return (num & 1);
}

#endif
