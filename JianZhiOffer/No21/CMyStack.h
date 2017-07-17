/************************************************************************/
/* 问题描述：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中
		   ，调用min,push及pop的时间复杂度都是o(1)
*/
/************************************************************************/

#ifndef _CMYSTACK_H
#define _CMYSTACK_H

#include <stack>
#include <iostream>
using namespace std;

template<class T>
class CStackWithMin
{
public:
	CStackWithMin();
	~CStackWithMin();
	
	void push(const T & newData);
	void pop();
	T min() const;


private:
	stack<T> mData;
	stack<T> mTheMinData;
};

template<class T>
CStackWithMin<T>::CStackWithMin()
{

}

template<class T>
CStackWithMin<T>::~CStackWithMin()
{
}


template<class T>
void CStackWithMin<T>::push(const T & newData)
{
	mData.push(newData);
	if (mTheMinData.empty())
	{
		mTheMinData.push(newData);
	}
	else
	{
		mTheMinData.push(newData < mTheMinData.top() ? newData : mTheMinData.top());
	}
}


template<class T>
void CStackWithMin<T>::pop()
{
	assert(mData.size() > 0 && mTheMinData.size() > 0);
	mData.pop();
	mTheMinData.pop();
}


template<class T>
T CStackWithMin<T>::min() const
{
	assert(mData.size() > 0 && mTheMinData.size() > 0);
	return mTheMinData.top();
}



void test()
{
	CStackWithMin<int> a;
	a.push(3);
	cout << a.min() << endl;
	a.push(4);
	a.push(2);
	a.push(1);
	a.pop();
	a.pop();
	a.push(0);
}

#endif
