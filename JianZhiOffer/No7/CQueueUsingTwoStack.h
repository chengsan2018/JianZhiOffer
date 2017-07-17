/************************************************************************/
/* ������ջʵ��һ�����У��ֱ�����ڶ���β������ڵ���ڶ���ͷ��ɾ���ڵ�Ĺ���                                                                  */
/************************************************************************/
#ifndef _CQUEUEUSINGTWOSTACK_H
#define _CQUEUEUSINGTWOSTACK_H
#include<iostream>
#include <stack>
#include <exception>

using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T & node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
CQueue<T>::~CQueue()
{

}

template <typename T>
CQueue<T>::CQueue()
{

}

//ɾ��ͷ��
template <typename T>
T CQueue<T>::deleteHead()
{
	while (stack1.size() > 0)
	{
		T& data = stack1.top();
		stack1.pop();
		stack2.push(data);
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();
	return head;
}
//����β��
template <typename T>
void CQueue<T>::appendTail(const T & node)
{
	stack1.push(node);
}

void test()
{
	CQueue<int> a;
	a.appendTail(1);
	a.appendTail(2);

	cout << a.deleteHead() << endl;
	cout << a.deleteHead() << endl;
	cout << a.deleteHead() << endl;
}

#endif
