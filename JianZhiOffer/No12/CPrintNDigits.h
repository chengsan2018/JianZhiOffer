/************************************************************************/
/* ������������������n�� ��˳���ӡ����1������nλʮ������

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
/* ������
*/
/************************************************************************/
void PrintNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1]; //����n+1λ�ַ��ռ�
	memset(number, '0', n);
	number[n] = '\0';

	while (!InCrement(number))  //���û�����
	{
		PrintNumber(number);    //��ӡ����
	}
	cout << endl;
	delete[] number;
}

/************************************************************************/
/* ����+1 
*/
/************************************************************************/
bool InCrement(char * number)
{
	bool IsOverFlow = false;   // �Ƿ����
	int len = strlen(number);  // ���ֳ���
	int takeOver = 1;          // �Ƿ������Ե�λ�Ľ�λ, ��ʼΪ1

	for (int i = len - 1; i >= 0; i--) //�����λ��ʼ
	{
		if (takeOver == 0)     
		{// ���û�����Ե�λ�Ľ�λ
			break;
		}
		else
		{// ��������Ե�λ�Ľ�λ
			if (number[i] == '9') //��ǰλ������Ϊ'9'
			{
				if (i == 0) //�����ǰλΪ���λ
				{
					IsOverFlow = true;  //�����������ֹѭ��
					break;
				}
				else        //�����ǰλ��Ϊ���λ
				{
					number[i] = '0'; //��ǰλ��Ϊ'0' takeOver ����Ϊ1
				}
			}
			else //��ǰλ�����ֲ�Ϊ'9'
			{
				number[i] += 1;
				takeOver = 0; //takeOver ��Ϊ0 ��������λ
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
