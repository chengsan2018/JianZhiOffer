/************************************************************************/
/* 问题描述：输入一个二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新
           的结点，只能调整树种结点指针的指向。
*/
/************************************************************************/

#ifndef _CBST2DOUBLYLIST_H
#define _CBST2DOUBLYLIST_H

#include <iostream>

using namespace std;

struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};

void InOrder(CBinaryTreeNode* theNode, CBinaryTreeNode *preNode, CBinaryTreeNode* postNode);
CBinaryTreeNode* FindPreNode(CBinaryTreeNode* theNode);
CBinaryTreeNode* FindPostNode(CBinaryTreeNode* theNode);


CBinaryTreeNode* Convert(CBinaryTreeNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot, NULL, NULL);
		CBinaryTreeNode* headNode = pRoot;
		while (headNode->mLeft)
		{
			headNode = headNode->mLeft;
		}
		return headNode;
	}
	else
		return NULL;
}

void InOrder(CBinaryTreeNode* theNode, CBinaryTreeNode *preNode, CBinaryTreeNode* postNode)
{
	if ( !theNode->mLeft && ! theNode->mRight )  // 如果是叶节点
	{
		theNode->mLeft = preNode;
		theNode->mRight = postNode;
		return;
	}

	CBinaryTreeNode* PreNodeFromSubTree = NULL; 
	CBinaryTreeNode* PostNodeFromSubTree = NULL;

	if (!theNode->mLeft)  //如果左子树为空
	{
		theNode->mLeft = NULL;
	}
	else
	{
		PreNodeFromSubTree = FindPreNode(theNode); //在左子树中，找到当前节点的前驱
		InOrder(theNode->mLeft, preNode, theNode); //遍历左子树，左子树的后继一定是theNode
		theNode->mLeft = PreNodeFromSubTree;      
	}

	if (!theNode->mRight)
	{
		theNode->mRight = NULL;
	}
	else
	{ 
		PostNodeFromSubTree = FindPostNode(theNode); //在右子树中，找到当前节点的后继
		InOrder(theNode->mRight, theNode, postNode); //遍历右子树，右子树的前驱一定是theNode
		theNode->mRight = PostNodeFromSubTree;
	}

}

CBinaryTreeNode* FindPreNode(CBinaryTreeNode* theNode)
{
	CBinaryTreeNode* preNode = NULL;
	if (theNode->mLeft)
	{
		preNode = theNode->mLeft;
		while (preNode->mRight)
		{
			preNode = preNode->mRight;
		}
	}
	return preNode;
}

CBinaryTreeNode* FindPostNode(CBinaryTreeNode* theNode)
{
	CBinaryTreeNode* postNode = NULL;
	if (theNode->mRight)
	{
		postNode = theNode->mRight;
		while (postNode->mLeft)
		{
			postNode = postNode->mLeft;
		}
	}
	return postNode;
}

void test()
{
	CBinaryTreeNode node1(4, NULL, NULL);
	CBinaryTreeNode node2(8, NULL, NULL);
	CBinaryTreeNode node3(6, NULL, &node2);
	CBinaryTreeNode node4(12, NULL, NULL);
	CBinaryTreeNode node5(16, NULL, NULL);
	CBinaryTreeNode node6(14, &node4, &node5);
	CBinaryTreeNode node7(10, &node3, &node6);

	CBinaryTreeNode* pHead = Convert(&node7);

}

#endif
