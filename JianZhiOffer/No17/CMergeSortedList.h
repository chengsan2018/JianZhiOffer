#ifndef _CMERGESORTEDLIST_H
#define _CMERGESORTEDLIST_H


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
/* @合并两个递增链表
   @输入：两个的链表的头节点指针
   @输出：合并后链表的头节点指针
*/
/************************************************************************/
ListNode* MergeSortedList(ListNode* pListHead1, ListNode* pListHead2)
{
	ListNode* pMergedListHead = NULL;      //合并后链表的头节点
	//如果输入链表其中有一个有空
	if (pListHead1 == NULL)
	{
		return pListHead2;
	}
	if (pListHead2 == NULL)
	{
		return pListHead1;
	}
	//如果输入链表都不为空
	ListNode* currentNode1 = pListHead1;
	ListNode* currentNode2 = pListHead2;
	if (currentNode1->mValue > currentNode2->mValue)
	{
		pMergedListHead = currentNode2;
		currentNode2 = currentNode2->mNext;
	}
	else
	{
		pMergedListHead = currentNode1;
		currentNode1 = currentNode1->mNext;
	}
	ListNode* currentNode = pMergedListHead;

	while (currentNode1 != NULL || currentNode2 != NULL)
	{
		if (currentNode1 == NULL)
		{
			currentNode->mNext = currentNode2;
			break;
		}
		else if ( currentNode2 == NULL)
		{
			currentNode->mNext = currentNode1;
			break;
		}
		else
		{
			if (currentNode1->mValue > currentNode2->mValue)
			{
				currentNode->mNext = currentNode2;
				currentNode2 = currentNode2->mNext;
			}
			else
			{
				currentNode->mNext = currentNode1;
				currentNode1 = currentNode1->mNext;
			}
			currentNode = currentNode->mNext;
		}
	}
	return pMergedListHead;
}

void test()
{
	ListNode *node1 = new ListNode(1, NULL);
	ListNode *node2 = new ListNode(3, NULL);
	ListNode *node3 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(7, NULL);
	node1->mNext = node2;
	node2->mNext = node3;
	node3->mNext = node4;

	ListNode *node5 = new ListNode(2, NULL);
	ListNode *node6 = new ListNode(4, NULL);
	ListNode *node7 = new ListNode(6, NULL);
	ListNode *node8 = new ListNode(8, NULL);
	node5->mNext = node6;
	node6->mNext = node7;
	node7->mNext = node8;

	ListNode *newList = MergeSortedList(node1, node5);
	newList->printList();
}
#endif
