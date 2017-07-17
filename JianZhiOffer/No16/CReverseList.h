/************************************************************************/
/* 问题描述：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头结点。
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
/* @反转函数
   @输入：原链表的头节点
   @输出：反转链表的头节点
   定义两个节点指针：一个是当前节点指针，二个是在原始链表的中，当前节点指针的前驱指针。
   不断迭代更新这两个指针
*/
/************************************************************************/
ListNode* ReverseList(ListNode *pHead)
{
	ListNode* lastNode = NULL;      //前驱节点
	ListNode* currentNode = pHead;  //当前节点
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
