#ifndef _CDEPTHOFTREE_H
#define _CDEPTHOFTREE_H

#include <iostream>

using namespace std;

struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode *mLeft;
	CBinaryTreeNode *mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) : mValue(v), mLeft(l), mRight(r) {}
};

int GetDepthOfBinaryTree(CBinaryTreeNode * pRoot)
{
	int theDepth = 0;
	if (pRoot)
	{
		int theLeftDepth = 0;
		int theRightDepth = 0;
		if (pRoot->mLeft)
		{
			theLeftDepth = GetDepthOfBinaryTree(pRoot->mLeft);
		}
		if (pRoot->mRight)
		{
			theRightDepth = GetDepthOfBinaryTree(pRoot->mRight);
		}
		theDepth = ++theLeftDepth > ++theRightDepth ? theLeftDepth : theRightDepth;
	}
	return theDepth;
}

bool IsBalancedBinaryTree(CBinaryTreeNode* pRoot)
{
	if (pRoot)
	{
		int theLeftDepth = 0;
		int theRightDepth = 0;
		if (pRoot->mLeft)
		{
			theLeftDepth = GetDepthOfBinaryTree(pRoot->mLeft);
		}
		if (pRoot->mRight)
		{
			theRightDepth = GetDepthOfBinaryTree(pRoot->mRight);
		}

		int diff = theLeftDepth - theRightDepth;
		if (diff > 1 || diff < -1)
		{
			return false;
		}
		return IsBalancedBinaryTree(pRoot->mLeft) && IsBalancedBinaryTree(pRoot->mRight);
	}
	return true;
}

bool IsBalancedBinaryTree2(CBinaryTreeNode * pRoot, int* theDepth)
{
	//ºóÐò±éÀú
	if (pRoot)
	{
		bool theResult = true;
		int* theLeftDepth = new int (0);
		int* theRightDepth = new int(0);
		if (pRoot->mLeft)
		{
			theResult = IsBalancedBinaryTree2(pRoot->mLeft, theLeftDepth);
		}

		if (theResult && pRoot->mRight)
		{
			theResult = IsBalancedBinaryTree2(pRoot->mRight, theRightDepth);
		}

		int diff = theRightDepth - theLeftDepth;
		if (theResult && diff <= 1 && diff >= -1)
		{
			*theDepth = *theRightDepth > *theRightDepth ? *theRightDepth + 1 : *theLeftDepth + 1;
		}

		delete theLeftDepth;
		delete theRightDepth;
		return theResult;
	}
	else
	{
		return true;
	}
}

void test()
{
	CBinaryTreeNode node1(7, NULL, NULL);
	CBinaryTreeNode node2(5, &node1, NULL);
	CBinaryTreeNode node3(4, NULL, NULL);
	CBinaryTreeNode node4(2, &node3, &node2);
	CBinaryTreeNode node5(6, NULL, NULL);
	CBinaryTreeNode node6(3, NULL, &node5);
	CBinaryTreeNode node7(1, &node4, &node6);

	cout << GetDepthOfBinaryTree(&node7) << endl;
	cout << IsBalancedBinaryTree(&node7) << endl;
	int de;
	cout << IsBalancedBinaryTree2(&node7, &de) << endl;
}

#endif
