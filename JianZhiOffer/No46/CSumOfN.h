/************************************************************************/
/* 问题描述：求1 + 2 + …… + n
*/
/************************************************************************/

#ifndef _CSUMOFN_H
#define _CSUMOFN_H

#include <iostream>

using namespace std;

class Temp
{
public:
	Temp(){ ++N; Sum += N; }

	static void Reset() { N = 0; Sum = 0; }
	static unsigned int GetSum() { return Sum; }

private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int sum_solution1(unsigned int n)
{
	Temp::Reset();

	Temp* a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

class A;
A* Array[2];

class A
{
public:
	virtual unsigned int sum(unsigned int n)
	{
		return 0;
	}
};

class B : public A
{
public:
	virtual unsigned int sum(unsigned int n)
	{
		return Array[!!n]->sum(n - 1) + n;
	}
};

unsigned int sum_solution2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	
	int value = Array[1]->sum(n);
	return value;
}

typedef unsigned int(*fun)(unsigned int); //函数指针

unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}

unsigned int sum_solution3(unsigned int n)
{
	static fun f[2] = { Solution3_Teminator, sum_solution3 }; //定义函数指针数组
	return f[!!n](n - 1) + n;
}

void test()
{
	cout << sum_solution1(100) << endl;
	cout << sum_solution2(100) << endl;
	cout << sum_solution3(100) << endl;
}



#endif
