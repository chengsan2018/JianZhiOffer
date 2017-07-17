/************************************************************************/
/* 问题描述：输入一个矩阵，按照从外到里顺时针依次打印出每一个数字
*/
/************************************************************************/

#ifndef _CPRINTMATRIX_H
#define _CPRINTMATRIX_H

#include <iostream>

using namespace std;

void PrintMatrixInCircle(int matrix[][4], int startRow, int startColumn, int endRow, int endColumn);

void PrintMatrixClockwisely(int matrix[][4], int rows, int columns)
{

	int startColumn = 0, startRow = 0;
	int endColumn = columns - 1, endRow = rows - 1;

	while (startRow <= endRow || startColumn <= endColumn)
	{
		PrintMatrixInCircle(matrix, startRow, startColumn, endRow, endColumn);
		startRow++;
		startColumn++;
		endColumn--;
		endRow--;
	}
	cout << endl;
}

void PrintMatrixInCircle(int matrix[][4], int startRow, int startColumn, int endRow, int endColumn)
{
	if (startRow == endRow && startColumn == endColumn)
	{
		cout << matrix[startRow][startColumn]<< ' ';
	}
	else if (startRow == endRow)
	{
		for (int i = startColumn; i <= endColumn; i++)
		{
			cout << matrix[startRow][i] << ' ';
		}
	}
	else if (startColumn == endColumn)
	{
		for (int i = startRow; i <= endRow; i++)
		{
			cout << matrix[i][startColumn] << ' ';
		}
	}
	else
	{
		for (int i = startColumn; i <= endColumn; i++)
		{
			cout << matrix[startRow][i] << ' ';
		}

		for (int i = startRow+1; i <= endRow; i++)
		{
			cout << matrix[i][endColumn] << ' ';
		}

		for (int i = endColumn-1; i >= startColumn; i--)
		{
			cout << matrix[endRow][i] << ' ';
		}

		for (int i = endRow - 1; i >= startRow+1; i--)
		{
			cout << matrix[i][startColumn] << ' ';
		}
	}
}


void test()
{
	int a[4][4] = { { 1, 2, 3, 4 }, 
					{ 5, 6, 7, 8 }, 
					{ 9, 10, 11, 12}, 
					{13, 14, 15, 16} };

	PrintMatrixClockwisely(a, 4, 4);
}

#endif
