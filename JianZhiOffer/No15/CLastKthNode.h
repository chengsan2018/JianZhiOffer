/************************************************************************/
/* 问题描述：输入一个链表，输出该链表中倒数第k个节点（从1开始计数）
*/
/************************************************************************/
#ifndef _CLASTKTHNODE_H
#define _CLASTKTHNODE_H
#include <iostream>

using namespace std;

struct ListNode
{
	int mValue;
	ListNode* mNext;


	ListNode(int v, ListNode* next) : mValue(v), mNext(next){}
};

/************************************************************************/
/* @常规解法
	包含两次遍历
*/
/************************************************************************/
void FindLastKthNode(ListNode *head, int k)
{
	if (head && k >= 1)
	{
		int NodeNum = 0;
		ListNode *currentNode = head;
		while (currentNode)
		{
			NodeNum++;
			currentNode = currentNode->mNext;
		}

		if (NodeNum < k)
		{
			cout << "输入索引超出范围！" << endl;
			return;
		}
		else
		{
			int theId = NodeNum - k + 1;
			ListNode *theNode = head;
			while (theId > 1)
			{
				theNode = theNode->mNext;
				theId--;
			}
			cout << theNode->mValue << endl;
			return;
		}
	}
	else
	{
		cout << "输入参数有误！" << endl;
		return;
	}
}

/************************************************************************/
/* @新解法
	采用双指针
	只需要一次遍历
*/
/************************************************************************/
void newFindLastKthNode(ListNode * head, int k)
{
	if (head && k >= 1)
	{
		ListNode *pFirst = head;
		ListNode *pSecond = head;
		int gap = 0;
		while (pFirst->mNext && gap < k - 1)
		{
			pFirst = pFirst->mNext;
			gap++;
		}

		if (!pFirst->mNext && gap < k -1 )
		{
			cout << "输入索引超出界限！" << endl;
			return;
		}

		while (pFirst->mNext)
		{
			pFirst = pFirst->mNext;
			pSecond = pSecond->mNext;
		}
		cout << pSecond->mValue << endl;
	}
	else
	{
		cout << "输入参数有误！" << endl;
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

	newFindLastKthNode(node1, 3);
	newFindLastKthNode(node1, 1);
	newFindLastKthNode(node1, 6);
}

#endif
