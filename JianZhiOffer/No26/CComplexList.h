/************************************************************************/
/* ��ʵ�����º���������һ�����������ڸ��������У�ÿ����������һ��nextָ��ָ����һ����
   ���⣬����һ��siblingָ�������е����������NULL��
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
		// ��һ�α���
		CComplexListNode* newListHead = new CComplexListNode(pHead->mValue, NULL, NULL);
		CComplexListNode* newListCurrent = newListHead;
		CComplexListNode* soureListNext = pHead->mNext;
		while (soureListNext)
		{
			newListCurrent->mNext = new CComplexListNode(soureListNext->mValue, NULL, NULL);
			newListCurrent = newListCurrent->mNext;
			soureListNext = soureListNext->mNext;
		}

		// �ڶ��α���
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
