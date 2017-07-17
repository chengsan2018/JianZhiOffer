/************************************************************************/
/* ��������������һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ��㡣
*/
/************************************************************************/
#ifndef _REVERSELIST_H
#define _REVERSELIST_H

#include <iostream>
using namespace std;

struct ListNode
{
	int mValue;
	ListNode *mNext;

	ListNode(int v, ListNode * next) : mValue(v), mNext(next){}

	void printList() {
		ListNode *currentNode = this;
		while (currentNode)
		{
			cout << currentNode->mValue;
			if (currentNode->mNext)
			{
				cout << " - ";
			}
			currentNode = currentNode->mNext;
		}
		cout << endl;
	}
};

/************************************************************************/
/* @��ת����
   @���룺ԭ�����ͷ�ڵ�
   @�������ת�����ͷ�ڵ�
   ���������ڵ�ָ�룺һ���ǵ�ǰ�ڵ�ָ�룬��������ԭʼ������У���ǰ�ڵ�ָ���ǰ��ָ�롣
   ���ϵ�������������ָ��
*/
/************************************************************************/
ListNode* ReverseList(ListNode *pHead)
{
	ListNode* lastNode = NULL;      //ǰ���ڵ�
	ListNode* currentNode = pHead;  //��ǰ�ڵ�
	ListNode* temp;
	while (currentNode != NULL)
	{
		temp = currentNode->mNext;
		currentNode->mNext = lastNode;
		lastNode = currentNode;
		currentNode = temp;
	}
	return lastNode;
}

void test()
{
	ListNode *node1 = new ListNode(1, NULL);
	ListNode *node2 = new ListNode(2, NULL);
	ListNode *node3 = new ListNode(3, NULL);
	ListNode *node4 = new ListNode(4, NULL);
	ListNode *node5 = new ListNode(5, NULL);

	node1->mNext = node2;
	node2->mNext = node3;
	node3->mNext = node4;
	node4->mNext = node5;
	node1->printList();
	ListNode *ReverseHead = ReverseList(node1);
	ReverseHead->printList();
}

void test2()
{
	ListNode *node1 = NULL;
	node1->printList();
	ListNode *ReverseHead = ReverseList(node1);
	ReverseHead->printList();
}

#endif
