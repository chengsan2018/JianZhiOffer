/************************************************************************/
/* 请实现如下函数，复制一个复杂链表。在复杂链表中，每个结点除了有一个next指针指向下一个节
   点外，还有一个sibling指向链表中的任意结点或者NULL。
*/
/************************************************************************/
#ifndef _CCOMPLEXLIST_H
#define _CCOMPLEXLIST_H

#include <iostream>

struct CComplexListNode
{
	int mValue;
	CComplexListNode* mNext;
	CComplexListNode* mSibling;

	CComplexListNode(int ivalue, CComplexListNode* inext, CComplexListNode* isibling) :mValue(ivalue), mNext(inext), mSibling(isibling) {}
};

CComplexListNode* CLone(CComplexListNode* pHead)
{
	if (!pHead)
	{
		return NULL;
	}
	else
	{	
		// 第一次遍历
		CComplexListNode* newListHead = new CComplexListNode(pHead->mValue, NULL, NULL);
		CComplexListNode* newListCurrent = newListHead;
		CComplexListNode* soureListNext = pHead->mNext;
		while (soureListNext)
		{
			newListCurrent->mNext = new CComplexListNode(soureListNext->mValue, NULL, NULL);
			newListCurrent = newListCurrent->mNext;
			soureListNext = soureListNext->mNext;
		}

		// 第二次遍历
		CComplexListNode* newListCurrent = newListHead;
		CComplexListNode* soureListCurrent = pHead;
		while (soureListCurrent)
		{
			if (!soureListCurrent->mSibling)
			{
				newListCurrent->mSibling = NULL;
			}
			else
			{
				CComplexListNode* currentSibling = pHead;
				newListCurrent->mSibling = newListHead;
				while (currentSibling != soureListCurrent->mSibling)
				{
					newListCurrent->mSibling = newListCurrent->mSibling->mNext;
					currentSibling = currentSibling->mNext;
				}
			}
			soureListCurrent = soureListCurrent->mNext;
			newListCurrent = newListCurrent->mNext;
		}
	}
}

#endif
