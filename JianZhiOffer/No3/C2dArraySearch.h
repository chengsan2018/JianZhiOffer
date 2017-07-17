/************************************************************************/
/*  һ������Ķ�ά���飬ÿһ�к�ÿһ�ж��ǵ������� 
	���磺
	 1 2 8 9 
	 2 4 9 12
	 4 7 10 13
	 6 8 11 15
	��ɺ����������ά���飬��һ�������жϸ��������Ƿ��и���
/************************************************************************/

#ifndef _C2DARRAYSEARCH_H
#define _C2DARRAYSEARCH_H

/************************************************************************/
/* �����ά�����еĲ���                                                                  
/************************************************************************/
template< class T >
bool Ordered2dArraySearch(T ** &a, int srow, int scolumn, int erow, int ecolumn, T elem)
{
	//�������к����в���
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

	if (i - srow <= 1 || j - scolumn <= 1) // i-srow == 0 ��ʾ������Ԫ��С����Ԫ��
										   // i -srow == 1 ��ʾ������Ԫ�ش�����Ԫ��С�ڵڶ���Ԫ��
		return false;
	else
	{
		srow++;
		scolumn++;
	}
	erow = i - 1;
	ecolumn = j - 1;
	//��С��Χ����
	return Ordered2dArraySearch(a, srow, scolumn, erow, ecolumn, elem);
}

//ʾ��
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

//Ϊ��ά�������ռ�
template <class T>
void alloc2dArray(T ** &a, int irow, int icolumn)  //ע�⴫�ݵ��Ƕ�άָ�������
{
	a = new T*[irow];
	for (int i = 0; i < irow; i++)
	{
		*(a + i) = new T[icolumn];
	}
}
//�ͷŶ�ά�ռ�
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
//Ϊ��ά���鸳ֵ
template <class T>
void set2dArrayValue(T **a, int irow, int icolumn, T* src, int len)
{
	if (irow * icolumn != len)
	{
		cout << "�޷���ֵ" << endl;
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