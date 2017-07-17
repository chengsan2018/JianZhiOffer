#ifndef _CPRINTPROBABILITY_H
#define _CPRINTPROBABILITY_H

#include <iostream>

using namespace std;

int g_maxValue = 6;

void PrintProbability(int number)
{
	if (number < 1)
		return;
	
	int* pProb[2]; //指针数组
	pProb[0] = new int[g_maxValue * number + 1];
	pProb[1] = new int[g_maxValue * number + 1];

	//初始化
	for (int i = 0; i < g_maxValue * number + 1; ++ i)
	{
		pProb[0][i] = 0;
		pProb[1][i] = 0;
	}

	int IndexOfProbArray = 0;
	for (int i = 1; i <= g_maxValue; ++i)
	{
		pProb[IndexOfProbArray][i] = 1;
	}

	for (int k = 2; k <= number; ++k)
	{
		
		for (int i = 0; i < k; ++ i)
		{
			pProb[1 - IndexOfProbArray][i] = 0;
		}

		for (int i = k; i <= g_maxValue* k; ++i)
		{
			pProb[1 - IndexOfProbArray][i] = 0;
			
			for (int j = i - 1; j >= i - g_maxValue && j >= k - 1;--j)
			{
				pProb[1 - IndexOfProbArray][i] += pProb[IndexOfProbArray][j];
			}
		}
		IndexOfProbArray = 1 - IndexOfProbArray;
	}

	for (int i = number; i < g_maxValue * number + 1; ++i)
	{
		cout << i << ' ';
	}
	cout << endl;

	int total = pow((double)g_maxValue, number);

	for (int i = number; i < g_maxValue * number + 1; ++i)
	{
		cout << pProb[IndexOfProbArray][i] << '/' << total << ' ';
	}
	cout << endl;
}

#define N 50
int num1[N], num2[N];
void Show(int n){
	memset(num1, 0, N*sizeof(int));
	memset(num2, 0, N*sizeof(int));
	for (int i = 1; i <= 6; i++) num1[i] = 1;
	int i, j, k;
	for (i = 2; i <= n; i++){
		for (j = i; j <= 6 * i; j++){
			k = j - 6;
			if (k < i)   k = i - 1;
			for (; k < j; k++)  num2[j] += num1[k];
		}
		memset(num1, 0, N*sizeof(int));
		for (int m = i; m <= 6 * i; m++) num1[m] = num2[m];
		memset(num2, 0, N*sizeof(int));
	}
	cout << "The probability distribution of " << n << " dices" << endl << endl;
	cout << "Point: \t" << "Probability:" << endl;;
	for (int kkk = n; kkk <= 6 * n; kkk++){
		cout << kkk << ": \t" << num1[kkk] << "/" << (pow(6.0, n)) << endl;
	}
}

void test()
{
	PrintProbability(4);
	cout << endl;
	Show(4);
}

#endif
