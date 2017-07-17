/************************************************************************/
/* ��������������һ������ĵ�һ���ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ                                                                     */
/************************************************************************/
#ifndef _CPRINTLIST_H
#define _CPRINTLIST_H

#include <stack>

template <class T>
struct ListNode
{
	T mValue;  //ֵ
	ListNode<T> *mNextNode; // ��һ���ڵ��ַ
	//���캯��
	ListNode(T v, ListNode<T>* n):mValue(v), mNextNode(n){}
};


//��ջʵ�֣���β��ͷ��ӡ����
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

//���Ժ���
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