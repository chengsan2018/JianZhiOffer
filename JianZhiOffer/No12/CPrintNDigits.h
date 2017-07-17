/************************************************************************/
/* 问题描述：输入数字n， 按顺序打印出从1到最大的n位十进制数

*/
/************************************************************************/

#ifndef _CPRINTNDIGITS_H
#define _CPRINTNDIGITS_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool InCrement(char * number);
void PrintNumber(char *number);

/************************************************************************/
/* 主函数
*/
/************************************************************************/
void PrintNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1]; //申请n+1位字符空间
	memset(number, '0', n);
	number[n] = '\0';

	while (!InCrement(number))  //如果没有溢出
	{
		PrintNumber(number);    //打印数字
	}
	cout << endl;
	delete[] number;
}

/************************************************************************/
/* 数字+1 
*/
/************************************************************************/
bool InCrement(char * number)
{
	bool IsOverFlow = false;   // 是否溢出
	int len = strlen(number);  // 数字长度
	int takeOver = 1;          // 是否有来自低位的进位, 初始为1

	for (int i = len - 1; i >= 0; i--) //从最低位开始
	{
		if (takeOver == 0)     
		{// 如果没有来自低位的进位
			break;
		}
		else
		{// 如果有来自低位的进位
			if (number[i] == '9') //当前位的数字为'9'
			{
				if (i == 0) //如果当前位为最高位
				{
					IsOverFlow = true;  //则发生溢出，终止循环
					break;
				}
				else        //如果当前位不为最高位
				{
					number[i] = '0'; //当前位设为'0' takeOver 保持为1
				}
			}
			else //当前位的数字不为'9'
			{
				number[i] += 1;
				takeOver = 0; //takeOver 置为0 不发生进位
			}
		}
	}
	return IsOverFlow;
}

void PrintNumber(char *number)
{
	if (number)
	{
		bool isBegin = false;
		for (int i = 0; number[i] != '\0'; i++)
		{
			if (number[i] != '0')
			{
				isBegin = true;
			}
			if (isBegin)
				cout << number[i];
		}
			
		cout << ' ';
	}
}

void swapChar(char * a, char * b);

int sum = 0;

void PrintPermutation(char a[], int n , int len)
{
	if (n == 1)
	{
		sum++;
		cout <<sum <<". " ;
		for (int i = 0; i < len;i++)
		{
			cout << a[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < n;i++)
		{
			swapChar(&a[i], &a[n - 1]);
			PrintPermutation(a, n - 1 , len);
			swapChar(&a[i],&a[n - 1]);
		}
	}
}

void swapChar(char * a, char * b)
{
	if (b != a)
	{
		char  temp = *a;
		*a = *b;
		*b = temp;
	}
}

int n = 0;

void swap(char *a, char *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

void perm(char list[], int k, int m)
{
	int i;
	if (k > m)
	{
		for (i = 0; i <= m; i++)
		{
			cout << "&" << list[i];

		}
		cout << "\n";
		n++;
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			perm(list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}


void test()
{
	char a[] = "abc";
	//PrintPermutation(a, sizeof(a) / sizeof(a[0]), sizeof(a) / sizeof(a[0]));
	perm(a, 0, 3);
// 	string str = "abc";
// 	while (next_permutation(str.begin(), str.end()))
// 	{
// 		cout << str << endl;
// 	}
}
#endif
