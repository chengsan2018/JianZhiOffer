/************************************************************************/
/* 问题描述：输入两棵二叉树A和B，判断B是不是A的子结构。
*/
/************************************************************************/


#ifndef _CJUDGESUBTREE_H
#define _CJUDGESUBTREE_H

#include <iostream>

using namespace std;

/************************************************************************/
/* 二叉树结点
*/
/************************************************************************/
struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight; 

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};

bool CIsTheSameTree(CBinaryTreeNode* mRoot1, CBinaryTreeNode* mRoot2);

/************************************************************************/
/* 函数功能：判断树A是否包含形如树B的子树
   输入： mOriginalTree - 树A的根结点
		 mSubTree - 树B的根结点
   输出： 判断结果
*/
/************************************************************************/
bool CHasSubTree(CBinaryTreeNode* mOriginalTree, CBinaryTreeNode* mSubTree)
{
	bool HasSubTree = false;
	if (mOriginalTree != NULL && mSubTree != NULL)
	{
		if (mOriginalTree->mValue == mSubTree->mValue)
		{
			HasSubTree = CIsTheSameTree(mOriginalTree, mSubTree);
		}
		if (!HasSubTree)
		{
			HasSubTree = CHasSubTree(mOriginalTree->mLeft, mSubTree);
		}
		if (!HasSubTree)
		{
			HasSubTree = CHasSubTree(mOriginalTree->mRight, mSubTree);
		}
	}
	return HasSubTree;
}

/************************************************************************/
/* 函数功能：判断树2是否与 “以树1的根结点的某个子树” 完全一致
   输入： mRoot1 - 树1的根结点
         mRoot2 - 树2的根结点
   输出： 判断结果
*/
/************************************************************************/
bool CIsTheSameTree(CBinaryTreeNode* mRoot1, CBinaryTreeNode* mRoot2)
{
	if ( mRoot1 == NULL && mRoot2 == NULL)
	{
		return true;
	}
	else if ( mRoot1 == NULL)
	{
		return false;
	}
	else if (mRoot2 == NULL)
	{
		return true;
	}
	else
	{
		if (mRoot1->mValue != mRoot2->mValue)
		{
			return false;
		}
		else
		{
			bool temp = CIsTheSameTree(mRoot1->mLeft, mRoot2->mLeft);
			if (!temp)
			{
				return false;
			}
			else
			{
				bool temp1 = CIsTheSameTree(mRoot1->mRight, mRoot2->mRight);
				if (!temp1)
				{
					return false;
				}
			}
		}
		return true;
	}
}

void test()
{
	CBinaryTreeNode node1(4, NULL, NULL);
	CBinaryTreeNode node2(7, NULL, NULL);
	CBinaryTreeNode node3(2, &node1, &node2);
	CBinaryTreeNode node4(9, NULL, NULL);
	CBinaryTreeNode node5(8, &node4, &node3);
	CBinaryTreeNode node6(7, NULL, NULL);
	CBinaryTreeNode node7(8, &node5, &node6);

	CBinaryTreeNode node8(9, NULL, NULL);
	CBinaryTreeNode node9(2, NULL, NULL);
	CBinaryTreeNode node10(8, &node8, &node9);

	cout << CHasSubTree(&node7, &node10) << endl;
}

#endif
