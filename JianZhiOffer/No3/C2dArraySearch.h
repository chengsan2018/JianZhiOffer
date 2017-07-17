/************************************************************************/
/*  一个有序的二维数组，每一行和每一列都是递增排序 
	例如：
	 1 2 8 9 
	 2 4 9 12
	 4 7 10 13
	 6 8 11 15
	完成函数，输入二维数组，和一个数，判断该数组中是否有该数
/************************************************************************/

#ifndef _C2DARRAYSEARCH_H
#define _C2DARRAYSEARCH_H

/************************************************************************/
/* 有序二维数组中的查找                                                                  
/************************************************************************/
template< class T >
bool Ordered2dArraySearch(T ** &a, int srow, int scolumn, int erow, int ecolumn, T elem)
{
	//先在首列和首行查找
	int i, j;
	for (i = srow; i <= erow; i++)
	{
		if (elem == *(*(a+i)+scolumn))
		{
			return true;
		}
		else if (elem < *(*(a + i) + scolumn))
		{
			break;
		}
	}

	for (j = scolumn; j <= ecolumn; j++)
	{
		if (elem == *(*(a+srow)+j))
		{
			return true;
		}
		else if (elem < *(*(a + srow) + j))
		{
			break;
		}
	}

	if (i - srow <= 1 || j - scolumn <= 1) // i-srow == 0 表示待查找元素小于首元素
										   // i -srow == 1 表示待查找元素大于首元素小于第二个元素
		return false;
	else
	{
		srow++;
		scolumn++;
	}
	erow = i - 1;
	ecolumn = j - 1;
	//缩小范围查找
	return Ordered2dArraySearch(a, srow, scolumn, erow, ecolumn, elem);
}

//示例
void test()
{
	int a[16] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int **b;
	int irow = 4, icolumn = 4;
	alloc2dArray(b, irow, icolumn);
	set2dArrayValue(b, irow, icolumn, a, 16);
	cout << Ordered2dArraySearch<int>(b, 0, 0, 3, 3, 16) << endl;
	free2dArray(b, irow, icolumn);
}

//为二维数组分配空间
template <class T>
void alloc2dArray(T ** &a, int irow, int icolumn)  //注意传递的是二维指针的引用
{
	a = new T*[irow];
	for (int i = 0; i < irow; i++)
	{
		*(a + i) = new T[icolumn];
	}
}
//释放二维空间
template <class T>
void free2dArray(T ** &a, int irow, int icolumn)
{

	for (int i = 0; i < irow; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = NULL;
}
//为二维数组赋值
template <class T>
void set2dArrayValue(T **a, int irow, int icolumn, T* src, int len)
{
	if (irow * icolumn != len)
	{
		cout << "无法赋值" << endl;
		return;
	}
	else
	{
		int k = 0;
		for (int i = 0; i < irow; i++)
		{
			for (int j = 0; j < icolumn; j++)
			{
				a[i][j] = src[k++];
			}
		}
	}
}
#endif