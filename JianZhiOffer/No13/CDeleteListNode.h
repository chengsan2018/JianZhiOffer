/************************************************************************/
/* 问题描述：给定单项链表的头指针和和一个节点指针，定义一个函数在O(1)时间删除该节点。
   链表节点与函数的定义如下：

   struct ListNode
   {
   int mValue;
   ListNode * mNext;
   };

   void DeleteNode(ListNode ** PListHead, ListNode* pToDeleted);
*/
/************************************************************************/

#ifndef _CDELETELISTNODE_H
#define _CDELETELISTNODE_H

using namespace std;

struct ListNode
{
	int mValue;
	ListNode * mNext;

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

void DeleteNode(ListNode ** PListHead, ListNode* pToDeleted)
{
	if (!PListHead || !pToDeleted)
	{
		return;
	}

	if (pToDeleted->mNext != NULL) //如果待删除节点不是尾节点
	{
		ListNode* pNext = pToDeleted->mNext;
		pToDeleted->mValue = pNext->mValue;
		pToDeleted->mNext = pNext->mNext;
		delete pNext;
		pNext = NULL;
	}
	else if (*PListHead == pToDeleted) //如果待删除节点即是尾节点又是头节点
	{
		delete pToDeleted;
		pToDeleted = NULL;
		*PListHead = NULL;
	}
	else // 否则，从头开始遍历
	{
		ListNode *currentNode = *PListHead;
		while ( currentNode->mNext != pToDeleted)
		{
			currentNode = currentNode->mNext;
		}

		currentNode->mNext = NULL;
		delete pToDeleted;
		pToDeleted = NULL;
	}
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
	DeleteNode(&node1, node3);
	node1->printList();
}
#endif
