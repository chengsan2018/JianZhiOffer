#ifndef _COPERATESTRING_H
#define _COPERATESTRING_H



#include <cstring>
#include <iostream>

using namespace std;


void ReverseString(char* str, int low, int high)
{
	if (str && low < high)
	{
		char temp;
		while (low < high)
		{
			temp = str[low];
			str[low] = str[high];
			str[high] = temp;

			++low;
			--high;
		}
	}
}

void ReverseSentence(char *pData)
{
	if (pData)
	{
		int len = strlen(pData);

		//翻转整个句子
		ReverseString(pData, 0, len - 1);
		
		int istart = 0;
		int iend = 0;
		while (istart < len && iend < len)
		{
			if (pData[iend] == ' ')
			{
				ReverseString(pData, istart, iend - 1);
				istart = iend + 1;
				iend = istart;
			}
			else
			{
				++iend;
			}
		}
	}
}

void LeftRotateString(char *pStr, int n)
{
	if (pStr)
	{
		int nStr = static_cast<int>(strlen(pStr));

		ReverseString(pStr, 0, nStr - 1);

		ReverseString(pStr, 0, nStr - n - 1);

		ReverseString(pStr, nStr - n, nStr - 1);
	}
}

void LeftRotateString2(char *pStr, int n)
{

	if (pStr)
	{
		int nStr = static_cast<int>(strlen(pStr));

		if (n >= nStr)
		{
			n = n % nStr;
		}

		int low = 0, high = nStr - 1;
		int middle = n;
		int i = middle;
		while (true)
		{
			swap(pStr[low], pStr[i]);
			++low;
			++i;

			if (low == middle)
			{
				if (i == nStr)
				{
					return;
				}
				middle = i;
			}
			else if (i == nStr)
			{
				i = middle;
			}
		}
	}
}


void test()
{
	char word[] = "I am a student.";
	ReverseSentence(word);
	cout << word << endl;

	char str[] = "abcdefg";
	LeftRotateString2(str, 10);
	cout << str << endl;
}

#endif
