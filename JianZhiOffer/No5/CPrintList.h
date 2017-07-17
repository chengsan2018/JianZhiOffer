/************************************************************************/
/* 问题描述：输入一个链表的第一个节点，从尾到头反过来打印出每个节点的值                                                                     */
/************************************************************************/
#ifndef _CPRINTLIST_H
#define _CPRINTLIST_H

#include <stack>

template <class T>
struct ListNode
{
	T mValue;  //值
	ListNode<T> *mNextNode; // 下一个节点地址
	//构造函数
	ListNode(T v, ListNode<T>* n):mValue(v), mNextNode(n){}
};


//用栈实现，从尾到头打印链表
template<class T>
void PrintListReverse(ListNode<T> *headNode)
{
	stack<ListNode<T> *> allNodes;
	ListNode<T> * theNode = headNode;
	while (theNode)
	{
		allNodes.push(theNode);
		theNode = theNode->mNextNode;
	}

	while (!allNodes.empty())
	{
		cout << allNodes.top()->mValue << endl;
		allNodes.pop();
	}
}

//测试函数
void test()
{
	ListNode<int> node1(1, NULL),
		node2(2, NULL),
		node3(3, NULL);
	node1.mNextNode = &node2;
	node2.mNextNode = &node3;

	PrintListReverse(&node1);
}
#endif